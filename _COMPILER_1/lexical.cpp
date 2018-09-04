#include "lexical.h"

#include <fstream>
using namespace std;


lexical::lexical(ifstream& in, ofstream& out): in(in), out(out)
{
	// ������� �����
	for (auto k = begin(Keywords); k < end(Keywords); k++)
		keyWords.insert(*k);
	// ����
	for (auto k = begin(Types); k < end(Types); k++)
		keyWords.insert(*k);
	// ���������
	for (auto k = begin(Operators); k < end(Operators); k++)
		opAndSep.insert(*k);
	// �����������
	for (auto k = begin(Separators); k < end(Separators); k++)
		opAndSep.insert(*k);
}


lexical::~lexical()
{
	if (!in.is_open())
		throw exception("Input stream is closed");
	if (!out.is_open())
		throw exception("Output stream is closed");
}


void lexical::analyze()
{
	
}