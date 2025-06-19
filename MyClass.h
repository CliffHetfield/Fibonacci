#pragma once
#include <vector>
#include <string>
#include <fstream>

// Проверка, что строка содержит только цифры и пробелы
bool isValidLine(const std::string& line);

// Проверка корректности входного файла
int validateInput(std::ifstream& inputFile, std::ofstream& outputFile, std::vector<int>& sequence);

// Проверка, что последовательность — числа Фибоначчи
bool isFibonacciSequence(const std::vector<int>&sequence, int& errorIndex);
