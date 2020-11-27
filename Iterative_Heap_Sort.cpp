#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

// ��������� ������� 
void buildMaxHeap(int* arr, int n);
void heapSort(int* arr, int n);

int main()
{
    setlocale(LC_ALL, "russian");
    int n;
    cout << "������� ������ �������: ";
    cin >> n;
    int* arr = new int[n];

    cout << "��� ������: ";
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  
    }

    printf("\n");

    heapSort(arr, n);

    cout << "��������������� ������: ";
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
        if (arr[i] > arr[(i - 1) / 2]) // ���� ���� ������ ��������
        {
            int j = i;
            while (arr[j] > arr[(j - 1) / 2]) // ������ �� ������� ���� �������� �� ����� ������
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
        int j = 0, index; // ��������� ������ ������������
        do 
        {

            index = (2 * j + 1); // ����� � ������ ������ child
            if (arr[index] < arr[index + 1] && index < (i - 1)) {
                index++; // ���� ����� child < right child, ������ � ������ ������� child
            }
            if (arr[j] < arr[index] && index < i) {
                swap(arr[j], arr[index]); // ���� �������� ������ ������ ����, ������ �� �������
            }
            j = index; // ���������� ����� ������� ��������
        } while (index < i);
    }
}




// do...while
/*
�� �� ����� index = i, ������ ��� �� �������� ������ � ��������� ������� � ���������� index ������ ������ ���� ������ ��� i, 
� index ���� ������ ���� ���� ��� i-1 ��-�� ������ "if" �����, �� ����������� ���, � ���� index = i - 1, 
� ���� �� ����� ����������� ���, �� �� ���������� � ������ ��������� � ������� �� ������ �������
*/
