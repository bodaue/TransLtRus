/*!
* \file
* \brief В данном файле находятся заголовки функций исполняемых в программе
*/
#pragma once
#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <fstream>
using namespace std;

/*!
* \brief производит обратную транслитерацию буквы
* \param[in] string – символ на латыни
* \return символ на кириллице
*/
string trunSymbol(string symbol);

/*!
* \brief производит обратную транслитерацию слова
* \param[in] word - исходное слово, написанное на латыне
* \return - слово, написанное на кириллице
*/
string trWord(string word);

/*!
* \brief производит обратную транслитерацию строки
* \param[in] str - исходная строка на латыне
* \return - строка, написанная на кириллице
*/
string trStr(string str);

/*!
* \brief производит транслитерацию символа с кириллице на латынь
* \param[in] symbol - исзодный символ на кириллице
* \return - символ на латыне
*/
string symboLat(string symbol);

/*!
* \brief производит транслитерацию слова с кириллици на латынь
* \param[in] word - исходное слово на кириллице
* \return - слово, написанное на латыне
*/
string wordLat(string word);

/*!
* \brief проверяет наличие последовательности латынских букв, образующих один символ при обратной транслитерации на кириллицу, в слове
* \param[in] word - слово на латыне, которое нужно проверить
* \return - true - в слове содержатся последовательность, false - в слове последовательности не содержтся 
*/
bool checkWord(string word);

/*!
* \brief выполняет поиск слова в пользовательском словаре для произведения обратной транслитерации
* \param[in] word - искомое слово
* \return - слово на кириллице
*/
string findInWordList(string word);