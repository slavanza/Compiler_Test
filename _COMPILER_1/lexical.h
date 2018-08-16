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


// возможно, в дальнейшем придётся отказаться от реализации некоторых типов, которые не потребуются для использования (таких как long int)
vector<string> Types = { string("i8"), string("u8"), string("i16"),
						string("u16"), string("i32"), string("u32"),
						string("i64"), string("u64"),
						string("bool"), string("char"),
						string("f32"), string("f64") };


// основные знаки и символы, применяемые в высказываниях
vector<string> Signs = { string("+"), string("-"), string("*"), string("/"),
						string("&"), string("|"), string("<"), string("="),
						string("="), string("!"), string("["), string("]"),
						string("("), string(")") };


// доступные для имён буквы нижнего регистра
string lower = "abcdefghijklmnopqrstuvwxyz";

// доступные для имён буквы верхнего регистра
string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// доступные цифры
string numbers = "0123456789";


class lexical
{
	vector<token> input; // токены, идущие в том порядке, в котором они были встречены
	const vector<string> const *lpText;
public:
	lexical(vector<string>* lpVector);
	~lexical();
	void analyze();
};

