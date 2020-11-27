#include "Header.h"
#include <time.h>

int main() {
    setlocale(LC_ALL, "Russian");

    Array <char> mas1;
    mas1.Scan(5);
    mas1.Print();
    cout << "__________________________\n";

    cout << "Создаем mas2 инициализировав его как mas1" << endl;
    Array <char> mas2 = mas1;
    cout << mas2;
    cout << "\n__________________________\n";

    cout << "Массивы mas1 и mas2 равны?: ";
    if (mas1 == mas2) cout << "Da";
    else cout << "Net";
    cout << "\n__________________________\n";

    mas1 += '6'; // '6'
    cout << "Добавляем 6 в конец массива" << endl;
    cout << mas1;
    cout << "\n__________________________\n";

    cout << "Массивы mas1 и mas2 равны?: ";
    if (mas1 == mas2) cout << "Da";
    else cout << "Net";
    cout << "\n__________________________\n";

    cout << "Создаем mas3 путем добавления 7 в конец mas1" << endl;
    Array <char> mas3 = mas1 + '7'; // '7'
    cout << mas3;
    cout << "\n__________________________\n";

    cout << "Удаляем первый элемент из mas3" << endl;
    mas3.DelPosEq(0);
    cout << mas3;
    cout << "\n__________________________\n";

    cout << "Создаем mas4 удаляя из mas3 последний элемент" << endl;
    Array <char> mas4 = mas3.DelPosNew(5);
    cout << mas4;
    cout << "\n__________________________\n";
    
    mas1 -= '1'; // '1'
    cout << "Удаляем единицу из mas1" << endl;
    cout << "Массивы mas1 и mas4 равны?: ";
    if (mas1 == mas4) cout << "Da";
    else cout << "Net";
    cout << "\n__________________________\n";


    int n;
    char* b; // char
    cout << "\nВведите n: ";
    cin >> n;
    b = new char[n]; // char

    cout << "Формируем массив b из n случайных чисел" << endl;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        b[i] = rand() % 10 + 97; // + 97 for char
    }
    Array <char> mas5(b, n);
    cout << mas5;
    cout << "\n__________________________\n";

    int max, min;
    max = mas5.Max();
    min = mas5.Min();
    cout << "Максимальный элемент: mas5[" << max << "] = " << mas5[max] << "\n" << "Минимальный элемент: mas5[" << min << "] = " << mas5[min];
    cout << "\n__________________________\n";

    mas5.Sorting();
    cout << "Отсортированный массив: ";
    cout << mas5;
    cout << "\n__________________________\n";

    cout << "Создаем mas6 путем соединения mas1 и mas5" << endl;
    Array <char> mas6 = mas1 + mas5;
    cout << mas6;
    cout << "\n__________________________\n";

    cout << "Создаем mas7 из 4 элементов" << endl;
    Array <char> mas7(4);
    cin >> mas7;
    cout << mas7;
    cout << "\n__________________________\n";

    int index_7;
    cout << "Проверка входит ли 1 в mas7" << endl;
    index_7 = mas7.FindKey('1'); // '1'
    cout << index_7 << '\n';
    cout << "Проверка входит ли 10 в mas7" << endl;
    index_7 = mas7.FindKey('f'); // 'f'
    cout << index_7;
    cout << "\n__________________________\n";


    mas4 += mas7;
    cout << "Изменили mas4 добавив к нему mas7" << endl;
    cout << mas4 << "\nМассивы mas4 и mas6 равны?: ";
    if (mas4 == mas6) cout << "Da";
    else cout << "Net";
    cout << "\n_____________________________________\n";

    mas4 = mas6;
    cout << "Присваиваем mas6 к mas4" << endl;
    cout << mas4;
    cout << "\n_____________________________________\n";

    return 0;
}