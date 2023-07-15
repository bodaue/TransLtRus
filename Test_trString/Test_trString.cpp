#include "pch.h"
#include "CppUnitTest.h"
#include "..\TransLtRus\TransLtRus.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TesttrString
{
	TEST_CLASS(TesttrString)
	{
	public:
		
		TEST_METHOD(oneWord)
		{
			string str = "Privet", exp = "Привет";
			str = trStr(str);
			Assert::AreEqual(str, exp);
		}

		TEST_METHOD(empty)
		{
			string str = "", exp = "";
			str = trStr(str);
			Assert::AreEqual(str, exp);
		}

		TEST_METHOD(notBukva)
		{
			string str = "...!?", exp = "...!?";
			str = trStr(str);
			Assert::AreEqual(str, exp);
		}

		TEST_METHOD(beginWordEndWord)
		{
			string str = "Privet mir", exp = "Привет мир";
			str = trStr(str);
			Assert::AreEqual(str, exp);
		}

		TEST_METHOD(beginDelimiterEndDelimiter)
		{
			string str = "-Privet mir!", exp = "-Привет мир!";
			str = trStr(str);
			Assert::AreEqual(str, exp);
		}

		TEST_METHOD(beginWordEndDelimiter)
		{
			string str = "Privet mir!", exp = "Привет мир!";
			str = trStr(str);
			Assert::AreEqual(str, exp);
		}

		TEST_METHOD(beginDelimiterEndWord)
		{
			string str = "-Privet mir", exp = "-Привет мир";
			str = trStr(str);
			Assert::AreEqual(str, exp);
		}
	};
}
