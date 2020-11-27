#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;
typedef unsigned char UC;

class BoolVector
{
	UC* bv;
	int n, m;
	int Input(const char* s, int, int, int);
	void Output(int, int);
	BoolVector kostl(const char* s, int kol);
public:
	BoolVector(int n1 = 1);
	BoolVector(const BoolVector&);
	BoolVector(const char* s);
	BoolVector(const char* s, int);
	BoolVector operator= (const BoolVector&);
	~BoolVector() { delete[]bv; }

	UC operator[] (int);
	void Print();
	void Scan(int);
	int Weight();

	BoolVector SetUp1(int);
	BoolVector SetUp0(int);
	BoolVector Invert(int);
	BoolVector SetUp1(int col, int pos);
	BoolVector SetUp0(int col, int pos);
	BoolVector Invert(int col, int pos);

	bool operator== (BoolVector);
	bool operator!= (BoolVector);
	bool operator< (BoolVector);
	bool operator> (BoolVector);

	BoolVector operator& (BoolVector&);
	BoolVector operator| (BoolVector&);
	BoolVector operator^ (BoolVector&);
	BoolVector operator~ ();
	BoolVector operator<< (int);
	BoolVector operator>> (int);

	BoolVector& operator &=(BoolVector& x);
	BoolVector& operator |=(BoolVector& x);
	BoolVector& operator ^=(BoolVector& x);
	BoolVector& operator <<=(int);
	BoolVector operator>>= (int);

	friend ostream& operator<< (ostream& r, BoolVector& x);
	friend istream& operator>> (istream& r, BoolVector& x);
};

int BoolVector::Weight()   //вес булева вектора
{
	int w = 0;
	UC mask = 1;
	for (int i = 0; i < m; i++, mask = 1)
		for (mask <<= 7; mask != 0; mask >>= 1)
			if (bv[i] & mask)w++;
	return w;
}


BoolVector::BoolVector(int n1)
{
	m = n1 / 8; int k = n1 % 8;
	if (k) m++;
	bv = new UC[m];
	n = n1;
	for (int i = 0; i < m; i++) bv[i] = 0;
}

BoolVector::BoolVector(const BoolVector& x)
{
	n = x.n;
	m = x.m;
	bv = new UC[m];
	for (int i = 0; i < m; i++)
		bv[i] = x.bv[i];
}

BoolVector BoolVector::kostl(const char* s, int kol)
{

	n = strlen(s) + kol;
	m = n / 8; int k = n % 8;
	if (k) m++;
	bv = new UC[m];

	int i_s = 0, i_bv = 0;
	if (k) {
		i_s = Input(s, i_bv, i_s, k);
		i_bv++;
	}
	for (; i_bv < m; i_bv++)
		i_s = Input(s, i_bv, i_s, 8);

	BoolVector p = *this;
	return p;
}
BoolVector::BoolVector(const char* s)
{
	n = strlen(s);
	m = n / 8; int k = n % 8;
	if (k) m++;
	bv = new UC[m];

	int i_s = 0, i_bv = 0;
	if (k) {
		i_s = Input(s, i_bv, i_s, k);
		i_bv++;
	}
	for (; i_bv < m; i_bv++)
		i_s = Input(s, i_bv, i_s, 8);
}

BoolVector::BoolVector(const char* s, int kol)
{
	int d = strlen(s);
	n = kol;
	m = n / 8; int k = n % 8;
	if (k) m++;
	bv = new UC[m];

	int i_bv, i_s;
	if (d >= n)
	{
		i_bv = 0; i_s = d - n;
		if (k) {
			i_s = Input(s, i_bv, i_s, k);
			i_bv++;
		}
		for (; i_s < d; i_bv++)
			i_s = Input(s, i_bv, i_s, 8);
	}
	else {
		int m2 = d / 8; int k2 = d % 8; i_s = 0;
		if (k2) m2++;

		for (i_bv = 0; i_bv < m - m2; i_bv++) {
			bv[i_bv] = 0;
		}
		if (k2) {
			i_s = Input(s, i_bv, 0, k2);
			i_bv++;
		}
		for (; i_s < d; i_bv++)
			i_s = Input(s, i_bv, i_s, 8);
	}
}
int BoolVector::Input(const char* s, int i_bv, int i_s, int k)
{
	UC mask = 1;
	bv[i_bv] = 0;
	for (int i = 0; i < k; i++, i_s++)
	{
		bv[i_bv] <<= 1;
		if (s[i_s] == '1') bv[i_bv] |= mask;
	}
	return i_s;
}

void BoolVector::Output(int i_bv, int k)
{
	UC mask = 1;
	mask <<= k - 1;
	for (int i = 0; i < k; i++)
	{
		if (bv[i_bv] & mask)
		{
			cout << " " << '1';
		}
		else cout << " " << '0';
		mask >>= 1;
	}

}
void BoolVector::Scan(int n1)
{
	char* s; int m1, k;
	s = new char[n1];
	cin >> s;

	m1 = n1 / 8; k = n1 % 8;
	if (k) m1++;

	if (m != m1)
	{
		delete[]bv;
		m = m1;
		bv = new UC[m];
	}
	n = n1;
	int i_bv = 0, i_s = 0;
	if (k)
	{
		i_s = Input(s, i_bv, i_s, k);
		i_bv++;
	}
	for (; i_s < n; i_bv++)
		i_s = Input(s, i_bv, i_s, 8);
}

