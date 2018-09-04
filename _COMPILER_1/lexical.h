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


// ��������, � ���������� ������� ���������� �� ���������� ��������� �����, ������� �� ����������� ��� �������������
vector<string> Types = { "i32", "u32", "bool", "char", "f32", "f64", "void" };


vector<string> Keywords = { "if", "else", "for", "while", "do", "return" };


// �������� ����� � �������, ����������� � �������������
vector<string> Operators = { "+", "-", "*", "/", "&", "|", "<", ">", "=", "!" };


vector<string> Separators = { "{", "}", "(", ")","[", "]" };


// ��������� ��� ��� ����� ������� ��������
string lower = "abcdefghijklmnopqrstuvwxyz";

// ��������� ��� ��� ����� �������� ��������
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// ��������� �����
string numbers = "0123456789";


class lexical
{
	vector<lexem> lexems; // �������, ������ � ��� �������, � ������� ��� ���� ���������
	ifstream& in;
	ofstream& out; // ��������, �������� ������
	string buf;
	set<string> keyWords; // �������� �����
	set<string> opAndSep; // ��������� � �����������
public:
	lexical(ifstream& in, ofstream& out);
	~lexical();
	void analyze();
};

