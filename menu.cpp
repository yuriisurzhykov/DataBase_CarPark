#include "header.h"

void MainMenu() {
	system("cls");
	cout << "1. Добавить данные." << endl;
	cout << "2. Редактировать данные." << endl;
	cout << "3. Удалить данные." << endl;
	cout << "4. Показать данные." << endl;
	cout << "5. Другие возможности." << endl;
	cout << "0. Выход." << endl;
	char Answer = _getch();
	switch (Answer) {
	case '1':
		InputData();
		break;
	case '2':
		CorrectData();
		break;
	/*case '3':
		DeleteDataMain();
		break;*/
	case '4':
		ShowDataMenu();
		break;
	case '5':
		AllOportunuties();
		break;
	case '0':
		remove("BUFER_DATA.txt");
		WriteInFile(Root, "BASE.txt");
		DemageTree(Root);
		exit(0);
	default:
		MainMenu();
	}
}

void ShowDataMenu() {
	system("cls");
	cout << "1. Вывестив в виде списка." << endl;
	cout << "2. Вывести в виде дерева." << endl;
	cout << "0. Вернуться в главное меню." << endl;
	char Answer = _getch();
	switch (Answer) {
	case '1':
		ShowData();
		break;
	default:
		ShowDataMenu();
	}
}

void AllOportunuties() {
	system("cls");
	cout << "1. Добавление данных." << endl;
	cout << "2. Удаление данных." << endl;
	cout << "3. Редактирование данных." << endl;
	cout << "4. Поиск данных на заданую букву." << endl;
	cout << "5. Формирование списков автобусов." << endl;
	cout << "6. Поиск водителя с найбольшим числом нарушений." << endl;
	cout << "7. Сортировка данных по номеру автобуса." << endl;
	cout << "8. Вывод данных." << endl;
	cout << "0. Вернуться назад." << endl;
	char Answer = _getch();
	switch (Answer) {
	case '1':
		InputData();
		break;
	/*case '2':
		DeleteDataMain();
		break;
	case '3':
		CorrectData();
		break;*/
	case '4':
		SearchForLetter();
		break;
	/*case '5':
		ShowListOfBus();
		break;*/
	case '6':
		ShowMaxValutation();
		break;
	/*case '7':
		ResortingMain();
		break;*/
	case '8':
		ShowData();
		break;
	default:
		AllOportunuties();
	}
}

/*void DeleteDataMenu()
{
	string SearchData;
	HeadTable();
	PrintTree(Root);
	cout << "Введите ФИО для удаления: ";
	getline(cin, SearchData);
	while (DeleteData(&Root, SearchData) == NULL) {
		cout << "В базе нет такого элемента!";
		cout << "Попробовать еще раз? Нажмите 'Д' или 'Н'";
		char Answer = GetKey();
		if (Answer == 'н')
			break;
		cout << endl << "Введите ФИО для удаления: ";
		getline(cin, SearchData);
	}
	MainMenu();
}*/