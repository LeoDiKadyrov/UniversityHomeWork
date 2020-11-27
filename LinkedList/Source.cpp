#include "Header.h"

int main()

{
	setlocale(LC_ALL, "russian");
	int x, pos;
	list* A;
	node* p;
	node* b;
	A = new list;
	A->FormRand(10);
	A->PrintList();

	cout << "\nВведите какой элемент хотим найти: " << endl;
	cin >> x;
	p = A->FindKey(x);

	cout << "\nВведите номер позиции элемента списка: " << endl;
	cin >> pos;
	b = A->FindPos(pos);

	if (p != NULL &&  p == b) {
		A->DelAfter(p);
		cout << "Что получилось: " << endl;
		A->PrintList();
	}
	else { cout << "Элементы не совпадают: " << endl; }

	cout << "\nВывожу список как есть" << endl;

	A->PrintList();

}