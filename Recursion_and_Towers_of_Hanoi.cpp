#include <iostream>
#include "Header.h"

using namespace std;

// Прототипы функций
void HanOut(Stack st[], int I, int II, int III, int count);
int HanTower(Stack st[], int I, int II, int III, int n, int count);

int main() {
	setlocale(LC_ALL, "russian");
	Stack st[3];
	int n, j, count = 0;
	cout << "Введите количество золотых дисков: ";
	cin >> n;
	cout << "Заполняем стэк: ";
	for (j = n; j > 0; j--) {
		cout << j << " ";
		st[0].Push(j);
	}
	cout << "\n";
	HanTower(st, 0, 1, 2, n, count);
	cout << "Ханойская башня построена";
}

void HanOut(Stack st[], int I, int II, int III, int count) {

	cout << count << ") Убираем диск с " << I + 1 << " и перекладываем на " << II + 1 << ": \n1-ая пирамидка: ";
	st[0].Output();
	cout << "\n2-ая пирамидка: ";
	st[1].Output();
	cout << "\n3-ая пирамидка: ";
	st[2].Output();
	cout << "\n____________________________\n";
}

int HanTower(Stack st[], int I, int II, int III, int n, int count) {
	int k;

	if (n == 1) {

		k = st[I].Pop();

		st[II].Push(k);


		count++;
		HanOut(st, I, II, III, count);
		return count;
	}
	else {
		count = HanTower(st, I, III, II, n - 1, count);
		count = HanTower(st, I, II, III, 1, count);
		count = HanTower(st, III, II, I, n - 1, count);
	}
}