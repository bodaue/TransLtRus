#include "pch.h"
#include "CppUnitTest.h"
#include "..\TransLtRus\TransLtRus.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestcheckWord
{
	TEST_CLASS(TestcheckWord)
	{
	public:
		
		TEST_METHOD(type)
		{
			string word = "Chavkat'";
			bool otvet;
			otvet = checkWord(word);
			Assert::IsTrue(otvet);
		}

		TEST_METHOD(downReg)
		{
			string word = "chavkat'";
			bool otvet;
			otvet = checkWord(word);
			Assert::IsTrue(otvet);
		}

		TEST_METHOD(notPosl)
		{
			string word = "havkat'";
			bool otvet;
			otvet = checkWord(word);
			Assert::IsFalse(otvet);
		}

		TEST_METHOD(poslInsert)
		{
			string word = "Pochavkat'";
			bool otvet, exp = true;
			otvet = checkWord(word);
			Assert::IsTrue(otvet);
		}

		TEST_METHOD(endPosl)
		{
			string word = "Poch";
			bool otvet, exp = true;
			otvet = checkWord(word);
			Assert::IsTrue(otvet);
		}
	};
}
