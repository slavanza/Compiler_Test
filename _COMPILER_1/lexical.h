#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

struct token
{
	string chars;
	token(const char* lpCh, int str, int seek) { chars = lpCh; }
};


// ��������, � ���������� ������� ���������� �� ���������� ��������� �����, ������� �� ����������� ��� ������������� (����� ��� long int)
vector<string> Types = { string("i8"), string("u8"), string("i16"),
						string("u16"), string("i32"), string("u32"),
						string("i64"), string("u64"),
						string("bool"), string("char"),
						string("f32"), string("f64") };


// �������� ����� � �������, ����������� � �������������
vector<string> Signs = { string("+"), string("-"), string("*"), string("/"),
						string("&"), string("|"), string("<"), string("="),
						string("="), string("!"), string("["), string("]"),
						string("("), string(")") };


// ��������� ��� ��� ����� ������� ��������
string lower = "abcdefghijklmnopqrstuvwxyz";

// ��������� ��� ��� ����� �������� ��������
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// ��������� �����
string numbers = "0123456789";


class lexical
{
	vector<token> input; // ������, ������ � ��� �������, � ������� ��� ���� ���������
	const vector<string> const *lpText;
public:
	lexical(vector<string>* lpVector);
	~lexical();
	void analyze();
};

