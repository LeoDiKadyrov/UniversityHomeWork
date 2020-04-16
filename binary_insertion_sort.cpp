#include <stdio.h>
#include <iostream>

using namespace std;

//Прототипы функций
int binarySearch(int arr[], int item, int low, int high);
void insertionSort(int arr[], int n);

int main() {
    setlocale(LC_ALL, "russian");
    puts("Создаем секретную базу данных зашифрованную с помощью шифра Цезаря в 100 элементов массива: ");
    const int N = 100;
    int arr[N], d = 0;
    for (int i = 0; i < N; i++)
    {
        d = rand() % 10;
        arr[i] = d;
        printf("%d ", arr[i]);
    }
    int i;

    insertionSort(arr, N);

    printf("\n");
    printf("Выводим отсортированный массив на экран: \n");
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}

int binarySearch(int arr[], int item, int low, int high)
{
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

void insertionSort(int arr[], const int N)
{   
    printf("\n");
    puts("Запускаем усовершенствованный алгоритм поиска преступника *звуки работы* ");
    int i, loc, j, k, selected;

    for (i = 1; i < N; ++i)
    {
        j = i - 1;
        selected = arr[i];

        // Находим позицию на которую нужно поставить выбранный элемент
        loc = binarySearch(arr, selected, 0, j);

        // Двигаем все элементы чтобы образовать место
        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}