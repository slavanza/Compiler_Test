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


// ��������, � ���������� ������� ���������� �� ���������� ��������� �����, ������� �� ����������� ��� �������������
vector<string> Types = { "i32", "bool", "char", "f32", "void" };


vector<string> Keywords = { "if", "else", "for", "while", "do", "return" };


// �������� ����� � �������, ����������� � �������������
string Operators = "+-*/&|<>=!.";


string Separators = "{}()[],;\"";


// ��������� ��� ��� ����� ������� ��������
string lower = "abcdefghijklmnopqrstuvwxyz";

// ��������� ��� ��� ����� �������� ��������
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// ��������� �����
string numbers = "0123456789";


class lexical
{
	vector<lexem> lexems; // �������, ������ � ��� �������, � ������� ��� ���� ���������
	const ifstream* in;
	const ofstream* out; // ��������, �������� ������
	string program;
	set<string> keyWords; // �������� �����
	set<char> opAndSep; // ��������� � �����������
	char current; // ������� ������

	unsigned cursor;
	unsigned line;
public:
	lexical(ifstream& in, ofstream& out);
	~lexical();
	void analyze();
private:
	bool getNextToken();
	bool nextSymbol(); // ��������� ���������� �������
	void skipSpaceAndComment(); // ������� �������� � ������������
	unsigned isConstant(); // �������� �� ���������
	unsigned checkOperator(); // �������� ������� ����������
	void isIdentifier(); // �������� �� �������������
	void addLexInfo(lexem& lex); // ���������� �������
};


/// [TODO]: �������� ��� �������, �������������� ��������� ������, ������������������ � ������������