#include <iostream>
#include <locale.h>
#include "Header.h"

using namespace std;

class Set : public BoolVector
{
	int N; //кол-во эл-тов

public:
	Set() : BoolVector(256) { N = 0; }//создание пустого множества
	Set(char*);
	Set(const Set&);
	~Set() {};
	Set& operator= (const Set&);

	Set operator+ (char); //добавление эл-та, создается новое мн-во
	Set& operator+= (char); //добавление эл-та, изменяется *this

	Set operator- (char); //удаление эл-та, создается новое мн-во
	Set& operator-= (char); //удаление эл-та, изменяется *this

	Set operator+ (Set &); //объединение мн-в, создается новое мн-во
	Set operator+= (Set &); //объединение мн-в, изменяется *this

	Set operator* (Set &); //пересечение мн-в, создается новое мн-во
	Set operator*= (Set &); //пересечение мн-в, изменяется *this

	Set operator- (Set &); //разность мн-в, создается новое мн-во
	Set operator-= (Set &); //разность мн-в, изменяется *this

	Set operator~(); //дополнение до универсального

	bool operator== (Set);
	bool operator!= (Set);
	int Number() { return N; }

	bool FindKey(char);    	//проверка принадлежности эл-та мн-ву
	bool Empty();        	      	//проверка пустоты множества
	bool NotEmpty();

	virtual void Print();
	virtual void Scan(int);

	friend ostream& operator << (ostream& r, Set& x);
	friend istream& operator >> (istream& r, Set& x);
};

Set::Set(const Set& x) : BoolVector(x)
{
	N = x.N;
}

Set::Set(char* s)
{
	n = 256;
	m = 32;
	bv = new UC[m];
	int i;
	for (i = 0; i < m; i++) bv[i] = 0;
	for (i = 0; s[i]; i++) SetUp1((int)s[i]);
	N = Weight();
}

Set& Set::operator= (const Set& x)
{
	this->BoolVector::operator=(x);
	N = this->Weight();
	return *this;
}

Set Set::operator+(char ch)
{
	Set s = *this;
	s.SetUp1(ch);
	s.N = s.Weight();
	return s;
}

Set& Set::operator+=(char ch)
{
	SetUp1(ch);
	N = Weight();
	return *this;
}

Set Set::operator-(char ch)
{
	Set s = *this;
	s.SetUp0(ch);
	s.N = s.Weight();
	return s;
}

Set& Set::operator-=(char ch)
{
	SetUp0(ch);
	N = Weight();
	return *this;
}

Set Set::operator+(Set& x)
{
	Set s = *this;
	s |= x;
	s.N = s.Weight();
	return s;
}

Set Set::operator+=(Set& x)
{
	*this |= x;
	N = Weight();
	return *this;
}

Set Set::operator*(Set& x)
{
	Set s = *this;
	s &= x;
	s.N = s.Weight();
	return s;
}

Set Set::operator*=(Set &x)
{
	(*this) &= x;
	N = Weight();
	return *this;
}

Set Set::operator-(Set& x)
{
	Set s1 = *this;
	Set s2 = s1 * x;
	s1 ^= s2;
	s1.N = s1.Weight();
	return s1;
}

Set Set::operator-=(Set& x)
{
	Set s1 = (*this) * x;
	*this ^= s1;
	N = Weight();
	return *this;
}

Set Set::operator~()
{
	Set res = *this;
	res.BoolVector::operator~();
	res.N = res.Weight();
	return res;
}

void Set::Print()
{
	if (!(this->Empty()))
	{
		for (int i = 0; i < 256; i++)
		{
			if (operator[](i))
			{
				cout << char(i) << ' ';
			}
		}
	}
	else
	{
		cout << "Empty";
	}
	cout << endl;
}

void Set::Scan(int n)
{
	cout << "enter " << n << " elements: ";
	char* s;
	s = new char[n + 1];
	cin >> s;
	Set res(s);
	*this = res;
	delete[] s;
}

bool Set::FindKey(char ch)
{
	if (operator[]((UC)ch))
	{
		return true;
	}
	return false;
}

bool Set::Empty()
{
	if (N == 0)
	{
		return true;
	}
	return false;
}

bool Set::NotEmpty()
{
	if (N != 0)
	{
		return true;
	}
	return false;
}

bool Set::operator==(Set x)
{
	if (this->BoolVector::operator==(x))
	{
		return true;
	}
	return false;
}

bool Set::operator!=(Set x)
{
	Set s = *this;
	int f = 0;
	for (int i = 0; i < N; i++)
		if (s[i] == x[i])
			f++;
	if (f == N)
		return true;
	else return false;
}

ostream& operator<< (ostream& r, Set& x)
{
	x.Print(); return r;
}

istream& operator>>(istream& r, Set& x)
{
	cout << "number of elements";
	char s[257];
	cin >> s;
	Set res(s);
	x = res;
	return r;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char s[257];
	cout << "Введите строку для формирования множества: " << endl;
	gets_s(s, 256);
	Set s1(s);
	cout << "s1: ";
	s1.Print(); cout << endl;
	int kol = s1.Number();
	cout << "Кол-во элементов в s1: " << kol << endl;
	cout << "______________________" << endl;
	Set s2(s1);
	cout << "s2: " << s2 << endl;
	if (s1 == s2) {
		cout << "S1 == S2" << endl;
	}
	else { cout << "S1 != S2" << endl; }
	cout << "______________________" << endl;
	if (s2.FindKey('o'))
	{
		s2 -= 'o';
	}
	else
	{
		s2 += 'o';
	}
	if (s2.FindKey('a'))
	{
		s2 -= 'a';
	}
	else
	{
		s2 += 'a';
	}
	cout << "s2: " << s2 << endl;
	if (s1 == s2)
	{
		cout << "s1 = s2" << endl;
	}
	else
	{
		cout << "s1 != s2" << endl;
	}
	cout << "______________________" << endl;
	Set s3;
	cout << "s3: " << s3 << endl;
	cout << "is s3 empty?: ";
	if (s3.Empty())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << "______________________" << endl;
	s3.Scan(6);
	cout << "is s3 empty?: ";
	if (s3.Empty())
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}
	cout << "s3: " << s3;
	cout << "______________________" << endl;
	Set s4 = s3 - 'y' + 'i';
	cout << "s4: " << s4;
	cout << "______________________" << endl;
	Set t1, t2, t3;
	t1 = s2 + s4;
	t2 = s2 * s4;
	t3 = s2 - s4;
	cout << "t1 :" << t1 << endl;
	cout << "t2 :" << t2 << endl;
	cout << "t3 :" << t3 << endl;

	cout << "_______________________";
	Set t4, t5;
	cout << "t4 :" << t4 << endl;
	t4 = ~s2;
	t5 = t4 * s2;
	cout << "t4 :" << t4 << endl;
	cout << "t5 :" << t5 << endl;
	cout << "_______________________";
	char string[257];
	cout << "\nВведите строку для формирования множества: " << endl;
	getchar();
	gets_s(string, 256);
	Set s5(string);
	cout << "s5: ";
	s5.Print(); cout << endl;
	cout << "_______________________";
	s5 = s5 * s1;
	cout << "\ns5 * s1: " << s5 << endl;
	cout << "_______________________";
	s5 = s5 + t2;
	cout << "\ns5 + t2: " << s5 << endl;
	cout << "_______________________";
	Set s6 = s1;
	cout << "\ns6: " << s6 << endl;
	if (s5 == s6) {
		cout << "s5 = s6" << endl;
	}
	else { cout << "s5 != s6" << endl; }
		
	return 0;
}