void BoolVector::Print()
{
	int k = n % 8; int i = 0;
	if (k)
	{
		Output(0, k); i++;
	}
	for (; i < m; i++)Output(i, 8);
	cout << endl;
}
BoolVector BoolVector::operator=(const BoolVector& x)
{
	if (this != &x)
	{
		if (m != x.m)
		{
			delete[]bv;
			m = x.m;
			bv = new UC[m];
		}
		for (int i = 0; i < m; i++)
			bv[i] = x.bv[i];
		n = x.n;
	}
	return *this;
}

UC BoolVector::operator[] (int i)
{
	int m1 = i / 8, k = i % 8;
	UC mask = 1;
	mask <<= k;
	if (bv[m - 1 - m1] & mask) return 1;
	else return 0;
}


bool BoolVector::operator== (BoolVector x)
{
	if (n != x.n) return false;
	for (int i = 0; i < m; i++)
		if (bv[i] != x.bv[i]) return false;
	return true;
}
bool BoolVector::operator!= (BoolVector x)
{
	if (*this == x)return false;
	else return true;
}
bool BoolVector::operator< (BoolVector x)
{
	if (n != x.n) return false;
	for (int i = 0; i < m; i++)
		if (bv[i] >= x.bv[i]) return false;
	return true;
}
bool BoolVector::operator> (BoolVector x)
{
	if (n != x.n) return false;
	for (int i = 0; i < m; i++)
		if (bv[i] <= x.bv[i]) return false;
	return true;
}
BoolVector BoolVector::SetUp1(int i)
{
	if (i < 0 || i >= n) cout << "incorrect index" << endl;
	else {
		int m1 = i / 8, k = i % 8;
		UC mask = 1;  mask <<= k;
		bv[m - 1 - m1] |= mask;
	}
	return (*this);
}

BoolVector BoolVector::SetUp0(int i)
{
	if (i < 0 || i >= n) cout << "incorrect index" << endl;
	else {
		int m1 = i / 8, k = i % 8;
		UC mask = 1;  mask <<= k;
		mask = ~(mask);
		bv[m - 1 - m1] &= mask;
	}
	return (*this);
}
BoolVector BoolVector::Invert(int i)
{
	if (i < 0 || i >= n) cout << "incorrect index" << endl;
	else {
		int m1 = i / 8, k = i % 8;
		UC mask = 1;  mask <<= k;
		bv[m - 1 - m1] ^= mask;
	}
	return (*this);
}
BoolVector BoolVector::SetUp0(int col, int pos)
{
	for (int i = pos; (i < n) & (i < pos + col); i++) {
		SetUp0(i);
	}
	return *this;
}
BoolVector BoolVector::SetUp1(int col, int pos)
{
	for (int i = pos; (i < n) & (i < pos + col); i++) {
		SetUp1(i);
	}
	return *this;
}
BoolVector BoolVector::Invert(int col, int pos)
{
	for (int i = pos; (i < n) & (i < pos + col); i++) {
		Invert(i);
	}
	return *this;
}
BoolVector BoolVector::operator& (BoolVector& x)
{
	int N = n, j_res = m - 1;
	if (N > x.n) { N = x.n; j_res = x.m - 1; }
	BoolVector Res(N);
	int j, j_x;
	for (j = m - 1, j_x = x.m - 1; j_res >= 0; j--, j_x--, j_res--)
		Res.bv[j_res] = bv[j] & x.bv[j_x];
	return Res;
}

BoolVector& BoolVector::operator&= (BoolVector& x)
{
	BoolVector res;
	res = (*this & x);
	*this = res;
	return (*this);
}

BoolVector BoolVector::operator| (BoolVector& x)
{
	int n1 = n, j_res = m - 1;


	if (x.n > n1)
	{
		n1 = x.n;
		j_res = x.m - 1;

	}
	BoolVector res(n1);

	int j, j_x;
	for (j = m - 1, j_x = x.m - 1; ((j >= 0) && (j_x >= 0)); j--, j_x--, j_res--)
		res.bv[j_res] = bv[j] | x.bv[j_x];
	if (j >= 0)
		for (; j_res > 0; j_res--, j--)
		{
			res.bv[j_res] = bv[j];
		}
	if (j_x >= 0)
		for (; j_res > 0; j_res--, j_x--)
		{
			res.bv[j_res] = bv[j_x];
		}

	return res;

}
BoolVector& BoolVector::operator|= (BoolVector& x)
{
	BoolVector res;
	res = (*this) | x;
	*this = res;
	return (*this);
}
BoolVector BoolVector::operator^ (BoolVector& x)
{
	int n1 = n, j_res = m - 1;


	if (x.n > n1)
	{
		n1 = x.n;
		j_res = x.m - 1;

	}
	BoolVector res(n1);

	int j, j_x;
	for (j = m - 1, j_x = x.m - 1; ((j >= 0) && (j_x >= 0)); j--, j_x--, j_res--)
		res.bv[j_res] = bv[j] ^ x.bv[j_x];
	if (j >= 0)
		for (; j_res > 0; j_res--, j--)
		{
			res.bv[j_res] = bv[j];
		}
	if (j_x >= 0)
		for (; j_res > 0; j_res--, j_x--)
		{
			res.bv[j_res] = bv[j_x];
		}

	return res;

}
BoolVector& BoolVector::operator^= (BoolVector& x)
{
	BoolVector res;
	res = (*this) ^ x;
	*this = res;
	return (*this);
}

