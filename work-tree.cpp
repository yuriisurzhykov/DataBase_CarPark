#include "header.h"

void InputData() {
	system("cls");
	AUTOPARK_Tree* Data = new AUTOPARK_Tree;
	cout << endl << "\t\tВВОД ДАННЫХ" << endl << endl;
	cout << "Введите имя водителя: ";
	getline(cin, Data->Name);
	while (!CheckStringToNumb(Data->Name)) {
		cout << endl << "В имени не может быть цифр или символов!" << endl;
		cout << "Введите имя водителя: ";
		getline(cin, Data->Name);
	}
	cout << "Введите колличество нарушений водителя: ";
	string Temp;
	getline(cin, Temp);
	while (!CheckInt(Temp)) {
		cout << endl << "Введите корректное значение!" << endl;
		cout << "Введите колличество нарушений водителя: ";
		getline(cin, Temp);
	}
	Data->AmountValutation = StringToInt(Temp);
	cout << "Введите номер автобуса: ";
	getline(cin, Data->NumberBus);
	while (Data->NumberBus.size() > 8) {
		cout << endl << "Максимальное количество символов 8!" << endl;
		cout << "Введите номер автобуса: ";
		getline(cin, Data->NumberBus);
	}
	cout << "Введите номер маршрута: ";
	getline(cin, Temp);
	while (!CheckInt(Temp) || Temp[0] < (1 - '0')) {
		cout << endl << "Введите корректное значение!" << endl;
		cout << "Введите номер маршрута: ";
		getline(cin, Temp);
	}
	Data->NumberWay = StringToInt(Temp);
	cout << "Автобус находиться в парке?  Нажмите 'Д' или 'Н'" << endl;
	Data->Presense = GetKey();
	if (!CheckExistence(Root, *Data)) {
		WriteBuferData(Data, "BUFER_DATA.txt");
		if (!PushData(&Root, NULL, *Data)) {
			cout << "Произошла ошибка при добавлении данных!" << endl;
			delete Data;
		}
		else {
			cout << "Данные успешно занеcены!" << endl;
			delete Data;
		}
	}
	else {
		cout << endl << "Данная запись уже присутствует!" << endl;
	}
	cout << "Хотите еще ввести данные? Нажмите Д или Н";
	char Answer = GetKey();
	if (Answer == 'н') {
		MainMenu();
	}
	else InputData();
}

void HeadTable() {
	Position = 0;
	cout << "\t" << "+----+------------------------------------------+------------------------------------------+" << endl;
	cout << "\t" << "|  № |         ФИО Водителя       |  Количество |  Номер автобуса  |   Номер   | Наличие в |" << endl;
	cout << "\t" << "| п/п|                            |  нарушений  |                  |  маршрута |   парке   |" << endl;
	cout << "\t" << "+----+------------------------------------------+------------------------------------------+" << endl;
}

void ShowData() {
	system("cls");
	cout << "\t\t\t\t\t\tБАЗА ДАННЫХ" << endl;
	HeadTable();
	PrintTree(Root);
	cout << endl << "ВЫБЕРИТЕ ДАЛЬНЕЙШЕЕ ДЕЙСТВИЕ" << endl;
	cout << "1. Добавить данные." << endl;
	cout << "2. Удалить данные." << endl;
	cout << "3. Редактировать данные." << endl;
	cout << "0. Вернуться в главное меню." << endl;
	system("pause");
	char Answer = _getch();
	while (Answer < '0' && Answer > '3') {
		cout << "Неверный вариант ответа!";
		cout << "Выберите правильный вариант!";
		char Answer = _getch();
	}
	switch (Answer) {
	case '1':
		InputData();
		break;
	/*case '2':
		DeleteDataMain();
		break;*/
	case '3':
		CorrectData();
		break;
	case '0':
		MainMenu();
		break;
	}
	system("pause");
}

void PrintTreeAsTree(AUTOPARK_Tree *Branch) {
	
}

void PrintTree(AUTOPARK_Tree *Branch) {
	if (Branch == NULL) return;
	else {
		PrintTree(Branch->Left);
		cout << "\t" << "|" << setw(4) << right << ++Position;
		cout << "|";
		cout << setw(27) << left << Branch->Name << " | ";
		cout << setw(12) << right << Branch->AmountValutation;
		cout << "|";
		cout << setw(18) << right << Branch->NumberBus;
		cout << "|";
		cout << setw(11) << right << Branch->NumberWay;
		cout << "|";
		if (Branch->Presense == 'д') cout << "    да     ";
		else cout << "    нет    ";
		cout << "|" << endl;
		cout << "\t" << "+----+------------------------------------------+------------------------------------------+" << endl;
		PrintTree(Branch->Right);
	}
}

int PushData(AUTOPARK_Tree** Branch, AUTOPARK_Tree* ParentFunc, AUTOPARK_Tree Data) {
	if ((*Branch) == NULL) {
		(*Branch) = new AUTOPARK_Tree;
		(*Branch)->Name = Data.Name;
		(*Branch)->AmountValutation = Data.AmountValutation;
		(*Branch)->NumberBus = Data.NumberBus;
		(*Branch)->NumberWay = Data.NumberWay; 
		(*Branch)->Presense = Data.Presense;
		(*Branch)->Left = (*Branch)->Right = NULL;
		(*Branch)->Parent = ParentFunc;
		return 1;
	}
	else {
		//int compare = StringCompare(Data.Name, (*Branch)->Name);
		if (Data.Name >= (*Branch)->Name)
			PushData(&(*Branch)->Right, (*Branch), Data);
		else 
			PushData(&(*Branch)->Left, (*Branch), Data);
	}
}


void DemageTree(AUTOPARK_Tree* Branch) {
	if (Branch != NULL) {
		DemageTree(Branch->Left);
		DemageTree(Branch->Right);
		delete Branch;
		Branch = NULL;
	}
}