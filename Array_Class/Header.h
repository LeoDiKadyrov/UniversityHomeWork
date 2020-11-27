#pragma once

#include <iostream>

using namespace std;

class Array {
public:

    Array(int m = 1);
    Array(int* b, int m);
    Array(const Array& x);
    Array& operator= (const Array& x);
    ~Array();

    void Scan(int m);
    void Print();

    int& operator[] (int i);
    int FindKey(int key);

    Array& operator+=(int key);
    Array operator + (int key);
    Array& operator += (Array);
    Array operator+ (Array);
    Array& operator -= (int key);
    Array operator - (int key);
    Array& DelPosEq(int pos);
    Array DelPosNew(int pos);

    bool operator == (Array);
    bool operator != (Array);

    int Max();
    int Min();
    void Sorting();

    friend ostream& operator << (ostream& r, Array& x);
    friend istream& operator >> (istream& r, Array& x);

private:

    int* a, n, mem;
    void ShiftRight(int pos);
};

Array::Array(int m) {
    mem = 2 * m;
    a = new int[mem];
    n = m;
}

Array::Array(int* b, int m) {
    n = m;
    mem = m * 2;
    a = new int[mem];
    for (int i = 0; i < m; i++) {
        a[i] = b[i];
    }
}

Array::Array(const Array& x) {
    n = x.n;
    mem = x.mem;
    a = new int[mem];
    for (int i = 0; i < n; i++) {
        a[i] = x.a[i];
    }
}

Array& Array::operator= (const Array& x) {
    if (this != &x) {
        delete[]a;
        n = x.n;
        mem = 2 * n;
        a = new int[mem];
        for (int i = 0; i < n; i++) {
            a[i] = x.a[i];
        }
    }
    return *this;
}

Array::~Array() {
    delete[] a;
}

void Array::Scan(int m) {
    cout << "Введите " << m << " элементов: ";
    if (mem <= m) {
        delete[]a;
        n = m;
        mem = 2 * n;
        a = new int[mem];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Array::Print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << "\n";
}

int& Array::operator[] (int k) {
    try {
        if (k < 0 || k >= n) {
            throw("Неверный индекс");
        }
    }
    catch (char* s) {
        cout << "Ошибка: " << s << "первый элемент: " << a[0] << '\n';

    }
    catch (...) {
        cout << "Ошибка: неизвестный индекс" << "первый элемент: " << a[0] << '\n';
    }
    return a[k];
}

int Array::FindKey(int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

Array& Array::operator+= (int key) {
    if (n < mem) {
        a[n] = key;
        n++;
    }
    else {
        int i, * t;
        t = new int[(n + 2) * 2];
        for (i = 0; i < n; i++) {
            t[i] = a[i];
        }
        t[n] = key;
        delete[]a;
        a = t;
        n++;
        mem = n * 2;
    }
    return *this;
}

Array Array::operator+ (int key) {
    Array Res(n + 1);
    for (int i = 0; i < n; i++) {
        Res.a[i] = a[i];
    }
    Res.a[n] = key;
    return Res;
}

Array& Array::operator+= (Array b) {
    if (n + b.n < mem) {
        for (int i = n; i < n + b.n; i++) {
            a[i] = b.a[i - n];
        }
        n += b.n;
    }
    else {
        int* t;
        t = new int[(n + b.n) * 2];
        for (int i = 0; i < n; i++) {
            t[i] = a[i];
        }
        for (int i = n; i < n + b.n; i++) {
            t[i] = b[i - n];
        }
        delete[]a;
        a = t;
        n += b.n;
        mem = n * 2;
    }

    return *this;
}

Array Array::operator+ (Array b) {
    Array Res(n + b.n);
    for (int i = 0; i < n; i++) {
        Res.a[i] = a[i];
    }
    for (int i = n; i < n + b.n; i++) {
        Res.a[i] = b.a[i - n];
    }
    return Res;
}

Array& Array::operator-= (int key) {
    try {
        int pos = FindKey(key);
        if (pos + 1) {
            this->ShiftRight(pos);
        }
        else {
            throw ("Нет такого значения в массиве");
        }
    }
    catch (char* s) {
        cout << "Ошибка: " << s << "\nУдаляем первый элемент";
        this->ShiftRight(0);
    }
    return *this;
}

Array Array::operator- (int key) {
    Array Res(n);
    for (int i = 0; i < n; i++) {
        Res.a[i] = a[i];
    }
    Res -= key;
    return Res;
}

Array& Array::DelPosEq(int pos) {
    try {
        if (pos < 0 || pos >= n) {
            throw ("Индекс не входит в диапазон");
        }
        this->ShiftRight(pos);
    }
    catch (char* s) {
        cout << "Ошибка: " << s << "\nУдаляем первый элемент";
        this->ShiftRight(0);
    }
    return *this;
}

Array Array::DelPosNew(int pos) {
    Array Res(n);
    for (int i = 0; i < n; i++) {
        Res.a[i] = a[i];
    }
    try {
        if (pos < 0 || pos >= n) {
            throw ("Индекс не входит в диапазон");
        }
        Res.ShiftRight(pos);
    }
    catch (char* s) {
        cout << "Ошибка: " << s << "\nУдаляем первый элемент";
        Res.ShiftRight(0);
    }
    return Res;
}

bool Array::operator==(Array b) {
    int i;
    if (n == b.n) {
        for (i = 0; i < n && a[i] == b.a[i]; i++);
        if (i == n) {
            return true;
        }
    }
    return false;
}

bool Array::operator!=(Array b) {
    return !(*this == b);
}

int Array::Max() {
    int max = a[0], max_index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            max_index = i;
        }
    }
    return max_index;
}

int Array::Min() {
    int min = a[0], min_index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            min_index = i;
        }
    }
    return min_index;
}

void Array::Sorting() {
    int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                k = a[j + 1]; a[j + 1] = a[j]; a[j] = k;
            }
        }
}

istream& operator>> (istream& r, Array& x) {
    // cout << "Введите кол-во элементов: ";
    int m = 4;
    // cin >> m;
    if (x.mem < m) {
        delete[]x.a;
        x.mem = 2 * m;
        x.n = m;
        x.a = new int[x.mem];
    }
    cout << "\nВведите " << m << " элементов: ";
    for (int i = 0; i < m; i++) {
        r >> x.a[i];
    }
    return r;
}

ostream& operator << (ostream& r, Array& x) {
    cout << "Массив: ";
    for (int i = 0; i < x.n; i++) {
        cout << x.a[i] << ' ';
    }
    cout << "\n";
    return r;
}

void Array::ShiftRight(int pos) {
    for (int i = pos; i < n; i++) {
        a[i] = a[i + 1];
    }
    n -= 1;
};
