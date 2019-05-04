#include "header.h"

AUTOPARK_Tree* SearchName(AUTOPARK_Tree* Branch, string SearchData) {
	if (Branch == NULL)
		return Branch;
	else {
		if (Branch->Name == SearchData)
			return Branch;
		else if (SearchData > Branch->Name)
			return SearchName(Branch->Right, SearchData);
		else return SearchName(Branch->Left, SearchData);
	}
}

void SearchForLetter() {
	system("cls");
	int *AmountFindElem = new int(0);
	cout << "Введите букву для поиска водителя: ";
	string SearchChar;
	getline(cin, SearchChar);
	while (SearchChar.size() > 1) {
		cout << "Введите только ОДИН символ!" << endl;
		getline(cin, SearchChar);
	}
	system("cls");
	HeadTable();
	SearchDriver(Root, SearchChar[0], AmountFindElem);
	cout << AmountFindElem << endl;
	if (*AmountFindElem == 0) {
		cout << "\tВодителей на букву " << SearchChar[0] << " нет!" << endl;
	}
	cout << "\tПовторить поиск? Нажмите 'Д' или 'Н'" << endl;
	char* Answer = new char(GetKey());
	if (*Answer == 'н') {
		delete Answer;
		MainMenu();
	}
	else {
		delete Answer;
		SearchForLetter();
	}
}

void SearchDriver(AUTOPARK_Tree* Branch, char SearchChar, int* Counter) {
	if (Branch == NULL) return;
	else {
		if (Branch->Name[0] == SearchChar) {
			*Counter++;
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
		}
		SearchDriver(Branch->Left, SearchChar, Counter);
		SearchDriver(Branch->Right, SearchChar, Counter);
	}
}

void ShowMaxValutation() {
	system("cls");
	AUTOPARK_Tree* MaxValutDriver = NULL;
	int MaxValutInt = 0;
	SearchMaxValutation(Root, &MaxValutDriver, MaxValutInt);
	if (Root == NULL) {
		cout << "Данных в базе нет!" << endl;
		cout << "Повторите попытку позже.";
		Sleep(800);
		MainMenu();
	}
	else {
		HeadTable();
		cout << "\t" << "|" << setw(4) << right << ++Position;
		cout << "|";
		cout << setw(27) << left << MaxValutDriver->Name << " | ";
		cout << setw(12) << right << MaxValutDriver->AmountValutation;
		cout << "|";
		cout << setw(18) << right << MaxValutDriver->NumberBus;
		cout << "|";
		cout << setw(11) << right << MaxValutDriver->NumberWay;
		cout << "|";
		if (MaxValutDriver->Presense == 'д') cout << "    да     ";
		else cout << "    нет    ";
		cout << "|" << endl;
		cout << "\t" << "+----+------------------------------------------+------------------------------------------+" << endl;
	}
	system("pause");
	MainMenu();
}

AUTOPARK_Tree* SearchMaxValutation(AUTOPARK_Tree* Branch, AUTOPARK_Tree** MaxValutPtr, int MaxValutInt) {
	if (Branch == NULL)
		return Branch;
	else {
		SearchMaxValutation(Branch->Left, &(*MaxValutPtr), MaxValutInt);
		SearchMaxValutation(Branch->Right, &(*MaxValutPtr), MaxValutInt);
		if (MaxValutInt < Branch->AmountValutation) {
			MaxValutInt = Branch->AmountValutation;
			cout << MaxValutInt << endl;
			(*MaxValutPtr) = NULL;
			(*MaxValutPtr) = Branch;
		}
	}
}