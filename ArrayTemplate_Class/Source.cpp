#include "Header.h"
#include <time.h>

int main() {
    setlocale(LC_ALL, "Russian");

    Array <char> mas1;
    mas1.Scan(5);
    mas1.Print();
    cout << "__________________________\n";

    cout << "������� mas2 ��������������� ��� ��� mas1" << endl;
    Array <char> mas2 = mas1;
    cout << mas2;
    cout << "\n__________________________\n";

    cout << "������� mas1 � mas2 �����?: ";
    if (mas1 == mas2) cout << "Da";
    else cout << "Net";
    cout << "\n__________________________\n";

    mas1 += '6'; // '6'
    cout << "��������� 6 � ����� �������" << endl;
    cout << mas1;
    cout << "\n__________________________\n";

    cout << "������� mas1 � mas2 �����?: ";
    if (mas1 == mas2) cout << "Da";
    else cout << "Net";
    cout << "\n__________________________\n";

    cout << "������� mas3 ����� ���������� 7 � ����� mas1" << endl;
    Array <char> mas3 = mas1 + '7'; // '7'
    cout << mas3;
    cout << "\n__________________________\n";

    cout << "������� ������ ������� �� mas3" << endl;
    mas3.DelPosEq(0);
    cout << mas3;
    cout << "\n__________________________\n";

    cout << "������� mas4 ������ �� mas3 ��������� �������" << endl;
    Array <char> mas4 = mas3.DelPosNew(5);
    cout << mas4;
    cout << "\n__________________________\n";
    
    mas1 -= '1'; // '1'
    cout << "������� ������� �� mas1" << endl;
    cout << "������� mas1 � mas4 �����?: ";
    if (mas1 == mas4) cout << "Da";
    else cout << "Net";
    cout << "\n__________________________\n";


    int n;
    char* b; // char
    cout << "\n������� n: ";
    cin >> n;
    b = new char[n]; // char

    cout << "��������� ������ b �� n ��������� �����" << endl;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        b[i] = rand() % 10 + 97; // + 97 for char
    }
    Array <char> mas5(b, n);
    cout << mas5;
    cout << "\n__________________________\n";

    int max, min;
    max = mas5.Max();
    min = mas5.Min();
    cout << "������������ �������: mas5[" << max << "] = " << mas5[max] << "\n" << "����������� �������: mas5[" << min << "] = " << mas5[min];
    cout << "\n__________________________\n";

    mas5.Sorting();
    cout << "��������������� ������: ";
    cout << mas5;
    cout << "\n__________________________\n";

    cout << "������� mas6 ����� ���������� mas1 � mas5" << endl;
    Array <char> mas6 = mas1 + mas5;
    cout << mas6;
    cout << "\n__________________________\n";

    cout << "������� mas7 �� 4 ���������" << endl;
    Array <char> mas7(4);
    cin >> mas7;
    cout << mas7;
    cout << "\n__________________________\n";

    int index_7;
    cout << "�������� ������ �� 1 � mas7" << endl;
    index_7 = mas7.FindKey('1'); // '1'
    cout << index_7 << '\n';
    cout << "�������� ������ �� 10 � mas7" << endl;
    index_7 = mas7.FindKey('f'); // 'f'
    cout << index_7;
    cout << "\n__________________________\n";


    mas4 += mas7;
    cout << "�������� mas4 ������� � ���� mas7" << endl;
    cout << mas4 << "\n������� mas4 � mas6 �����?: ";
    if (mas4 == mas6) cout << "Da";
    else cout << "Net";
    cout << "\n_____________________________________\n";

    mas4 = mas6;
    cout << "����������� mas6 � mas4" << endl;
    cout << mas4;
    cout << "\n_____________________________________\n";

    return 0;
}