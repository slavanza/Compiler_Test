#include "lexical.h"

#include <fstream>
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
	for (int i = 0; i < Operators.size(); i++)
		opAndSep.insert(Operators[i]);
	// разделители
	for (int i = 0; i < Separators.size(); i++)
		opAndSep.insert(Separators[i]);

	cursor = 0;
	line = 1;
}


lexical::~lexical()
{
	if (!in->is_open())
		throw exception("Input stream is closed");
	if (!out->is_open())
		throw exception("Output stream is closed");
}


void lexical::analyze()
{
	
}


bool lexical::getNextToken()
{
	lexem lex;
}