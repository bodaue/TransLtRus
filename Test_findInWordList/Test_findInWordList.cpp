#include "pch.h"
#include "CppUnitTest.h"
#include "..\TransLtRus\TransLtRus.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestfindInWordList
{
	TEST_CLASS(TestfindInWordList)
	{
	public:
		
		TEST_METHOD(wordIsFind)
		{
			string word = "Chacha", exp = "����", wordRus;
			wordRus = findInWordList(word);
			Assert::AreEqual(wordRus, exp);
		}

		TEST_METHOD(wordIsNotFind)
		{
			string word = "Zhacha", exp = "������", wordRus;
			wordRus = findInWordList(word);
			Assert::AreEqual(wordRus, exp);
		}
	};
}
