#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

//#include "textProcessor.h"


// предварительный макет для тестов, потом надо перенести в отдельный класс, чтобы main сводился к 5-7 строкам кода

const int params = 2;

int main(int argC, char** argV)
{
	/*if (argC != 3)
	{
		cout << "Передано " << argC << " параметров" << endl << "Должно быть передано параметров: " << params << endl;
		cout << "Использование: <файл исходного кода> <конечный файл (не обязательно)>" << endl;
		system("pause");
		return -1;
	}
	/// <begin> Обработка входных аргументов

	vector<string> args;
	for (int i = 1; i < argC; i++)
	{
		args.push_back(string(argV[i]));
	}
	textProcessor processor(args); // первоначальная обработка входных аргументов

	/// <end> Обработка входных аргументов
	*/


	string param = argV[1];
	cout << "Compiled " << param << " succesfully" << endl;


	system("pause");
	return 0;
}