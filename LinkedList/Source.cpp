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

	cout << "\n������� ����� ������� ����� �����: " << endl;
	cin >> x;
	p = A->FindKey(x);

	cout << "\n������� ����� ������� �������� ������: " << endl;
	cin >> pos;
	b = A->FindPos(pos);

	if (p != NULL &&  p == b) {
		A->DelAfter(p);
		cout << "��� ����������: " << endl;
		A->PrintList();
	}
	else { cout << "�������� �� ���������: " << endl; }

	cout << "\n������ ������ ��� ����" << endl;

	A->PrintList();

}