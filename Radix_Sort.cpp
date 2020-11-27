#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

void printArray(int* a, int n);
int max_rank(int* a, int n);
void bit_sort(int* a, int l, int r, int k);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите количество элементов в массиве: ";
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++) {
		mas[i] = rand() % 100;
	}

	cout << "—формированный массив: " << endl;
	printArray(mas, n);

	int k = max_rank(mas, n);
	bit_sort(mas, 0, n - 1, k);

	cout << "—ортированный массив: " << endl;
	printArray(mas, n);
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int max_rank(int* a, int n) //определение старшего разр€да
{
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int mask = 1;
	mask <<= 31;
	int k = 0;
	while (mask)
	{
		if ((mask & max) != 0) {
			return (31 - k);
		}
		mask = mask >> 1;
		k++;
	}
}

void bit_sort(int* a, int l, int r, int k)
{
	if ((l >= r) || (k < 0)) return;
	else
	{
		int i = l;
		int j = r;
		int mask = 1;
		mask <<= k;
		while (i < j)
		{
			while ((i < j) && ((a[i] & mask) == 0)) {
				i++;
			}
			while ((i < j) && ((a[j] & mask) != 0)) {
				j--;
			}
			if (i < j) {
				swap(a[i], a[j]);
			}
		}
		if ((a[r] & mask) == 0) {
			j++;
		}
		if (l < j) {
			bit_sort(a, l, j - 1, k - 1);
		}
		if (i < r) {
			bit_sort(a, i, r, k - 1);
		}
	}
}

