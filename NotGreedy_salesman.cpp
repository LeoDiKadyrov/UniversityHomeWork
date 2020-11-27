#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#pragma

class Salesman
{
    int** mas;
    int* minWay, *per;
    int nCities, nTrips = 0, weightOfTrip = 0;
    double thatTrip = 1e10;
public:
    void Enter();
    void DisplayTrap();
    void FillArray();
    void DisplayMatrix();
    void Algorithm();
    void DoArray();
    void Swap(int* a, int* b);
    void SortArray(int* a, int bib, int n);
    void DisplayEnd();

};

void Salesman::Enter() {
    std::cin >> nCities; 
    mas = new int* [nCities]; 
    for (int i = 0; i < nCities; i++)
    {
        mas[i] = new int[nCities];
    }
}

void Salesman::FillArray() {
    srand(time(NULL));
    for (int i = 0; i < nCities; ++i) {
        for (int j = 0; j < nCities; ++j) {
            mas[i][j] = rand() % 100;
        }
        mas[i][i] = 0;
    }
}

void Salesman::DisplayMatrix() {
    for (int i = 0; i < nCities; ++i) {
        for (int j = 0; j < nCities; ++j)
            std::cout << mas[i][j] << "\t";
        std::cout << std::endl;
    }
}

void Salesman::DoArray() {
    int thatCity;
    int i, j;
    std::cout << "С какого города начнем?: ";
    while (!(std::cin >> thatCity) || (thatCity > nCities || thatCity <= 0)) {
        std::cin.clear(); //  чтобы можно было продолжить ввод
        while (std::cin.get() != '\n') continue; // мусор
        std::cout << "Введите число между 1 и " << nCities << std::endl;
    }

    per = new int[nCities];
    minWay = new int[nCities];
    per[0] = thatCity;

    for (i = 1; i < nCities; i++) {
        if (i <= thatCity) {
            per[i] = i - 1;
        }
        else { per[i] = i; }
    }
}

void Salesman::Algorithm() {
    bool flag = true, flag1 = false;
    int i, j;
    while (flag != 0)
    {
        flag = false;
        flag1 = true;

        DisplayTrap();

        for (i = nCities - 2; i > 0 && flag1; i--) {
            if (per[i] < per[i + 1]) {
                for (j = nCities - 1; (j > i&& flag1); j--) {
                    if (per[j] > per[i]) {
                        Swap(&per[i], &per[j]);
                        SortArray(per, i + 1, nCities);
                        flag1 = false;
                    };
                }
                flag = true;
            }
            else flag = false;
        }
        weightOfTrip = 0;
    }
}

void Salesman::Swap(int* a, int* b) { // замена а на б
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Salesman::SortArray(int *arr, int bib, int n) { // сортировка пузырьком
    int i, j; 
    for (i = bib, j = n - 1; i < j; i++, j--) {
        Swap(&arr[i], &arr[j]);
    } 
}

void Salesman::DisplayTrap() {
    for (int i = 0; i < nCities; i++) {
        weightOfTrip += mas[per[i]][per[(i + 1) % nCities]];
    }
   
    if (weightOfTrip < thatTrip) // thatTrip изначально = 10e5
    {
        thatTrip = weightOfTrip;
        for (int i = 0; i < nCities; i++) {
            minWay[i] = per[i];
        }
    }

    for (int i = 0; i < nCities; ++i) {
        std::cout << per[i] << " ---> ";
    }
    std::cout << per[0] << std::endl;
    std::cout << "\nСумма пути: " << thatTrip << "\n__\n";

    weightOfTrip = 0; // обнуляем
    ++nTrips;
}

void Salesman::DisplayEnd() 
{
    std::cout << "\nМинимальный путь: ";

    for (int i = 0; i < nCities; i++) {
        std::cout << minWay[i] + 1 << " ---> ";
    }

    std::cout << minWay[0] + 1 << "\nМинимальная сумма пути: " << thatTrip << std::endl;
    std::cout << "Всего последовательностей: " << nTrips << std::endl;

    for (int i = 0; i < nCities; i++) {
        delete[] mas[i];
    }

    delete[] mas;

    delete[] per;
    delete[] minWay;
}

int main() {
    setlocale(LC_ALL, "russian");
    Salesman firstTrap;
    std::cout << "Сколько городов всего:  _\b";
    firstTrap.Enter();
    firstTrap.FillArray();
    firstTrap.DisplayMatrix();
    firstTrap.DoArray();
    firstTrap.Algorithm();
    //firstTrap.Greedy();
    firstTrap.DisplayEnd();
    return 0;
}