#include "textProcessor.h"


void textProcessor::proceed()
{
	cType = 0;
	/// <1>
	if ((text[0].find("-o") >= 0) || (text[0].find("-O") >= 0))
		cType = 'o';
	else if ((text[0].find("-c") >= 0) || (text[0].find("-C") >= 0))
		cType = 'c';
	else if ((text[0].find("-a") >= 0) || (text[0].find("-A") >= 0))
		cType = 'a';
	if (!cType)
		throw string("Wrong parameter");
	/// <2>
	inputFile = text[1];

	/// <3>
	if (text.size() > 2)
		outputFile = text[2];
}

textProcessor::textProcessor(vector<string> & text)
{
	in = nullptr;
	out = nullptr;
	this->text = text;
	/// обработка входных аргументов
	/// -o <source> <result>  | компил€ци€ в объектный файл
	/// -c <source> <result>  | компил€ци€ в исполн€емый файл
	/// -a <source> <result>  | трансл€ци€ в файл на ассемблере
	
	proceed();
}


textProcessor::~textProcessor()
{
	delete in;
	delete out;
}


ifstream& textProcessor::openInput()
{
	if(in != nullptr)
		in = new ifstream(inputFile.c_str());
	return *in;
}


ofstream& textProcessor::openOutput()
{
	if(out != nullptr)
		out = new ofstream(outputFile.c_str());
	return *out;
}