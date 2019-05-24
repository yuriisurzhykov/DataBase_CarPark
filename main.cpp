﻿/*
+---------------------------------------------------------------------------------------+
|              ПРЕДМЕТНАЯ ОБЛАСТЬ – АВТОПАРК.											|
|  Основные возможности программы:														|
|  -  добавление элемента;																|
|  -  удаление элемента;																|
|  -  возможность корректировки данных;													|
|  -  вывод всех данных;																|
|  -  формирование списка автобусов, выехавших из парка (оставшихся в парке);			|
|  -  вывод данных о водителях с наибольшим числом нарушений;							|
|  -  сортировкa данных по номерам автобусов;											|
|  -  вывод всех фамилий водителей, начинающихся  на заданную букву.					|
|																						|
+---------------------------------------------------------------------------------------+
*/

#include "header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	StartProgram();
	while (true) {
		MainMenu();
	}
	return 0;
}