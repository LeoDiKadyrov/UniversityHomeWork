#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <array>
#include <stdio.h>

using namespace std;

void Greedy(int** mas, int n);
void PrintMatrix(int** a, int n);

int main() {
    setlocale(LC_ALL, "russian");
    int** mas, nCities, i, j, thatCity;

    cout << "������� ���������� �������: ";
    cin >> nCities;
    mas = new int* [nCities];

    for (i = 0; i < nCities; i++) {
        mas[i] = new int[nCities];
    }
    srand(time(NULL));
    for (i = 0; i < nCities; i++) {
        for (j = 0; j < nCities; j++) {
            if (i == j) mas[i][j] = 0;
            else mas[i][j] = rand() % 10 + 1;
        }
    }

    cout << "\n�������� �����: ";
    cin >> thatCity;

    cout << "\n������� ����������: \n";
    PrintMatrix(mas, nCities);
    
    Greedy(mas, nCities);
   
    for (i = 0; i < nCities; i++) {
        delete[] mas[i];
    }

    delete[] mas;
    return 0;
};

void Greedy(int** mas, int n) { //����c�������� �����
    clock_t start_time = clock();
    int weightOfTrip = 0, * minWay, minPoint, minCity, bib = 0;

    minWay = new int[n + 1]; //��������� ������ ��� ������
    minWay[0] = 0;
    int i = 0;

    while (bib < n) {
        minCity = 1000;
        minPoint = n;
        bib++;

        for (int j = 0; j < n; j++) { //����� �������� ������
            if (mas[i][j] > 0 && mas[i][j] < minCity) {
                minCity = mas[i][j];
                minPoint = j;
            }
        }

        for (int t = 0; t < n; t++) { //�������� ������ � �������
            mas[i][t] = 0;
            mas[t][minPoint] = 0;
        }

        if (bib < n - 1) { //������� ��������� ��������
            mas[minPoint][0] = 0;
        }

        minWay[bib] = minPoint;
        i = minPoint;
        weightOfTrip += minCity;
        cout << endl;
        cout << weightOfTrip << endl;
        PrintMatrix(mas, n);
    }
    clock_t end_time = clock();
    cout << "����������� ����: \n";

    for (i = 0; i < n; i++) {
        cout << minWay[i] + 1 << " -> ";
    }

    cout << minWay[0] + 1 << "\n����������� �����: " << weightOfTrip << endl;
    double total = (end_time - start_time);
    cout << "����� ������: " << total / 1000 << " s. " << total << " ms." << endl;
    delete[] minWay; //������� ������ ��� �������
}

void PrintMatrix(int** a, int n) //����� �������
{
    int i, j;
    for (i = 0; i < n; i++, puts("\n"))
        for (j = 0; j < n; j++)
            printf("%6d", a[i][j]);
}