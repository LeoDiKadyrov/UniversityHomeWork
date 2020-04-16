#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <conio.h>

//Прототипы функций
void print_array(int arr[], int N);
void insert_sort(int arr[], int N);

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
	insert_sort(arr, N);
	print_array(arr, N);
}

void insert_sort(int arr[], const int N) {
	puts("\n");
	puts("Запускаем алгоритм *механические звуки*");
	for (int i = 1; i < N; i++)
	{
		int k = i; // Копируем старую позицию
			while (k > 0 && arr[k-1] > arr[k]) {
				int temp = arr[k - 1];
				arr[k - 1] = arr[k];
				arr[k] = temp;
				k -= 1;
		}
	}
}

void print_array(int arr[], const int N) {
	puts("\n");
	puts("Запускаем ал.... Опять не туда смотрю. Печатаем отсортированный массив");
	for (int i = 0; i < N; i++)
	{
		printf("%3d", arr[i]);
	}
}