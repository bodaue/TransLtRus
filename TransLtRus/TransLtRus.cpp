﻿/*!
* \file
* \brief В данном файле находятся код функций исполняемых в программе
*/

#include "TransLtRus.h"

int main(int argc, char* argv[])
{
	//Русская локализация в консоли
	setlocale(LC_ALL, "Russian");

	//Входной файл
	ifstream file(argv[1]);

	//Исходный текст
	vector <string> text;
	vector <string>textKirill;//выходной тексты
	string str;//Пустая строка для предварительной записи из файла
	int countNotEmptyString;//счётчик не пустых строк

	//Проверка открылся ли входной файл
	if (!file.is_open())
	{
		cout << "Файла не существует или неверно указан путь" << endl;
	}
	else
	{
		//Считываем содержимое файла
		countNotEmptyString = 0;
		while (getline(file, str))
		{
			if (!str.empty())
				countNotEmptyString++;
			text.push_back(str);
		}

		//Закрывваем файл
		file.close();


		//Проверяем что строки не пустые
		if (countNotEmptyString == 0)
		{
			cout << "Все строки пустые!" << endl;
		}
		else
		{
			//Произвести построчную обратную транслитерацию текста
			for (int i = 0; i < text.size(); i++)
			{
				textKirill.push_back(trStr(text[i]));
			}

			//Открыть или создать выходной вайл
			ofstream fout(argv[2]);

			//Записать результат обратной транслитерации в выходной файл
			for (int i = 0; i < textKirill.size(); i++)
			{
				fout << textKirill[i] << endl;
			}

			//Закрыть выходной файл
			fout.close();
		}
	}
}

string trStr(string str)
{
	string stRus;//Результирующая строка

	//Пока не расмотрен каждый символ
	for (int i = 0; i < str.length(); i++)
	{
		//Проверка условия, что текущий символ не является буквой(началом слова)
		if (isalpha(str[i]) == 0)
		{
			//Записать символ в результирующую строку
			stRus += str[i];
		}
		else
		{
			int begin = i;//Начало слова

			//Поиск конца слова
			while (((isalpha(str[i]) != 0) || (str[i] == '\'')) && (i < str.length()))
			{
				i++;
			}
			
			if (checkWord(str.substr(begin, i - begin)))
			{
				//Выполнить поиск в словаре и записать его в результирующую строку
				stRus += findInWordList(str.substr(begin, i - begin));
			}
			else
			{
				//Запись обратно транслитерированного слова в результирующую строку
				stRus += trWord(str.substr(begin, i - begin));
			}

			//Записать символ в результирующую строку
			stRus += str[i];
		}
	}

	//Вернуть результирующую строку
	return stRus;
}

string trWord(string word)
{
	string wordRus;
	for (int i = 0; i < word.length(); i++)
	{
		wordRus.append(trunSymbol(word.substr(i, 1)));
	}
	return wordRus;
}

string findInWordList(string word)
{
	string fileName = "C:\\Users\\Admin\\source\\repos\\TransLtRus\\TransLtRus\\wordList.txt";//Название файла словаря
	string str;//промежуточная строка для считывания словаря из файла
	map <string, string> wordList;//Словарь
	ifstream file;//Входной файл словаря

	//Открыть файл со словарём
	file.open(fileName);

	//Пока не конец файла
	while (!file.eof())
	{
		//Считать построчно
		getline(file, str);
		wordList.insert(pair<string, string>(wordLat(str), str));
	}
	if (!wordList[word].empty())
	{
		return wordList[word];
	}
	else
	{
		return trWord(word);
	}
}

string wordLat(string word)
{
	string wordLat;

	for (int i = 0; i < word.length(); i++)
	{
		wordLat.append(symboLat(word.substr(i, 1)));
	}

	return wordLat;
}

string symboLat(string symbol)
{
	map <string, string> alphabet;//Контейнер для хранения алфавита
	alphabet = { {"А","A"},{"Б","B"},{"В","V"},{"Г","G"},{"Д","D"},{"Е","E"},{"Ё","E"},{"Ж","Zh"},{"З","Z"},{"И","I"},{"Й","I"},{"К","K"},{"Л","L"},{"М","M"},{"Н","N"},{"О","O"},
				 {"П","P"},{"Р","R"},{"С","S"},{"Т","T"},{"У","U"},{"Ф","F"},{"Х","H"},{"Ц","C"},{"Ч","Ch"},{"Ш","Sh"},{"Щ","Shch"},{"Ы","Y"},{"ь","'"},{"ъ","''"}, {"Э","Ie"},{"Ю","Iu"},
				 {"Я","Ia"},{"а","a"},{"б","b"},{"в","v"},{"г","g"},{"д","d"},{"е","e"},{"ё","e"},{"ж","zh"},{"з","z"},{"и","i"},{"й","i"},{"к","k"},{"л","l"},{"м","m"},{"н","n"},
				 {"о","o"},{"п","p"},{"р","r"},{"с","s"},{"т","t"},{"у","u"},{"ф","f"},{"х","h"},{"ц","c"},{"ч","ch"},{"ш","sh"},{"щ","shch"},{"ы","y"},{"э","ie"},{"ю","iu"},{"я","ia"} };
	//Проверка принадлежит ли символ алфавиту
	if (!alphabet[symbol].empty())
	{
		return alphabet[symbol];
	}
	else
	{
		return symbol;
	}
	
}

string trunSymbol(string symbol)
{
	map <string, string> alphabet;//Контейнер для хранения алфавита
	alphabet = { {"A","А"},{"B","Б"},{"V","В"},{"G","Г"},{"D","Д"},{"E","Е"},{"E","Ё"},{"Zh","Ж"},{"Z","З"},{"I","И"},{"I","Й"},{"K","К"},{"L","Л"},{"M","М"},{"N","Н"},{"O","О"},
				 {"P","П"},{"R","Р"},{"S","С"},{"T","Т"},{"U","У"},{"F","Ф"},{"H","Х"},{"C","Ц"},{"Ch","Ч"},{"Sh","Ш"},{"W","Щ"},{"Y","Ы"},{"'","ь"},{"''","ъ"}, {"Ie","Э"},{"Iu","Ю"},
				 {"Ia","Я"},{"a","а"},{"b","б"},{"v","в"},{"g","г"},{"d","д"},{"e","е"},{"e","ё"},{"zh","ж"},{"z","з"},{"i","и"},{"i","й"},{"k","к"},{"l","л"},{"m","м"},{"n","н"},
				 {"o","о"},{"p","п"},{"r","р"},{"s","с"},{"t","т"},{"u","у"},{"f","ф"},{"h","х"},{"c","ц"},{"ch","ч"},{"sh","ш"},{"w","щ"},{"y","ы"},{"ie","э"},{"iu","ю"},{"ia","я"} };

	//Проверка принадлежит ли символ алфавиту
	if (!alphabet[symbol].empty())
	{
		return alphabet[symbol];
	}
	else
	{
		return symbol;
	}
	return 0;
}

bool checkWord(string word)
{
	string posl[15] = {"Zh", "zh","Ch", "ch", "Sh", "sh", "Shch", "shch", "Ia", "ia", "Iu", "iu", "Ie", "ie", "\'\'"};
	bool res = false;
	for (int i = 0; i < 14; i++)
	{
		if (word.find(posl[i])<word.length())
		{
			res = true;
		}
	}
	return res;
}