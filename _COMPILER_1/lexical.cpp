#include "lexical.h"
#include <iostream>

using namespace std;


lexical::lexical(ifstream& in, ofstream& out)
{
	this->in = &in;
	this->out = &out;

	// вводные слова
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
	
}


bool lexical::getNextToken()
{
	lexem lex;

	getNextToken();

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
	else if (isdigit(cursor))
	{
		switch (isConstant())
		{
		case 1 /*CHAR*/:
			lex.lexemType = CHAR;
			break;
		case 2 /*INTEGER*/:
			lex.lexemType = INTEGER;
			break;
		case 3 /*UINTEGER*/:
			lex.lexemType = UINTEGER;
			break;
		case 4 /*FLOAT*/:
			lex.lexemType = FLOAT;
			break;
		case 5 /*DOUBLE*/:
			lex.lexemType = DOUBLE;
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


void lexical::addLexInfo(lexem& lex)
{
	lex.lex.clear();
	lex.line = line;
	for (int i = lex.pos; i < cursor; i++)
	{
		lex.lex += program[i];
	}
}