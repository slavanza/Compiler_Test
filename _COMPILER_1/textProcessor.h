#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


/// <summary>
/// ����������� ������ ��������� �����������, ����������� ��� �������,
/// ����� ������������ �� ���������� ��������� � ����������� �������� �� � ������
/// </summary>
class textProcessor
{
	vector<string> text; // �����, ���������� �� ����
	char cType; // ��� ��������������� �������� || �������� ����� ������������ enum
	string inputFile; // ������� ����
	string outputFile; // �������� ����
	void proceed(); // ��������� ���������
public:
	textProcessor(vector<string> & text);
	~textProcessor();
	ifstream& openInput();
	ofstream& openOutput();
private:
	ifstream* in; // ������ ����� � ������ ��������������,
	ofstream* out; // ��������� ����� ������� �� �������� �����
};

