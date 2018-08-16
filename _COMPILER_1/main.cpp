#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

#include "textProcessor.h"


// предварительный макет для тестов, потом надо перенести в отдельный класс, чтобы main сводился к 5-7 строкам кода
int main(int argC, char** argV)
{
	try 
	{
		if (argC < 3)
			throw string("Not enough arguments");
	}
	catch (string s)
	{
		if (s._Equal("Not enough arguments"))
			cout << "Usage: <parameter> <source file> <target file>" << endl;
		system("pause");
		return 1; // неверные входные параметры
	}
	/// <begin> Обработка входных аргументов
	vector<string> args;
	for (int i = 1; i < argC; i++)
	{
		args.push_back(string(argV[i]));
	}
	textProcessor processor(args); // первоначальная обработка входных аргументов
	/// <end> Обработка входных аргументов




	system("pause");
	return 0;
}