#include "pch.h"
#include "CppUnitTest.h"
#include "..\TransLtRus\TransLtRus.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TesttrWord
{
	TEST_CLASS(TesttrWord)
	{
	public:
		
		TEST_METHOD(type)
		{
			string exp = "Ворота", res = "Vorota";
			res = trWord(res);
			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(empty)
		{
			string exp = "", res = "";
			res = trWord(res);
			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(leftSymbols)
		{
			string exp = "&&&&", res = "&&&&";
			res = trWord(res);
			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(oneSymbol)
		{
			string exp = "В", res = "V";
			res = trWord(res);
			Assert::AreEqual(exp, res);
		}

		TEST_METHOD(twoSymbol)
		{
			string exp = "Во", res = "Vo";
			res = trWord(res);
			Assert::AreEqual(exp, res);
		}
	};
}
