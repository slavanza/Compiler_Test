#include "textProcessor.h"


void textProcessor::proceed()
{
	inputFile = text[0];
	if(text.size() > 1)
		outputFile = text[1];
	else
	{
		string buf = text[0];
		buf += ".masm";
		outputFile = buf;
	}
}

textProcessor::textProcessor(vector<string> & text)
{
	in = nullptr;
	out = nullptr;
	this->text = text;
	proceed();
}


textProcessor::~textProcessor()
{
	delete in;
	delete out;
}


ifstream& textProcessor::openInput()
{
	if(in == nullptr)
		in = new ifstream(inputFile.c_str());
	else
		cout << "Manage to close the stream before opening a new one" << endl;
	if (!in)
		throw exception("Couldn't open file");
	return *in;
}


ofstream& textProcessor::openOutput()
{
	if (out == nullptr)
		out = new ofstream(outputFile.c_str());
	else
		cout << "Manage to close the stream before opening a new one" << endl;
	if (!out)
		throw exception("Couldn't open file");
	return *out;
}


void textProcessor::closeInput()
{
	in->close();
	delete in;
}


void textProcessor::closeOutput()
{
	out->close();
	delete out;
}