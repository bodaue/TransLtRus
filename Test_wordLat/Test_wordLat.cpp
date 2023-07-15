#include "pch.h"
#include "CppUnitTest.h"
#include "..\TransLtRus\TransLtRus.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestwordLat
{
	TEST_CLASS(TestwordLat)
	{
	public:
		
		TEST_METHOD(type)
		{
			string res = "иряър", exp = "Shapka";
			res = wordLat(res);
			Assert::AreEqual(res, exp);
		}

		TEST_METHOD(oneBukva)
		{
			string res = "и", exp = "Sh";
			res = wordLat(res);
			Assert::AreEqual(res, exp);
		}

		TEST_METHOD(leftSymbol)
		{
			string res = "ир&яър", exp = "Sha&pka";
			res = wordLat(res);
			Assert::AreEqual(res, exp);
		}
	};
}
