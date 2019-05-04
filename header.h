#pragma once
#ifndef _HEADER_H
#define _HEADER_H
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cstdlib>
using namespace std;
//��������� ������ "��������".
//���� ���������:
//  1)��������� �� ������� �������, �� ������ � �� ��������
//  2)������ �����
//  3)���������� ���������� ���������
//  4)������ ����� ���������
//  5)�������� ���������� ����� ��������
//  6)���������� ���������� ����������� � �����
typedef struct AUTOPARK_Tree {
	AUTOPARK_Tree* Parent;
	string Name;
	int AmountValutation;
	string NumberBus;
	int NumberWay;
	char Presense;
	AUTOPARK_Tree* Left;
	AUTOPARK_Tree* Right;
};

__declspec(selectany) AUTOPARK_Tree* Root = 0;
__declspec(selectany) AUTOPARK_Tree* NewRoot = 0;
__declspec(selectany) int Position = 0;

//������� "����"
void MainMenu();
void OutputMenu();
void MenuOutputTree();
void ShowDataMenu();
void AllOportunuties();

//������ ����� ������ ������
void InputData();
void ShowData();
void HeadTable();
int PushData(AUTOPARK_Tree** Branch, AUTOPARK_Tree* ParentFunc, AUTOPARK_Tree Data);
void PrintTree(AUTOPARK_Tree* Branch);
void PrintTreeAsTree(AUTOPARK_Tree* Branch, int Level);

//������������ �������� ���������
void ShowListOfBus();
void ShowLeftBus(AUTOPARK_Tree* Branch);
void ShowRemainingBus(AUTOPARK_Tree* Branch);
void ResortingMain();
void Re_Sorting(AUTOPARK_Tree* Data);
void Re_SortingTree(AUTOPARK_Tree** Branch, AUTOPARK_Tree* ParentFunc, AUTOPARK_Tree* Data);

//�������������� ������ + ����� ������� � ������
void CorrectData();
AUTOPARK_Tree* SearchName(AUTOPARK_Tree* Branch, string SearchData);
void SearchForLetter();
void SearchDriver(AUTOPARK_Tree* Branch, char SearchChar, int* Counter);
void ShowMaxValutation();
AUTOPARK_Tree* SearchMaxValutation(AUTOPARK_Tree *Branch, AUTOPARK_Tree **MaxValutPtr, int MaxValutInt);

//�������� ������
void DeleteDataMain();
AUTOPARK_Tree* DeleteData(AUTOPARK_Tree** Branch, string Search);
void DemageTree(AUTOPARK_Tree* Branch);
void DeleteAllData();

//������ � �������
void StartProgram();
int ReadFromFile(string FileName);
void WriteInFile(AUTOPARK_Tree* Data, string FileName);
void WriteBuferData(AUTOPARK_Tree* Data, string FileName);

//�������������� �������
void Greeting();
bool CheckExistence(AUTOPARK_Tree *Branch, AUTOPARK_Tree Data);
int StringCompare(string str1, string str2);
int StringToInt(string str);
char GetKey();
bool IsLetter(const char sym);
int CheckStringToNumb(string str);
int CheckInt(string str);
bool IsDigit(const char sym);
int ToLower(const char sym);

#endif