#include "header.h"

void MainMenu() {
	system("cls");
	cout << "1. �������� ������." << endl;
	cout << "2. ������������� ������." << endl;
	cout << "3. ������� ������." << endl;
	cout << "4. �������� ������." << endl;
	cout << "5. ������ �����������." << endl;
	cout << "0. �����." << endl;
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
	cout << "1. �������� � ���� ������." << endl;
	cout << "2. ������� � ���� ������." << endl;
	cout << "0. ��������� � ������� ����." << endl;
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
	cout << "1. ���������� ������." << endl;
	cout << "2. �������� ������." << endl;
	cout << "3. �������������� ������." << endl;
	cout << "4. ����� ������ �� ������� �����." << endl;
	cout << "5. ������������ ������� ���������." << endl;
	cout << "6. ����� �������� � ���������� ������ ���������." << endl;
	cout << "7. ���������� ������ �� ������ ��������." << endl;
	cout << "8. ����� ������." << endl;
	cout << "0. ��������� �����." << endl;
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
	cout << "������� ��� ��� ��������: ";
	getline(cin, SearchData);
	while (DeleteData(&Root, SearchData) == NULL) {
		cout << "� ���� ��� ������ ��������!";
		cout << "����������� ��� ���? ������� '�' ��� '�'";
		char Answer = GetKey();
		if (Answer == '�')
			break;
		cout << endl << "������� ��� ��� ��������: ";
		getline(cin, SearchData);
	}
	MainMenu();
}*/