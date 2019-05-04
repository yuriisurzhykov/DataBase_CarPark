#include "header.h"

bool IsLetter(const char sym) {
	int KeyCode = sym;
	if (KeyCode >= 65 && KeyCode < 91)
		return true;
	else if (KeyCode == 32)
		return true;
	else if (KeyCode >= 97 && KeyCode < 123)
		return true;
	else if (KeyCode == (127 - 168))
		return true;
	else if (KeyCode == (127 - 184))
		return true;
	else if (KeyCode <= -1 && KeyCode > -65)
		return true;
	else if (sym == '.')
		return true;
	else return false;
}

int CheckInt(string str) {
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (IsDigit(str[i]))
			continue;
		else return 0;
	}
	return 1;
}

int CheckStringToNumb(string str)
{
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (!IsLetter(str[i]))
			return 0;
		else continue;
	}
	return 1;
}

bool CheckExistence(AUTOPARK_Tree* Branch, AUTOPARK_Tree Data) {
	if (Branch == NULL) return false;
	else {
		if (Data.Name > Branch->Name)
			return CheckExistence(Branch->Right, Data);
		else if(Data.Name < Branch->Name)
			return CheckExistence(Branch->Left, Data);
		else {
			if (Branch->AmountValutation == Data.AmountValutation
				&& Branch->NumberBus == Data.NumberBus
				&& Branch->NumberWay == Data.NumberWay
				&& Branch->Presense == Data.Presense)
				return true;
		}
	}
}

bool IsDigit(const char sym)
{
	int KeyCode = sym;
	if (KeyCode >= 48 && KeyCode < 58)
		return true;
	else return false;
}

int StringToInt(string str) {
	int Value = 0;
	int pow;
	int size = str.size();
	if (size == 1 && str[0] == '-') return -1;
	else if (size == 1 && str[0] == '0') return 0;
	for (int i = size - 1, pow = 1; i >= 0; i--, pow *= 10) {
		Value += (str[i] - '0') * pow;
	}
	return Value;
}

int ToLower(const char sym) {
	if (sym < 0) {
		if (sym >= -128 && sym < -112)
			return sym + 32;
		else if (sym >= -112 && sym <= -97)
			return sym + 80;
		else if (sym == -16)
			return -15;
		else return sym;
	}
	else {
		if (sym >= 65 && sym <= 90)
			return sym + 32;
		else return sym;
	}
}

char GetKey()
{
	char Answer;
	Answer = _getch();
	switch (Answer) {
	case 'д':
		return Answer;
		break;
	case 'н':
		return Answer;
		break;
	case 'l':
		Answer = 'д';
		return Answer;
		break;
	case 'y':
		Answer = 'н';
		return Answer;
		break;
	default:
		cout << endl << "Нажмите 'Д' или 'Н' !";
		GetKey();
	}
}