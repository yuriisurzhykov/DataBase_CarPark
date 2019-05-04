#include "header.h"

void StartProgram() {
	if (!ReadFromFile("BASE.txt")) {
		if (!ReadFromFile("BASE_old.txt")) {
			cout << "\t\t\t\t\t������ � �������� ���� ���!" << endl;
			ifstream file("BUFER_DATA.txt");
			if (file.is_open()) {
				file.close();
				cout << "\t\t\t� ��� ���� ������������� ������ ����� ����������� ����������." << endl;
				cout << "\t\t\t������ �� ������������ ������?  ������� '�' ��� '�'" << endl;
				char Answer = GetKey();
				if (Answer == '�')
					if (ReadFromFile("BUFER_DATA.txt"))
						cout << "\t\t\t������ �� ������ ������� ��������!" << endl;
			}
			else {
				cout << "\t\t\t��� ��� ������ ������ ���������. ����� ����������!" << endl;
			}
			Sleep(2000);
			system("cls");
		}
		else {
			cout << "\t\t\t\t\t���������� ���������� ���� ���������." << endl << "\t\t\t\t\t������ �������� �� ��������� �����!" << endl;
			ifstream file("BUFER_DATA.txt");
			if (file.is_open()) {
				file.close();
				cout << "\t\t\t\t\t� ��� ���� ������������� ������ ����� ����������� ����������." << endl;
				cout << "\t\t\t\t\t������ �� ������������ ������?  ������� '�' ��� '�'" << endl;
				char Answer = GetKey();
				if (Answer == '�')
					if (ReadFromFile("BUFER_DATA.txt"))
						cout << "\t\t\t\t\t\t\t\t������ �� ������ ������� ��������!" << endl;
			}
			Sleep(2000);
			system("cls");
		}
	}
	else {
		remove("BASE_old.txt");
		rename("BASE.txt", "BASE_old.txt");
	}
}

int ReadFromFile(string FileName)
{
	AUTOPARK_Tree* Data;
	Data = new AUTOPARK_Tree;
	ifstream file(FileName);
	if (!file.is_open()) {
		return 0;
	}
	if (file.eof()) {
		file.close();
		return 1;
	}
	while (file.peek() != EOF) {
		file.ignore();
		getline(file, Data->Name);
		file >> Data->AmountValutation;
		file >> Data->NumberBus;
		file >> Data->NumberWay;
		file >> Data->Presense;
		PushData(&Root, NULL, *Data);
	}
	file.close();
	delete Data;
	return 1;
}

void WriteBuferData(AUTOPARK_Tree *Data, string FileName) {
	ofstream file(FileName, ios::app);
	if (!file.is_open())
		return;
	else {
		file << endl << Data->Name << endl;
		file << Data->AmountValutation << endl;
		file << Data->NumberBus << endl;
		file << Data->NumberWay << endl;
		file << Data->Presense;
		file.close();
		return;
	}
}

void WriteInFile(AUTOPARK_Tree* Data, string FileName)
{
	if (Data == NULL) return;
	else {
		ofstream file(FileName, ios::app);
		file << endl << Data->Name << endl;
		file << Data->AmountValutation << endl;
		file << Data->NumberBus << endl;
		file << Data->NumberWay << endl;
		file << Data->Presense;
		file.close();
		WriteInFile(Data->Left, FileName);
		WriteInFile(Data->Right, FileName);
	}
}