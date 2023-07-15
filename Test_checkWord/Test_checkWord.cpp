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
			bool otvet, exp = true;
			otvet = checkWord(word);
			Assert::IsTrue(otvet);
		}
	};
}
