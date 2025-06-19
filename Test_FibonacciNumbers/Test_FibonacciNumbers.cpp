#include "pch.h"
#include "CppUnitTest.h"
#include "../MyClass.h"
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFibonacciNumbers
{
	TEST_CLASS(TestIsValidLine)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Исходная строка
			std::string line = "0 1 1 2 3";

			// Ожидаемый результат
			bool expected = true;

			// Вызов функции
			bool result = isValidLine(line);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethod2)
		{
			// Исходная строка
			std::string line = "* _ !";

			// Ожидаемый результат
			bool expected = false;

			// Вызов функции
			bool result = isValidLine(line);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethod3)
		{
			// Исходная строка
			std::string line = "0 1 1 * 3";

			// Ожидаемый результат
			bool expected = false;

			// Вызов функции
			bool result = isValidLine(line);

			Assert::AreEqual(expected, result);
		}
	};


	TEST_CLASS(TestValidateInput)
	{
		const std::string inputFileName = "temp_input.txt";
		const std::string outputFileName = "temp_output.txt";

		void writeToFile(const std::string& filename, const std::string& content) {
			std::ofstream file(filename);
			file << content;
		}

		std::string readFromFile(const std::string& filename) {
			std::ifstream file(filename);
			return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		}

		void removeTempFiles() {
			std::remove(inputFileName.c_str());
			std::remove(outputFileName.c_str());
		}

	public:

		TEST_METHOD(TestMethod1)
		{
			writeToFile(inputFileName, "0 1 1 2 3 5");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 0;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod2)
		{
			writeToFile(inputFileName, "0 1 1 3");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 0;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod3)
		{
			writeToFile(inputFileName, "");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 3;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod4)
		{
			writeToFile(inputFileName, "0 1 1 2\n0 1 1 2 3");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 4;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod5)
		{
			writeToFile(inputFileName, "0 1 1 3\n0 1 1 2 5");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 4;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod6)
		{
			writeToFile(inputFileName, "0 1 1 * 3");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 5;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod7)
		{
			writeToFile(inputFileName, "-2 -1 0 1 2");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 5;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod8)
		{
			writeToFile(inputFileName, "1");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 6;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}

		TEST_METHOD(TestMethod9)
		{
			writeToFile(inputFileName, "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");

			std::ifstream input(inputFileName);
			std::ofstream output(outputFileName);

			std::vector<int> sequence;
			int result = validateInput(input, output, sequence);

			input.close();
			output.close();

			int expected = 7;

			Assert::AreEqual(expected, result);

			removeTempFiles();
		}
	};

	TEST_CLASS(TestIsFibonacciSequence)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			std::vector<int> sequence = { 0, 1 };
			int errorIndex = -1;

			bool result = isFibonacciSequence(sequence, errorIndex);

			bool expected = true;

			Assert::AreEqual(expected, result);
			Assert::AreEqual(-1, errorIndex);
		}

		TEST_METHOD(TestMethod2)
		{
			std::vector<int> sequence = { 0, 1, 1, 2, 3 };
			int errorIndex = -1;

			bool result = isFibonacciSequence(sequence, errorIndex);

			bool expected = true;

			Assert::AreEqual(expected, result);
			Assert::AreEqual(-1, errorIndex);
		}

		TEST_METHOD(TestMethod3)
		{
			std::vector<int> sequence = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181 };
			int errorIndex = -1;

			bool result = isFibonacciSequence(sequence, errorIndex);

			bool expected = true;

			Assert::AreEqual(expected, result);
			Assert::AreEqual(-1, errorIndex);
		}

		TEST_METHOD(TestMethod4)
		{
			std::vector<int> sequence = { 1, 1 };
			int errorIndex = -1;

			bool result = isFibonacciSequence(sequence, errorIndex);

			bool expected = false;

			Assert::AreEqual(expected, result);
			Assert::AreEqual(0, errorIndex);
		}

		TEST_METHOD(TestMethod5)
		{
			std::vector<int> sequence = { 0, 1, 2, 2, 3 };
			int errorIndex = -1;

			bool result = isFibonacciSequence(sequence, errorIndex);

			bool expected = false;

			Assert::AreEqual(expected, result);
			Assert::AreEqual(2, errorIndex);
		}

		TEST_METHOD(TestMethod6)
		{
			std::vector<int> sequence = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 45, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181 };
			int errorIndex = -1;

			bool result = isFibonacciSequence(sequence, errorIndex);

			bool expected = false;

			Assert::AreEqual(expected, result);
			Assert::AreEqual(9, errorIndex);
		}

		TEST_METHOD(TestMethod7)
		{
			std::vector<int> sequence = { 0, 1, 2, 3, 3, 5, 8 };
			int errorIndex = -1;

			bool result = isFibonacciSequence(sequence, errorIndex);

			bool expected = false;

			Assert::AreEqual(expected, result);
			Assert::AreEqual(2, errorIndex);
		}
	};
}
