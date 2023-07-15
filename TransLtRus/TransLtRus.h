/*!
* \file
* \brief � ������ ����� ��������� ��������� ������� ����������� � ���������
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
* \brief ���������� �������� �������������� �����
* \param[in] string � ������ �� ������
* \return ������ �� ���������
*/
string trunSymbol(string symbol);

/*!
* \brief ���������� �������� �������������� �����
* \param[in] word - �������� �����, ���������� �� ������
* \return - �����, ���������� �� ���������
*/
string trWord(string word);

/*!
* \brief ���������� �������� �������������� ������
* \param[in] str - �������� ������ �� ������
* \return - ������, ���������� �� ���������
*/
string trStr(string str);

/*!
* \brief ���������� �������������� ������� � ��������� �� ������
* \param[in] symbol - �������� ������ �� ���������
* \return - ������ �� ������
*/
string symboLat(string symbol);

/*!
* \brief ���������� �������������� ����� � ��������� �� ������
* \param[in] word - �������� ����� �� ���������
* \return - �����, ���������� �� ������
*/
string wordLat(string word);

/*!
* \brief ��������� ������� ������������������ ��������� ����, ���������� ���� ������ ��� �������� �������������� �� ���������, � �����
* \param[in] word - ����� �� ������, ������� ����� ���������
* \return - true - � ����� ���������� ������������������, false - � ����� ������������������ �� ��������� 
*/
bool checkWord(string word);

/*!
* \brief ��������� ����� ����� � ���������������� ������� ��� ������������ �������� ��������������
* \param[in] word - ������� �����
* \return - ����� �� ���������
*/
string findInWordList(string word);