BoolVector BoolVector::operator~ ()
{
	int i;
	for (i = 0; i < m; i++)
		bv[i] = ~bv[i];
	return *this;
}

BoolVector BoolVector::operator<< (int k)
{
	BoolVector res = (*this);
	if (k >= n) for (int i = 0; i < m; i++) bv[i] = 0;
	else {
		for (int i = n - 1; i >= k; i--) {
			if (res[i - k] == 1) {
				res.SetUp1(i);
			}
			else { res.SetUp0(i); }
		}
	}
	res.SetUp0(k, 0);
	return res;
}

BoolVector& BoolVector::operator<<=(int k)
{
	BoolVector res = *this;
	res = res << k;
	*this = res;
	return *this;
}
BoolVector BoolVector::operator>>(int k)
{
	int temp = k;
	int i;
	for (i = 0; temp < n; i++, temp++)
	{
		if (operator[](temp))
		{
			this->SetUp1(i);
		}
		else
		{
			this->SetUp0(i);
		}
	}
	for (; i < n; i++)
	{
		this->SetUp0(i);
	}
	return *this;
}

BoolVector BoolVector::operator>>=(int k)
{
	BoolVector res = *this;
	res = res >> k;
	*this = res;
	return *this;
}
istream& operator>> (istream& r, BoolVector& x)
{
	x.Scan(x.n); return r;
}
ostream& operator<< (ostream& r, BoolVector& x)
{
	x.Print(); return r;
}

int main()
{
	setlocale(LC_ALL, "russian");
	BoolVector B1, B2(10), B3("111011101110"), B4("111011101110", 10), B5("111011101110", 16);
	cout << "B1: " << B1 << endl;
	cout << "B2: " << B2 << endl;
	cout << "B3: " << B3 << endl;
	cout << "B4: " << B4 << endl;
	cout << "B5: " << B5 << endl;

	cout << "Вес В3: " << B3.Weight() << endl;
	cout << "Вес В5: " << B5.Weight() << endl;

	if (B3 != B5) {
		cout << "В3 и В5 не равны" << endl;
	}
	else { cout << "В3 и В5 равны" << endl; }

	BoolVector B6(B5);
	cout << "B6: " << B6 << endl;

	cout << "Введите В2: ";
	cin >> B2;
	cout << "B2: " << B2 << endl;

	B1 = B2;
	cout << "B1: " << B1 << endl;
	if (B1 == B2) {
		cout << "B1 = B2" << endl;
	}
	else { cout << "B1 != B2" << endl; }

	BoolVector V1, V2, V3;
	V1 = B1 & B3, V2 = B1 | B3, V3 = B1 ^ B3;
	cout << "V1: " << V1 << endl;
	cout << "V2: " << V2 << endl;
	cout << "V3: " << V3 << endl;

	B1 = B1 &= B3;
	cout << "B1&=B3: " << B1 << endl;
	if (B1 == V1) {
		cout << "B1 = V1" << endl;
	}
	else { cout << "B1 != V1" << endl; }

	B2 = B2 |= B3;
	cout << "B2|=B3: " << B2 << endl;
	if (B2 == V2) {
		cout << "B2 = V2" << endl;
	}
	else { cout << "B2 != V2" << endl; }

	B1 = ~B1;
	cout << "B1 invert: " << B1 << endl;
	int tmp = B1[4];
	cout << "B1[4]: " << tmp << endl;
	tmp = B1[5];
	cout << "B1[5]: " << tmp << endl;

	cout << "Устанавливаем 11 компоненту В1: ";
	B1.SetUp1(11); cout << "B1: " << B1 << endl;
	cout << "Сбрасываем 7-ую компоненту В1: ";
	B1.SetUp0(7);
	cout << B1 << endl;
	cout << "Инвертируем 9-ую компоненту В1: ";
	B1.Invert(9);
	cout << B1 << endl;

	cout << "Устанавливаем 3 компоненты начиная с 5-ой В1: ";
	B1.SetUp1(3, 5);
	cout << B1 << endl;
	cout << "Инвертируем 3 компоненты начиная с 1-ой В1: ";
	B1.Invert(3, 1);
	cout << B1 << endl;

	BoolVector V4;
	V4 = B1 << 4;
	B1 = B1 >> 4;
	cout << "B1: " << B1 << endl;
	cout << "V4: " << V4 << endl;
	if (V4 == B1) {
		cout << "V4 = B1" << endl;
	}
	else { cout << "V4 != B1" << endl; }
}
