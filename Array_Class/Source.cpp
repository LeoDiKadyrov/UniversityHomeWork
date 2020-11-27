#include "Header.h"
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "russian");
    Array mas1;
    mas1.Scan(5);
    mas1.Print();
    cout << "\n_____________________________________\n";

    Array mas2(mas1);
    cout << "������� mas2 ��������������� ��� ��� mas1" << endl;
    cout << mas2;
    cout << "\n_____________________________________\n";

    cout << "������� mas1 � mas2 �����?: ";
    if (mas1 == mas2) cout << "��";
    else cout << "���";
    cout << "\n_____________________________________\n";

    mas1 += 6;
    cout << "��������� 6 � ����� �������" << endl;
    cout << mas1;
    cout << "\n_____________________________________\n";

    cout << "������� mas1 � mas2 �����?: ";
    if (mas1 == mas2) cout << "��";
    else cout << "���";
    cout << "\n_____________________________________\n";

    Array mas3 = mas1 + 7;
    cout << "������� mas3 ����� ���������� 7 � ����� mas1" << endl;
    cout << mas3;
    cout << "\n_____________________________________\n";

    mas3.DelPosEq(0);
    cout << "������� ������ ������� �� mas3" << endl;
    cout << mas3;
    cout << "\n_____________________________________\n";

    Array mas4 = mas3.DelPosNew(5);
    cout << "������� mas4 ������ �� mas3 ��������� �������" << endl;
    cout << mas4;
    cout << "\n_____________________________________\n";

    mas1 -= 1;
    cout << "������� ������� �� mas1" << endl;
    cout << "������� mas1 � mas4 �����?: ";
    if (mas1 == mas4) cout << "��";
    else cout << "���";
    cout << "\n_____________________________________\n";

    int n, * b;
    cout << "������� n: ";
    cin >> n;
    b = new int[n];
    for (int i = 0; i < n; i++) {
        b[i] = rand() % 10;
    }
    Array mas5(b, n);
    cout << "��������� ������ b �� n ��������� �����" << endl;
    cout << mas5;
    cout << "\n_____________________________________\n";

    int max, min;
    max = mas5.Max();
    min = mas5.Min();
    cout << "Max �������: mas5[" << max << "] = " << mas5[max] << " Min �������: mas5[" << min << "] = " << mas5[min];
    cout << "\n_____________________________________\n";

    mas5.Sorting();
    cout << "��������������� ������: ";
    cout << mas5;
    cout << "\n_____________________________________\n";

    Array mas6 = mas1 + mas5;
    cout << "������� mas6 ����� ���������� mas1 � mas5" << endl;
    cout << mas6;
    cout << "\n_____________________________________\n";

    Array mas7(4);
    cout << "������� mas7 �� 4 ���������" << endl;
    cin >> mas7;
    cout << mas7;
    cout << "\n_____________________________________\n";

    int index_7;
    index_7 = mas7.FindKey(1);
    cout << "�������� ������ �� 1 � mas7" << endl;
    cout << index_7 << '\n';
    index_7 = mas7.FindKey(10);
    cout << "�������� ������ �� 10 � mas7" << endl;
    cout << index_7;
    cout << "\n_____________________________________\n";

    mas4 += mas7;
    cout << "�������� mas4 ������� � ���� mas7" << endl;
    cout << mas4 << "\n������� mas4 � mas6 �����?: ";
    if (mas4 == mas6) cout << "��";
    else cout << "���";
    cout << "\n_____________________________________\n";

    mas4 = mas6;
    cout << "����������� mas6 � mas4" << endl;
    cout << mas4;
    cout << "\n_____________________________________\n";
    return 0;
}
