#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

// Прототипы функции
void printArray(int* arr, int n);
void shellSort(int* a, int n);
void enterArray(int* arr, int n);

int main()
{
    setlocale(LC_ALL, "russian");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Массив до сортировки: ";
    enterArray(arr, n);
    unsigned int start_time = clock();
    printArray(arr, n);
    shellSort(arr, n);
    cout << "\nМассив после сортировки: ";
    printArray(arr, n);
    unsigned int end_time = clock();
    cout << endl;
    unsigned int search_time = end_time - start_time;
    cout << "Время сортировки с выводом: ";
    cout << search_time << " мс" << endl;

    delete[] arr;
    return 0;
}

void shellSort(int* a, int n) {
    int* step, i, j, t, k, temp, s, b, m;
    m = n / 2;
    step = new int[m];
    step[m - 1] = 0;
    i = -1;
    do {
        i++;
        if (i % 2 == 0) {
            step[i] = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
        }
        else {
            step[i] = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
        }
    } while (step[i] < n);
    t = i - 1;
    for (i = 0; i <= t; i++) {
        s = step[i];
        for (b = 0; b < s; b++) {
            for (j = b + s; j < n; j += s) {
                temp = a[j];
                for (k = j - s; k >= 0 && a[k] > temp; k -= s) {
                    a[k + s] = a[k];
                }
                a[k + s] = temp;
            }
        }
    }
}

void printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void enterArray(int* arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}


