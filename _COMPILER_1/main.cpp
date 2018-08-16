#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

#include "textProcessor.h"


// ��������������� ����� ��� ������, ����� ���� ��������� � ��������� �����, ����� main �������� � 5-7 ������� ����
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
		return 1; // �������� ������� ���������
	}
	/// <begin> ��������� ������� ����������
	vector<string> args;
	for (int i = 1; i < argC; i++)
	{
		args.push_back(string(argV[i]));
	}
	textProcessor processor(args); // �������������� ��������� ������� ����������
	/// <end> ��������� ������� ����������




	system("pause");
	return 0;
}