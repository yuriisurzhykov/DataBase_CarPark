#include "header.h"

void CorrectData() {
	system("cls");
	AUTOPARK_Tree *CorrectObj = NULL;
	cout << "\t\t\t\t������������� ������" << endl;
	HeadTable();
	PrintTree(Root);
	cout << endl << "������� ��� ��� �������������: ";
	string SearchData;
	getline(cin, SearchData);
	CorrectObj = SearchName(Root, SearchData);
	while (CorrectObj == NULL) {
		cout << "� ���� ��� ������ ��������!" << endl;
		cout << "��������� �������? ������� � ��� �" << endl;
		char Answer = GetKey();
		if (Answer == '�') {
			return;
		}
		cout << endl << "������� ��� ��� �������������: ";
		getline(cin, SearchData);
		CorrectObj = SearchName(Root, SearchData);
	}
	cout << "�������� ���� �������������" << endl;
	cout << "1. ��� ��������." << endl;
	cout << "2. ���������� ��������� ��������." << endl;
	cout << "3. ����� ��������." << endl;
	cout << "4. ����� �������� ��������." << endl;
	cout << "5. ����������� � �����." << endl;
	cout << "0. �������� � ��������� �����." << endl;
	char Answer = _getch();
	while (Answer < '0' && Answer > '5') {
		cout << "��� ������ �������� ������!" << endl;
		cout << "�������� ���������� �������!" << endl;
		Answer = _getch();
		if (Answer == '0')
			return;
	}
	AUTOPARK_Tree* Temp = new AUTOPARK_Tree; //��������� ��������� ���� ���������, �������� ��� ���� ������. ��� ������ ����� �������������� ��� ��������� ���������
	Temp->Name = CorrectObj->Name; //�������� ���� ��������� ������� � ���� ��������� ���������
	Temp->AmountValutation = CorrectObj->AmountValutation;
	Temp->NumberBus = CorrectObj->NumberBus;
	Temp->NumberWay = CorrectObj->NumberWay;
	Temp->Presense = CorrectObj->Presense;

	string TempStr;
	switch (Answer) {
	case '1':
		cout << "������� ����� ��� ��������: ";
		getline(cin, Temp->Name);
		while (!CheckStringToNumb(Temp->Name)) {
			cout << "� ����� �� ����� ���� ������� ��������, ����� ����!" << endl;
			cout << "������� ����� ��� ��������: ";
			getline(cin, Temp->Name);
		}
		break;
	case '2':
		cout << "������� ���������� ��������� ��������: ";
		getline(cin, TempStr);
		while (!CheckInt(TempStr)) {
			cout << endl << "������� ���������� ��������! (������ �����)" << endl;
			cout << "������� ���������� ��������� ��������: ";
			getline(cin, TempStr);
		}
		Temp->AmountValutation = StringToInt(TempStr);
		break;
	case '3':
		cout << "������� ����� ��������: ";
		getline(cin, Temp->NumberBus);
		while (Temp->NumberBus.size() > 8) {
			cout << endl << "������������ ���������� �������� 8!" << endl;
			cout << "������� ����� ��������: ";
			getline(cin, Temp->NumberBus);
		}
		break;
	case '4':
		cout << "������� ����� ��������: ";
		getline(cin, TempStr);
		while (!CheckInt(TempStr) || TempStr[0] < (1 - '0')) {
			cout << endl << "������� ���������� ��������!" << endl;
			cout << "������� ����� ��������: ";
			getline(cin, TempStr);
		}
		Temp->NumberWay = StringToInt(TempStr);
		break;
	case '5':
		cout << "������� ���������� � �����?  ������� '�' ��� '�'" << endl;
		Temp->Presense = GetKey();
		break;
	case '0':
		MainMenu();
		break;
	}
	cout << endl << "�� ����� ������ �������� ������ � �������� " << CorrectObj->Name << "? ������� '�' ��� '�'" << endl;
	if ((Answer = GetKey()) == '�') {
		cout << "������ ��������������";
	}
	else {
		cout << "������ � " << CorrectObj->Name << " ������� ��������!" << endl;
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
