#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


/// <summary>
/// –асполагает только исходными параметрами, переданными при запуске,
/// будет осуществл€ть их дальнейшую обработку и производить действи€ на еЄ основе
/// </summary>
class textProcessor
{
	vector<string> text; // текст, переданный на вход
	char cType; // тип осуществл€емого действи€ || возможно стоит использовать enum
	string inputFile; // входной файл
	string outputFile; // выходной файл
	void proceed(); // первична€ обработка
public:
	textProcessor(vector<string> & text);
	~textProcessor();
	ifstream& openInput();
	ofstream& openOutput();
private:
	ifstream* in; // потоки ввода и вывода соответственно,
	ofstream* out; // создаютс€ после запроса на открытие файла
};

