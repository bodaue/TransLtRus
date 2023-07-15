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
			string word = "Chacha", exp = "„ача", wordRus;
			wordRus = findInWordList(word);
			Assert::AreEqual(wordRus, exp);
		}

		TEST_METHOD(wordIsNotFind)
		{
			string word = "Zhacha", exp = "«хацха", wordRus;
			wordRus = findInWordList(word);
			Assert::AreEqual(wordRus, exp);
		}
	};
}
