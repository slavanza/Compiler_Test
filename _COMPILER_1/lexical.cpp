#include "lexical.h"
#include <iostream>

using namespace std;


lexical::lexical(ifstream& in, ofstream& out)
{
	this->in = &in;
	this->out = &out;

	// ключевые слова
	for (auto k = begin(Keywords); k < end(Keywords); k++)
		keyWords.insert(*k);
	// типы
	for (auto k = begin(Types); k < end(Types); k++)
		keyWords.insert(*k);
	// операторы
	for (unsigned i = 0; i < Operators.size(); i++)
		opAndSep.insert(Operators[i]);
	// разделители
	for (unsigned i = 0; i < Separators.size(); i++)
		opAndSep.insert(Separators[i]);

	cursor = 0;
	line = 1;
	getline(in, program, '\0');
	current = program[cursor];
}


lexical::~lexical()
{
	if (!in->is_open())
		cerr << "Input stream is closed" << endl;
	if (!out->is_open())
		cerr << "Output stream is closed" << endl;
}


void lexical::analyze()
{
	while (getNextToken());
}


bool lexical::getNextToken()
{
	lexem lex;

	skipSpaceAndComment();

	lex.pos = cursor;
	if (cursor == '\0')
	{
		lex.lexemType = ENDOF;
		return false;
	}
	else if (isalpha(cursor) || cursor == '_')
	{
		isIdentifier();
		lex.lexemType = IDENTIFIER;
	}
	else if (isdigit(cursor) || current == '\'')
	{
		switch (isConstant())
		{
		case 1 /*CHAR*/:
			lex.lexemType = CHAR;
			break;
		case 2 /*INTEGER*/:
			lex.lexemType = INTEGER;
			break;
		case 3 /*FLOAT*/:
			lex.lexemType = FLOAT;
			break;
		default:
			lex.lexemType = ERROR;
		}
	}
	else if (opAndSep.count(current))
	{
		lex.lexemType = checkOperator();
		nextSymbol();
	}
	else
	{
		lex.lexemType = ERROR;
		lex.lex = current;
		lex.line = line;

		lexems.push_back(lex);

		return false;
	}

	addLexInfo(lex);

	if (lex.lexemType == IDENTIFIER)
	{
		if (keyWords.count(lex.lex))
			lex.lexemType = KEYWORD;
	}

	lexems.push_back(lex);
}


bool lexical::nextSymbol()
{
	if (current != '\0')
	{
		current = program[++cursor];
		return true;
	}
	return false;
}


void lexical::skipSpaceAndComment()
{
	while (current == ' ' || current == '\n' || current == '\t')
	{
		if (current == '\n')
			line++;
		nextSymbol();
	}

	if (current == '/' && program[cursor + 1] == '/')
	{
		while (current != '\n')
		{
			if (current == '\0')
				return;
			nextSymbol();
		}
		skipSpaceAndComment();
	}
	if (current == '/' && program[cursor + 1] == '*')
	{
		while (current != '*' && program[cursor + 1] != '/')
		{
			if (current == '\0')
				return;
			if (current == '\n')
				line++;
			nextSymbol();
		}
		skipSpaceAndComment();
	}
}


unsigned lexical::isConstant()
{
	if (current == '\'')
	{
		do
		{
			nextSymbol();
		} while (current != '\'' || program[cursor - 1] != '\\');
		return 1;
	}
	unsigned points = 0;
	while (isdigit(current) || current == '.')
	{
		if (current == '.')
			points++;
		nextSymbol();
	}
	if (!points)
		return 2;
	else if (points == 1)
		return 3;
	else
		return 4;
}


unsigned lexical::checkOperator()
{
	int value = -1;
	switch (current)
	{
	case '"':
		nextSymbol();
		while (current != '"')
		{
			if (!nextSymbol())
				throw exception("Зацикливание в поиске stringLiteral");
		}
		return STRLITERAL;
		break;
	case '+': 
		if (program[current + 1] == '=') 
			value = OPPLUSEQ; // += 
		else if (program[value + 1] == '+') 
			value = OPPLUSPLUS; // ++ 
		else
			return OPPLUS;
		break; 
	case '-': 
		if (program[current + 1] == '=') 
			value = OPMINEQ; // -= 
		else if (program[current + 1] == '-') 
			value = OPMINMIN; // -- 
		else 
			return OPMIN;
		break; 
	case '*': 
		if (program[current + 1] == '=')
			value = OPMULTIEQ; // *= 
		else 
			return OPMULTI; 
		break; 
	case '/': 
		if (program[current + 1] == '=') 
			value = OPMULTIEQ; // /= 
		else 
			return OPDIV; 
		break; 
	case '>':
		if (program[current + 1] == '=')
			value = OPMOREEQ; // >=
		else return OPMORE;
		break;
	case '<':
		if (program[current + 1] == '=') 
			value = OPLESSEQ; // <=
		else return OPLESS;
		break;
	case '!':
		if (program[current + 1] == '=')
			value = OPNOTEQ; // !=
		else 
			return OPNOT;
		break;
	case '=':
		if (program[current + 1] == '=') 
			value = OPCOMPRARE; // !=
		else
			return OPEQ;
		break;
	case '&': return AMP;
	case '.': return DOT;
	case ',': return COMMA;
	case ';': return DCOMMA;
	case '{': return LBR;
	case '}': return RBR;
	case '(': return LCBR;
	case ')': return RCBR;
	default: return ERROR;
	}
	if (value != -1)
		nextSymbol();

	return value;
}


void lexical::isIdentifier()
{
	while (isalnum(current) || current == '_')
		nextSymbol();
}


void lexical::addLexInfo(lexem& lex)
{
	lex.lex.clear();
	lex.line = line;
	for (int i = lex.pos; i < cursor; i++)
	{
		lex.lex += program[i];
	}
}