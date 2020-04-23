#include <stdio.h>
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

//Прототипы функций
void print_array(int arr[], const int N);
long long insert_sort(int arr[], const int N);
long long BinaryInsertionSort(int arr[], const int N);

int main() {
	setlocale(LC_ALL, "russian");
	puts("Создаем секретную базу данных зашифрованную с помощью шифра Цезаря в 100 элементов массива: ");
	const int N = 50000; long long time = 0, time1 = 0, time2 = 0;
	int arr[N], arr1[N], d = 0;
	for (int i = 0; i < N; i++)
	{
		d = rand() % 10000;
		arr[i] = d;
		arr1[i] = d;
		printf("%d ", arr[i]);
		printf("%d ", arr1[i]);
	}
	// Прямая вставка
	time1 = insert_sort(arr, N);
	print_array(arr, N);


	// Бинарная прямая вставка
	time2 = BinaryInsertionSort(arr, N);
	print_array(arr, N);
	printf("\n");
	time = time1 - time2;
	puts("Время выполнения алгоритма: ");
	printf("%lld", time);
	
}

long long insert_sort(int arr[], const int N) {
	long long T, start, stop;
	start = GetTickCount();
	puts("\n");
	puts("Запускаем алгоритм *механические звуки*");
	for (int k = 1; k < N; k++)
	{
		int temp = arr[k];
		int j = k - 1;
		while (j >= 0 && temp <= arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
	stop = GetTickCount();
	T = stop - start;
	printf("Время выполнения данного алгоритма t=%lld в миллисекундах: ", T);
	return T;
}

void print_array(int arr[], const int N) {
	puts("\n");
	puts("Запускаем ал.... Опять не туда смотрю. Печатаем отсортированный массив");
	for (int i = 0; i < N; i++)
	{
		printf("%3d ", arr[i]);
	}
}

long long BinaryInsertionSort(int arr[], const int N) {
	long long T, start, stop;
	start = GetTickCount();
	int mid, high, low, temp;
	puts("\n");
	puts("Запускаем алгоритм *механические звуки*");
	for (int i = 1; i < N; i++) {
		low = 0, high = i;
		mid = i / 2;
		do {
			if (arr[i] > arr[mid]) {
				low = mid + 1;
			}
			else if (arr[i] < arr[mid]) {
				high = mid;
			}
			else { break; }
			mid = low + ((high - low) / 2);
		} while (low < high);

		if (mid < i) {
			temp = arr[i];
			memmove(arr + mid + 1, arr + mid, sizeof(int) * (i - mid));
			arr[mid] = temp;
		}
	}
	stop = GetTickCount();
	T = stop - start;
	printf("Время выполнения данного алгоритма t=%lld в миллисекундах: ", T);
	return T;
}