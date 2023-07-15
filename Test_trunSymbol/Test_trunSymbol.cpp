#include "pch.h"
#include "CppUnitTest.h"
#include "..\TransLtRus\TransLtRus.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TesttrunSymbol
{
	TEST_CLASS(TesttrunSymbol)
	{
	public:
		
		//
		TEST_METHOD(uppReg)
		{
			string otvet = "Ñ";
			string exp = trunSymbol("S");
			Assert::AreEqual(exp, otvet);
		}

		TEST_METHOD(downReg)
		{
			string otvet = "ñ";
			string exp = trunSymbol("s");
			Assert::AreEqual(exp, otvet);
		}

		TEST_METHOD(uppRegPosledovatelnost)
		{
			string otvet = "×";
			string exp = trunSymbol("Ch");
			Assert::AreEqual(exp, otvet);
		}

		TEST_METHOD(downRegPosledovatelnost)
		{
			string otvet = "÷";
			string exp = trunSymbol("ch");
			Assert::AreEqual(exp, otvet);
		}

		TEST_METHOD(notBukvaOne)
		{
			string otvet = "&";
			string exp = trunSymbol("&");
			Assert::AreEqual(exp, otvet);
		}

		TEST_METHOD(notBukvaTwo)
		{
			string otvet = "&&";
			string exp = trunSymbol("&&");
			Assert::AreEqual(exp, otvet);
		}
	};
}
