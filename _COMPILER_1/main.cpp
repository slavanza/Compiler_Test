#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

//#include "textProcessor.h"


// ��������������� ����� ��� ������, ����� ���� ��������� � ��������� �����, ����� main �������� � 5-7 ������� ����

const int params = 2;

int main(int argC, char** argV)
{
	/*if (argC != 3)
	{
		cout << "�������� " << argC << " ����������" << endl << "������ ���� �������� ����������: " << params << endl;
		cout << "�������������: <���� ��������� ����> <�������� ���� (�� �����������)>" << endl;
		system("pause");
		return -1;
	}
	/// <begin> ��������� ������� ����������

	vector<string> args;
	for (int i = 1; i < argC; i++)
	{
		args.push_back(string(argV[i]));
	}
	textProcessor processor(args); // �������������� ��������� ������� ����������

	/// <end> ��������� ������� ����������
	*/


	string param = argV[1];
	cout << "Compiled " << param << " succesfully" << endl;


	system("pause");
	return 0;
}