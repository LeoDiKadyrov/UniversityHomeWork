#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

// Прототипы функций 
void buildMaxHeap(int* arr, int n);
void heapSort(int* arr, int n);

int main()
{
    setlocale(LC_ALL, "russian");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Наш массив: ";
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  
    }

    printf("\n");

    heapSort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    delete[] arr;
    return 0;
}

void buildMaxHeap(int* arr, int n)
{
    for (int i = 1; i < n; i++)
    { 
        if (arr[i] > arr[(i - 1) / 2]) // если дитя больше родителя
        {
            int j = i;
            while (arr[j] > arr[(j - 1) / 2]) // меняем их местами пока родитель не будет меньше
            {
                swap(arr[j], arr[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapSort(int* arr, int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); 
        int j = 0, index; // обновляем каждую перестановку
        do 
        {

            index = (2 * j + 1); // берем в индекс левого child
            if (arr[index] < arr[index + 1] && index < (i - 1)) {
                index++; // если левый child < right child, пихаем в индекс правого child
            }
            if (arr[j] < arr[index] && index < i) {
                swap(arr[j], arr[index]); // если родитель меньше своего дитя, меняем их местами
            }
            j = index; // запоминаем самое большое значение
        } while (index < i);
    }
}




// do...while
/*
Мы не берем index = i, потому что мы поменяли первый и последний элемент и получается index просто должен быть меньше чем i, 
И index даже должен быть ниже чем i-1 из-за нашего "if" блока, мы увеличиваем его, и если index = i - 1, 
и если мы будем увеличивать его, то он поменяется с нужным элементом и встанет на нужную позицию
*/
