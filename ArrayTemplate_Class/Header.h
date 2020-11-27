#pragma once
#include <iostream>
#include <math.h>

using namespace std;

#define _USE_MATH_DEFINES 

template <class T> class Array {
	T* a;
	int n, mem;
	void ShiftLeft(int pos);

public:
	Array(int m = 1); 
	Array(T* b, int m);
	Array(const Array <T>& x);
	~Array();
	template <class T> friend ostream& operator << (ostream& r, Array <T>& x);
	template <class T> friend istream& operator >> (istream& r, Array <T>& x);
	T& operator[] (int i);
	Array <T>& operator= (const Array <T>& x);
	Array <T>& operator+= (T key);
	Array <T> operator + (T key);
	Array <T>& operator += (Array <T>);
	Array <T> operator+ (Array <T>);
	Array <T>& operator -= (T key);
	Array <T> operator - (T key);
	Array <T>& DelPosEq(int pos);
	Array <T> DelPosNew(int pos);
	void Scan(int m);
	void Print();
	int FindKey(int key);
	bool operator == (Array <T>);
	bool operator != (Array <T>);
	int Max();
	int Min();
	void Sorting();
};

template <class T> Array <T>::Array(int m) {
	mem = 2 * m;
	a = new T[mem];
	n = m;
}

template <class T> Array <T>::Array(T* b, int m) {
	n = m;
	mem = m * 2;
	a = new T[mem];
	for (int i = 0; i < m; i++) {
		a[i] = b[i];
	}
}

template <class T> Array <T>::Array(const Array<T>& x) {
	n = x.n;
	mem = x.mem;
	a = new T[mem];
	for (int i = 0; i < n; i++) {
		a[i] = x.a[i];
	}
}

template <class T> Array <T>:: ~Array() {
	delete[]a;
}

template <class T> void Array<T>::Scan(int m) {
	cout << "Введите " << m << " элементов: ";
	if (mem <= m) {
		delete[]a;
		n = m;
		mem = 2 * n;
		a = new T[mem];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

template <class T> void Array<T>::Print() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << "\n";
}

template <class T> int Array<T>::FindKey(int key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}

template <class T> Array <T>& Array<T>::DelPosEq(int pos) {
	try {
		if (pos < 0 || pos >= n) {
			throw ("Индекс вышел за границы");
		}
		this->ShiftLeft(pos);
	}
	catch (char* s) {
		cout << "Error: " << s << "\nУдаляем первый элемент";
		this->ShiftLeft(0);
	}
	catch (...) {
		cout << "Error: unknown index" << "first element: " << a[0] << '\n';
	}
	return *this;
}

template <class T> Array <T> Array <T>::DelPosNew(int pos) {
	Array Res(n);
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	try {
		if (pos < 0 || pos >= n) {
			throw ("Индекс вышел за границы");
		}
		Res.ShiftLeft(pos);
	}
	catch (char* s) {
		cout << "Error: " << s << "\nУдаляем первый элемент";
		Res.ShiftLeft(0);
	}
	catch (...) {
		cout << "Error: unknown index" << "first element: " << a[0] << '\n';
	}
	return Res;
}

template <class T> ostream& operator << (ostream& r, Array<T>& x) {
	cout << "Your array: ";
	for (int i = 0; i < x.n; i++) {
		cout << x.a[i] << ' ';
	}
	cout << "\n";
	return r;
}

template <class T>  istream& operator >> (istream& r, Array<T>& x) {
	// cout << "Введите кол-во эл-ов: ";
	int m = 4;
	// cin >> m;
	if (x.mem < m) {
		delete[]x.a;
		x.mem = 2 * m;
		x.n = m;
		x.a = new T[x.mem];
	}
	cout << "\nВведите " << m << " элементов: ";
	for (int i = 0; i < m; i++) {
		r >> x.a[i];
	}
	return r;
}

template <class T> int Array<T>::Max() {
	int max = a[0], max_index = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			max_index = i;
		}
	}
	return max_index;
}

template <class T> int Array<T>::Min() {
	int min = a[0], min_index = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			min_index = i;
		}
	}
	return min_index;
}

template <class T> void Array<T>::Sorting() {
	int k, t = n - 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < t - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				k = a[j + 1];
				a[j + 1] = a[j];
				a[j] = k;
			}
		}
}

template <class T> Array<T>& Array<T>::operator= (const Array <T>& x) {
	if (this != &x) {
		delete[]a;
		n = x.n;
		mem = 2 * n;
		a = new T[mem];
		for (int i = 0; i < n; i++) {
			a[i] = x.a[i];
		}
	}
	return *this;
}

template <class T> T& Array<T>::operator[] (int k) {
	try {
		if (k < 0 || k >= n) {
			throw("некорректный индекс");
		}
	}
	catch (char* s) {
		cout << "Error: " << s << "первый элемент: " << a[0] << '\n';

	}
	catch (...) {
		cout << "Error: неизвестный индекс" << "первый элемент: " << a[0] << '\n';
	}
	return a[k];
}

template <class T> bool Array<T>::operator== (Array <T> b) {
	int i;
	if (n == b.n) {
		for (i = 0; (i < n) && (a[i] == b.a[i]); i++);
		if (i == n) {
			return true;
		}
	}
	return false;
}

template <class T> bool Array<T> ::operator!= (Array <T> b) {
	return !(*this == b);
}

template <class T> Array <T>& Array<T> ::operator+= (Array <T> b) {
	if (n + b.n < mem) {
		for (int i = n; i < n + b.n; i++) {
			a[i] = b.a[i - n];
		}
		n += b.n;
	}
	else {
		T* t;
		t = new T[(n + b.n) * 2];
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

template <class T> Array <T> Array <T>::operator- (T key) {
	Array Res(n);
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	Res -= key;
	return Res;
}

template <class T> Array <T>& Array <T>:: operator-= (T key) {
	try {
		int pos = FindKey(key);
		if (pos + 1) {
			this->ShiftLeft(pos);
		}
		else {
			throw ("\nнет такого key\n");
		}
	}
	catch (char* s) {
		cout << "Error: " << s << "\nУдаляем первый элемент";
		this->ShiftLeft(0);
	}
	catch (...) {
		cout << "Error: unknown index" << "first element: " << a[0] << '\n';
	}
	return *this;
}

template <class T> Array <T>& Array <T>::operator+= (T key) {
	if (n < mem) {
		a[n] = key;
		n++;
	}
	else {
		int i; T* t;
		t = new T[(n + 1) * 2];
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

template <class T> Array <T> Array <T>::operator+ (T key) {
	Array Res(n + 1);
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	Res.a[n] = key;
	return Res;
}

template <class T> Array <T> Array <T>::operator+ (Array <T> b) {
	Array Res(n + b.n);
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	for (int i = n; i < n + b.n; i++) {
		Res.a[i] = b.a[i - n];
	}
	return Res;
}

template <class T> void Array<T>::ShiftLeft(int pos) {
	for (int i = pos; i < n; i++) {
		a[i] = a[i + 1];
	}
	n -= 1;
}
