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
};


// ��������, � ���������� ������� ���������� �� ���������� ��������� �����, ������� �� ����������� ��� �������������
vector<string> Types = { "i32", "u32", "bool", "char", "f32", "f64", "void" };


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
	string buf;
	set<string> keyWords; // �������� �����
	set<char> opAndSep; // ��������� � �����������

	unsigned cursor;
	unsigned line;
public:
	lexical(ifstream& in, ofstream& out);
	~lexical();
	void analyze();
private:
	bool getNextToken();
	unsigned isConstant(); // �������� �� ���������
	unsigned checkOperator(); // �������� ������� ����������
	void isIdentifier(); // �������� �� �������������
	bool nextSymbol(); // ��������� ���������� �������
};


/// [TODO]: �������� ��� �������, �������������� ��������� ������, ������������������ � ������������