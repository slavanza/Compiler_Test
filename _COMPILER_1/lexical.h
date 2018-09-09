#pragma once

#include <string>
#include <vector>
#include <set>
#include <fstream>

#include "token.h"

using std::string;
using std::vector;
using std::set;
using std::ifstream;
using std::ofstream;

struct lexem
{
	unsigned lexemType;
	string lex;
	unsigned line;
	unsigned pos;
};


// возможно, в дальнейшем придётся отказаться от реализации некоторых типов, которые не потребуются для использования
vector<string> Types = { "i32", "bool", "char", "f32", "void" };


vector<string> Keywords = { "if", "else", "for", "while", "do", "return" };


// основные знаки и символы, применяемые в высказываниях
string Operators = "+-*/&|<>=!.";


string Separators = "{}()[],;\"";


// доступные для имён буквы нижнего регистра
string lower = "abcdefghijklmnopqrstuvwxyz";

// доступные для имён буквы верхнего регистра
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// доступные цифры
string numbers = "0123456789";


class lexical
{
	vector<lexem> lexems; // лексемы, идущие в том порядке, в котором они были встречены
	const ifstream* in;
	const ofstream* out; // возможно, придется убрать
	string program;
	set<string> keyWords; // ключевые слова
	set<char> opAndSep; // операторы и разделители
	char current; // текущий символ

	unsigned cursor;
	unsigned line;
public:
	lexical(ifstream& in, ofstream& out);
	~lexical();
	void analyze();
private:
	bool getNextToken();
	bool nextSymbol(); // получение следующего символа
	void skipSpaceAndComment(); // пропуск пробелов и комментариев
	unsigned isConstant(); // проверка на константу
	unsigned checkOperator(); // проверка двойных операторов
	void isIdentifier(); // проверка на идентификатор
	void addLexInfo(lexem& lex); // заполнение лексемы
};


/// [TODO]: Добавить ещё функций, протестировать обработку текста, работоспособносить и корректность