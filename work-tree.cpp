#include "header.h"

void InputData() {
	system("cls");
	AUTOPARK_Tree* Data = new AUTOPARK_Tree;
	cout << endl << "\t\t���� ������" << endl << endl;
	cout << "������� ��� ��������: ";
	getline(cin, Data->Name);
	while (!CheckStringToNumb(Data->Name)) {
		cout << endl << "� ����� �� ����� ���� ���� ��� ��������!" << endl;
		cout << "������� ��� ��������: ";
		getline(cin, Data->Name);
	}
	cout << "������� ����������� ��������� ��������: ";
	string Temp;
	getline(cin, Temp);
	while (!CheckInt(Temp)) {
		cout << endl << "������� ���������� ��������!" << endl;
		cout << "������� ����������� ��������� ��������: ";
		getline(cin, Temp);
	}
	Data->AmountValutation = StringToInt(Temp);
	cout << "������� ����� ��������: ";
	getline(cin, Data->NumberBus);
	while (Data->NumberBus.size() > 8) {
		cout << endl << "������������ ���������� �������� 8!" << endl;
		cout << "������� ����� ��������: ";
		getline(cin, Data->NumberBus);
	}
	cout << "������� ����� ��������: ";
	getline(cin, Temp);
	while (!CheckInt(Temp) || Temp[0] < (1 - '0')) {
		cout << endl << "������� ���������� ��������!" << endl;
		cout << "������� ����� ��������: ";
		getline(cin, Temp);
	}
	Data->NumberWay = StringToInt(Temp);
	cout << "������� ���������� � �����?  ������� '�' ��� '�'" << endl;
	Data->Presense = GetKey();
	if (!CheckExistence(Root, *Data)) {
		WriteBuferData(Data, "BUFER_DATA.txt");
		if (!PushData(&Root, NULL, *Data)) {
			cout << "��������� ������ ��� ���������� ������!" << endl;
			delete Data;
		}
		else {
			cout << "������ ������� ����c���!" << endl;
			delete Data;
		}
	}
	else {
		cout << endl << "������ ������ ��� ������������!" << endl;
	}
	cout << "������ ��� ������ ������? ������� � ��� �";
	char Answer = GetKey();
	if (Answer == '�') {
		MainMenu();
	}
	else InputData();
}

void HeadTable() {
	Position = 0;
	cout << "\t" << "+----+------------------------------------------+------------------------------------------+" << endl;
	cout << "\t" << "|  � |         ��� ��������       |  ���������� |  ����� ��������  |   �����   | ������� � |" << endl;
	cout << "\t" << "| �/�|                            |  ���������  |                  |  �������� |   �����   |" << endl;
	cout << "\t" << "+----+------------------------------------------+------------------------------------------+" << endl;
}

void ShowData() {
	system("cls");
	cout << "\t\t\t\t\t\t���� ������" << endl;
	HeadTable();
	PrintTree(Root);
	cout << endl << "�������� ���������� ��������" << endl;
	cout << "1. �������� ������." << endl;
	cout << "2. ������� ������." << endl;
	cout << "3. ������������� ������." << endl;
	cout << "0. ��������� � ������� ����." << endl;
	system("pause");
	char Answer = _getch();
	while (Answer < '0' && Answer > '3') {
		cout << "�������� ������� ������!";
		cout << "�������� ���������� �������!";
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
		if (Branch->Presense == '�') cout << "    ��     ";
		else cout << "    ���    ";
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