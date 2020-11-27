#include "Header.h"
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "russian");
    Array mas1;
    mas1.Scan(5);
    mas1.Print();
    cout << "\n_____________________________________\n";

    Array mas2(mas1);
    cout << "Создаем mas2 инициализировав его как mas1" << endl;
    cout << mas2;
    cout << "\n_____________________________________\n";

    cout << "Массивы mas1 и mas2 равны?: ";
    if (mas1 == mas2) cout << "Да";
    else cout << "Нет";
    cout << "\n_____________________________________\n";

    mas1 += 6;
    cout << "Добавляем 6 в конец массива" << endl;
    cout << mas1;
    cout << "\n_____________________________________\n";

    cout << "Массивы mas1 и mas2 равны?: ";
    if (mas1 == mas2) cout << "Да";
    else cout << "Нет";
    cout << "\n_____________________________________\n";

    Array mas3 = mas1 + 7;
    cout << "Создаем mas3 путем добавления 7 в конец mas1" << endl;
    cout << mas3;
    cout << "\n_____________________________________\n";

    mas3.DelPosEq(0);
    cout << "Удаляем первый элемент из mas3" << endl;
    cout << mas3;
    cout << "\n_____________________________________\n";

    Array mas4 = mas3.DelPosNew(5);
    cout << "Создаем mas4 удаляя из mas3 последний элемент" << endl;
    cout << mas4;
    cout << "\n_____________________________________\n";

    mas1 -= 1;
    cout << "Удаляем единицу из mas1" << endl;
    cout << "Массивы mas1 и mas4 равны?: ";
    if (mas1 == mas4) cout << "Да";
    else cout << "Нет";
    cout << "\n_____________________________________\n";

    int n, * b;
    cout << "Введите n: ";
    cin >> n;
    b = new int[n];
    for (int i = 0; i < n; i++) {
        b[i] = rand() % 10;
    }
    Array mas5(b, n);
    cout << "Формируем массив b из n случайных чисел" << endl;
    cout << mas5;
    cout << "\n_____________________________________\n";

    int max, min;
    max = mas5.Max();
    min = mas5.Min();
    cout << "Max элемент: mas5[" << max << "] = " << mas5[max] << " Min элемент: mas5[" << min << "] = " << mas5[min];
    cout << "\n_____________________________________\n";

    mas5.Sorting();
    cout << "Отсортированный массив: ";
    cout << mas5;
    cout << "\n_____________________________________\n";

    Array mas6 = mas1 + mas5;
    cout << "Создаем mas6 путем соединения mas1 и mas5" << endl;
    cout << mas6;
    cout << "\n_____________________________________\n";

    Array mas7(4);
    cout << "Создаем mas7 из 4 элементов" << endl;
    cin >> mas7;
    cout << mas7;
    cout << "\n_____________________________________\n";

    int index_7;
    index_7 = mas7.FindKey(1);
    cout << "Проверка входит ли 1 в mas7" << endl;
    cout << index_7 << '\n';
    index_7 = mas7.FindKey(10);
    cout << "Проверка входит ли 10 в mas7" << endl;
    cout << index_7;
    cout << "\n_____________________________________\n";

    mas4 += mas7;
    cout << "Изменили mas4 добавив к нему mas7" << endl;
    cout << mas4 << "\nМассивы mas4 и mas6 равны?: ";
    if (mas4 == mas6) cout << "Да";
    else cout << "Нет";
    cout << "\n_____________________________________\n";

    mas4 = mas6;
    cout << "Присваиваем mas6 к mas4" << endl;
    cout << mas4;
    cout << "\n_____________________________________\n";
    return 0;
}
