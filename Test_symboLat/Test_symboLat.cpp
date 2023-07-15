#include "pch.h"
#include "CppUnitTest.h"
#include "..\TransLtRus\TransLtRus.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsymboLat
{
	TEST_CLASS(TestsymboLat)
	{
	public:
		
		TEST_METHOD(type)
		{
			string res = "÷", exp = "ch"; 
			res = symboLat(res);
			Assert::AreEqual(res, exp);
		}

		TEST_METHOD(notSymbol)
		{
			string res = "&", exp = "&"; 
			res = symboLat(res);
			Assert::AreEqual(res, exp);
		}

		TEST_METHOD(upReg)
		{
			string res = "×", exp = "Ch"; \
				res = symboLat(res);
			Assert::AreEqual(res, exp);
		}
	};
}
