#pragma once

#include <string>
#include <vector>
#include <set>

#include "token.h"

using std::string;
using std::vector;
using std::set;

struct lexem
{
	unsigned lexemType;
	string lex;
	unsigned line;
	unsigned pos;
	lexem(unsigned lexemType, const char* lex, unsigned line, unsigned pos) { this->lexemType = lexemType; this->lex = lex; this->line = line; this->pos = pos; }
};


// возможно, в дальнейшем придётся отказаться от реализации некоторых типов, которые не потребуются для использования
vector<string> Types = { "i32", "u32", "bool", "char", "f32", "f64", "void" };


vector<string> Keywords = { "if", "else", "for", "while", "do", "return" };


// основные знаки и символы, применяемые в высказываниях
vector<string> Operators = { "+", "-", "*", "/", "&", "|", "<", ">", "=", "!" };


vector<string> Separators = { "{", "}", "(", ")","[", "]" };


// доступные для имён буквы нижнего регистра
string lower = "abcdefghijklmnopqrstuvwxyz";

// доступные для имён буквы верхнего регистра
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// доступные цифры
string numbers = "0123456789";


class lexical
{
	vector<lexem> lexems; // лексемы, идущие в том порядке, в котором они были встречены
	ifstream& in;
	ofstream& out; // возможно, придется убрать
	string buf;
	set<string> keyWords; // ключевые слова
	set<string> opAndSep; // операторы и разделители
public:
	lexical(ifstream& in, ofstream& out);
	~lexical();
	void analyze();
};

