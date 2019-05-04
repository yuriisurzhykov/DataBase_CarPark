#include "header.h"

void CorrectData() {
	system("cls");
	AUTOPARK_Tree *CorrectObj = NULL;
	cout << "\t\t\t\tКОРРЕКТИРОВКА ДАННЫХ" << endl;
	HeadTable();
	PrintTree(Root);
	cout << endl << "Введите ФИО для корректировки: ";
	string SearchData;
	getline(cin, SearchData);
	CorrectObj = SearchName(Root, SearchData);
	while (CorrectObj == NULL) {
		cout << "В базе нет такого водителя!" << endl;
		cout << "Повторить попытку? Нажмите Д или Н" << endl;
		char Answer = GetKey();
		if (Answer == 'н') {
			return;
		}
		cout << endl << "Введите ФИО для корректировки: ";
		getline(cin, SearchData);
		CorrectObj = SearchName(Root, SearchData);
	}
	cout << "Выберите поле корректировки" << endl;
	cout << "1. Имя водителя." << endl;
	cout << "2. Количество нарушений водителя." << endl;
	cout << "3. Номер автобуса." << endl;
	cout << "4. Номер маршрута автобуса." << endl;
	cout << "5. Присутствие в парке." << endl;
	cout << "0. Отменить и вернуться назад." << endl;
	char Answer = _getch();
	while (Answer < '0' && Answer > '5') {
		cout << "Нет такого варианта ответа!" << endl;
		cout << "Выберите правильный вариант!" << endl;
		Answer = _getch();
		if (Answer == '0')
			return;
	}
	AUTOPARK_Tree* Temp = new AUTOPARK_Tree; //Объявляем указатель типа структуры, выделяем под него память. Эта память будет использоваться как временное хранилище
	Temp->Name = CorrectObj->Name; //Копируем поля найденого объекта в наше временное хранилище
	Temp->AmountValutation = CorrectObj->AmountValutation;
	Temp->NumberBus = CorrectObj->NumberBus;
	Temp->NumberWay = CorrectObj->NumberWay;
	Temp->Presense = CorrectObj->Presense;

	string TempStr;
	switch (Answer) {
	case '1':
		cout << "Введите новое имя водителя: ";
		getline(cin, Temp->Name);
		while (!CheckStringToNumb(Temp->Name)) {
			cout << "В имени не может быть никаких символов, кроме букв!" << endl;
			cout << "Введите новое имя водителя: ";
			getline(cin, Temp->Name);
		}
		break;
	case '2':
		cout << "Введите количество нарушений водителя: ";
		getline(cin, TempStr);
		while (!CheckInt(TempStr)) {
			cout << endl << "Введите корректное значение! (только цифры)" << endl;
			cout << "Введите количество нарушений водителя: ";
			getline(cin, TempStr);
		}
		Temp->AmountValutation = StringToInt(TempStr);
		break;
	case '3':
		cout << "Введите номер автобуса: ";
		getline(cin, Temp->NumberBus);
		while (Temp->NumberBus.size() > 8) {
			cout << endl << "Максимальное количество символов 8!" << endl;
			cout << "Введите номер автобуса: ";
			getline(cin, Temp->NumberBus);
		}
		break;
	case '4':
		cout << "Введите номер маршрута: ";
		getline(cin, TempStr);
		while (!CheckInt(TempStr) || TempStr[0] < (1 - '0')) {
			cout << endl << "Введите корректное значение!" << endl;
			cout << "Введите номер маршрута: ";
			getline(cin, TempStr);
		}
		Temp->NumberWay = StringToInt(TempStr);
		break;
	case '5':
		cout << "Автобус находиться в парке?  Нажмите 'Д' или 'Н'" << endl;
		Temp->Presense = GetKey();
		break;
	case '0':
		MainMenu();
		break;
	}
	cout << endl << "Вы точно хотите изменить данные о водителе " << CorrectObj->Name << "? Нажмите 'Д' или 'Н'" << endl;
	if ((Answer = GetKey()) == 'н') {
		cout << "Отмена редактирования";
	}
	else {
		cout << "Данные о " << CorrectObj->Name << " успешно изменены!" << endl;
		CorrectObj->Name = Temp->Name;
		CorrectObj->AmountValutation = Temp->AmountValutation;
		CorrectObj->NumberBus = Temp->NumberBus;
		CorrectObj->NumberWay = Temp->NumberWay;
		CorrectObj->Presense = Temp->Presense;
	}
	delete Temp;
	Sleep(800);
	MainMenu();
}
