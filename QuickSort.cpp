#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int l, int h);

int main()
{
    setlocale(LC_ALL, "russian");
    int n;
    cout << "������� n: ";
    cin >> n;
    int* arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "������ �� ����������: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    unsigned int start_time = clock();
    quickSort(arr, 0, n - 1);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "\n������ ����� ����������: ";
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } 
    cout << "����� ����������: ";
    cout << search_time << "��";
    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort(int arr[], int l, int h) // l --> ��������� ������, h --> �������� ������ 
{
    // ������� ���� 
    int* stack = new int[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    // ���� ���� �� �����������, �������
    while (top >= 0) {
        // ������� h, l
        h = stack[top--];
        l = stack[top--];
 
        int p = partition(arr, l, h);

        // ���� �������� ����� �� ������, �� ��������� �� � ���� �����
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // �� �� ��� � ������, ������ ������
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}