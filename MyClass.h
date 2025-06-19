#pragma once
#include <vector>
#include <string>
#include <fstream>

// ��������, ��� ������ �������� ������ ����� � �������
bool isValidLine(const std::string& line);

// �������� ������������ �������� �����
int validateInput(std::ifstream& inputFile, std::ofstream& outputFile, std::vector<int>& sequence);

// ��������, ��� ������������������ � ����� ���������
bool isFibonacciSequence(const std::vector<int>&sequence, int& errorIndex);
