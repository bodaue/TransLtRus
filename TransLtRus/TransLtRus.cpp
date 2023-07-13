#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <fstream>
using namespace std;
string trunSymbol(string symbol);

int main()
{
	//Русская локализация в консоли
	setlocale(LC_ALL, "Russian");

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
}