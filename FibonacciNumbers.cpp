#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

// Проверка, что строка содержит только цифры и пробелы
bool isValidLine(const string& line) {
    for (char ch : line) {
        if (!isdigit(ch) && !isspace(ch)) {
            return false;
        }
    }
    return true;
}

// Проверка корректности входного файла
int validateInput(ifstream& inputFile, ofstream& outputFile, vector<int>& sequence) {

    // Считываем все строки из входного файла
    string line;
    vector<string> allLines;
    while (getline(inputFile, line)) {
        allLines.push_back(line);
    }

    // Ошибка 3: входной файл пустой
    if (allLines.empty()) {
        outputFile << "Входной файл пустой." << endl;
        return 3;
    }

    // Ошибка 4: больше одной строки
    if (allLines.size() > 1) {
        outputFile << "Программа принимает на вход файлы из одной строки." << endl;
        return 4;
    }

    // Ошибка 5: посторонние символы (не цифры и не пробелы)
    if (!isValidLine(allLines[0])) {
        outputFile << "Программа принимает на вход только целые неотрицательные числа." << endl;
        return 5;
    }

    // Парсинг строки в числа
    istringstream iss(allLines[0]);
    int num;
    while (iss >> num) {
        if (num < 0) {
            outputFile << "Программа принимает на вход только целые неотрицательные числа." << endl;
            return 5;
        }
        sequence.push_back(num);
    }

    // Ошибка 6: меньше 2 чисел
    if (sequence.size() < 2) {
        outputFile << "Минимальное количество чисел в последовательности - 2." << endl;
        return 6;
    }

    // Ошибка 7: больше 1000 чисел
    if (sequence.size() > 1000) {
        outputFile << "Максимальное количество чисел в последовательности - 1000." << endl;
        return 7;
    }

    return 0; // Успех
}

// Проверка, что последовательность — числа Фибоначчи
bool isFibonacciSequence(const vector<int>& sequence, int& errorIndex) {

    // Проверяем первые два числа
    if (sequence[0] != 0) {
        errorIndex = 0;
        return false;
    }

    if (sequence[1] != 1) {
        errorIndex = 1;
        return false;
    }

    // Проверяем остальные числа
    for (size_t i = 2; i < sequence.size(); ++i) {
        if (sequence[i] != sequence[i - 1] + sequence[i - 2]) {
            errorIndex = i;
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("C:/Users/Daniil2/source/repos/FibonacciNumbers/input.txt");
    ofstream outputFile("C:/Users/Daniil2/source/repos/FibonacciNumbers/output.txt");
    
    // Ошибка 1: входной файл не существует
    if (!inputFile) {
        cout << "Неверно указан файл с входными данными. Возможно, файл не существует." << endl;
        return 1;
    }

    // Ошибка 2: выходной файл не создается
    if (!outputFile) {
        cout << "Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись." << endl;
        return 2;
    }
        
    vector<int> sequence;
    int validationCode = validateInput(inputFile, outputFile, sequence);

    if (validationCode != 0) {
        return validationCode;
    }

    // Проверка на последовательность чисел Фибоначчи
    int errorIndex = -1;
    if (isFibonacciSequence(sequence, errorIndex)) {
        outputFile << "Это числа Фибоначчи" << endl;
    }
    else {
        outputFile << "Это не числа Фибоначчи, потому что "
            << errorIndex + 1
            << "-е число в данной последовательности не вычисляется как сумма двух предыдущих"
            << endl;
    }

    return 0;
}
