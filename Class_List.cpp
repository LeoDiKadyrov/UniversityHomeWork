#include<iostream>
#include<locale.h>

using namespace std;

class Usel
{
	int key;
	Usel* prev, * next;

public:
	Usel()
	{
		key = 0; prev = NULL; next = NULL;
	}
	Usel(int k, Usel* pr, Usel* nxt)
	{
		key = k; prev = pr; next = nxt;
	}
	int& Key() { return key; }
	Usel*& Prev() { return prev; }
	Usel*& Next() { return next; }
	friend class List;
};

class List
{
	Usel* head, * tail;

public:
	List();//��������� ��������� ������ � �����
	List(int); //������ �� m ��������� ���������
	List(int*, int); //������ �� ������������������
	List(List&);
	~List();
	List& operator= (const List&);

	void AddAfter(int, Usel*); //���������� ����� ��������� ����
	void AddToTail(int); //���������� � �����
	void AddToHead(int); //���������� � ������
	void AddToHead(List);
	void AddToTail(List);

	void Del(Usel*); //�������� �� ���������
	void DelTail();  //�������� ������
	void DelHead();  //�������� ������

	Usel* FindKey(int); //����� �� �����
	Usel* FindPos(int); //����� �� �������

	bool Empty(); //�������� ������ �� �������
	bool NotEmpty();
	void Clear(); //������� ��� ����� ��������� ������ � ������

	bool operator == (List);
	bool operator != (List);

	Usel* Max();
	Usel* Min();

	void Print();
	void Scan(int); //������������ ������ �� n ���������

	friend ostream& operator<< (ostream& r, List& x);
	friend istream& operator>> (istream& r, List& x);
};

//_________________________________
List::List()   //��������� ��������� ������ � �����
{
	head = new Usel;
	tail = new Usel(0, head, 0);
	head->next = tail;
}

List::List(int m) //������ �� m ��������� ���������
{
	head = new Usel;
	tail = new Usel(0, head, 0);
	head->next = tail;
	for (int i = 0; i < m; i++)
	{
		int x = rand() % 100;
		AddToTail(x);
	}
}

List::List(int* a, int n) //������ �� ������������������
{
	head = new Usel;
	tail = new Usel(-1, head, NULL);
	head->next = tail;

	for (int i = 0; i < n; i++)
		AddToTail(a[i]);
}

List::List(List& x)
{
	head = new Usel;
	tail = new Usel(0, head, 0);
	head->next = tail;

	Usel* s = x.head->next;
	while (s != x.tail)
	{
		AddToTail(s->key);
		s = s->next;
	}
}

List::~List()
{
	Clear(); delete head; delete tail;
}


List& List::operator= (const List& x)
{
	if (this != &x)
	{
		Clear();
		Usel* s = x.head->next;
		while (s != x.tail)
		{
			AddToTail(s->key);
			s = s->next;
		}
	}
	return *this;
}

bool List::operator==(List x) {
	Usel* q1 = this->head->next, *q2 = x.head->next;
	if (q1 == this->tail && q2 == x.tail) return true;

	while (q1 != this->tail && q2 != x.tail) {
		if (q1->key != q2->key) return false;

		q1 = q2->next;
		q2 = q2->next;
	}
	if (q1 == this->tail && q2 == x.tail) return true;

	return false;
}

bool List::operator!=(List x) {
	if (*this == x) {
		return false;
	} return true;
}

void List::AddAfter(int k, Usel* pr) //���������� ����� ��������� ����
{
	Usel* q = new Usel(k, pr, pr->next);
	pr->next = q;
	q->next->prev = q;
}

void List::AddToTail(int x) //���������� � �����
{
	AddAfter(x, tail->prev);
}

void List::AddToHead(int x) //���������� � ������
{
	AddAfter(x, head);
}

void List::AddToHead(List x) {
	Usel* q = x.tail->prev;
	while (q != x.head)
	{
		AddToHead(q->key);
		q = q->prev;
	}
}

void List::AddToTail(List x) {
	Usel* q = x.head->next;
	while (q != x.tail)
	{
		AddToTail(q->key);
		q = q->next;
	}
}

void List::Del(Usel* p) //�������� �� ���������
{
	p->prev->next=p->next;
	p->next->prev=p->prev;
	delete p;
}

void List::DelTail()  //�������� ������
{
	Del(tail->prev);
}

void List::DelHead()  //�������� ������
{
	Del(head->next);
}

Usel* List::FindKey(int x) //����� �� �����
{
	Usel* q = this->head->next;
	while (q != this->tail) {
		if (q->key == x) {
			return q;
		}
		q = q->next;
	}
	cout << "������� �� � ������" << endl;
	return 0;
}

Usel *List::FindPos(int pos) //����� �� �������
{
	Usel *q = this->head->next;
	int i = 0;
	while (q != this->tail && i < pos)
	{
		i++; q = q->next;
	}
	if (i <= pos) {
		return q;
	} 
	cout << "out of bounds\n";
	return 0;
}

bool List::Empty() //�������� ������ �� �������
{
	if (this->head->next == this->tail) {
		return true;
	} 
	return false;
}

bool List::NotEmpty() //�������� ������ �� �������
{
	if (Empty()) {
		return false;
	}
	return true;
}

Usel* List::Max() {
	Usel *M = NULL;
	Usel *q = head->next;
	if (q == tail) {
		cout << "������ ����" << endl;
		return M;
	}
	M = q; q = q->next;
	while (q != tail) {
		if (q->key > M->key) {
			M = q;
		} 
		q = q->next;
	}
	return M;
}

Usel* List::Min() {
	Usel *M = NULL;
	Usel *q = head->next;
	if (q == tail) {
		cout << "������ ����" << endl;
		return M;
	}
	M = q; q = q->next;
	while (q != tail) {
		if (q->key < M->key) {
			M = q;
		}
		q = q->next;
	}
	return M;
}

void List::Clear() //������� ��� ����� ��������� ������ � ������
{
	while (head->next != tail) DelHead();
}

void List::Print()
{
	Usel* p = head->next;
	while (p != tail)
	{
		cout << p->key << ' ';
		p = p->next;
	}
}

void List::Scan(int n) //������������ ������ �� n ���������
{
	Clear();
	int i, x;
	cout << "������� �������� ������: ";
	for (i = 0; i < n; i++)
	{
		cin >> x;
		AddToTail(x);
	}
}

ostream& operator<< (ostream& r, List& x)
{
	x.Print(); return r;
}

istream& operator>> (istream& r, List& x) {
	int n; cout << "������� ���-�� ��������� � ������: ";
	cin >> n;
	x.Scan(n);
	return r;
}

int main()
{
	setlocale(LC_ALL, "russian");
	List s1;
	s1.AddToHead(1);
	s1.AddToTail(10);
	cout << "\n1_____________________\n";
	s1.Print();
	cout << "\n\n2_____________________\n";
	List s2(6);
	cout << "s2: " << s2 << endl;
	Usel* max, *min;
	max = s2.Max(); min = s2.Min();
	cout << "max: " << max->Key() << endl;
	cout << "min: " << min->Key() << endl;
	cout << "\n3_____________________\n";
	Usel* found = s2.FindPos(2);
	cout << "������ ������� � s2: " << found->Key() << endl;
	s2.Del(found);
	cout << "s2 ��� 2-�� ��������: " << s2;
	cout << "\n\n4_____________________\n";
	found = s2.FindPos(6);
	cout << "������ ������� � s2: " << found->Key() << endl;
	s2.DelTail();
	cout << "s2 ��� �������� � ������: " << s2;
	cout << "\n\n5_____________________\n";
	List s3;
	s3 = s1;
	cout << "s1==s3?\n";
	if (s1 == s3)
	{
		cout << "s1 = s3";
	}
	else
		cout << "s1 != s3" << endl;

	found = s3.FindKey(15);
	if (found != 0)
	{
		cout << found->Key() << endl;
	}
	cout << "\n6_____________________\n";
	s3.DelHead();
	found = s3.FindKey(10);
	s3.Del(found);
	cout << "�������� s3 �� �������\n";
	if (s3.Empty())
	{
		cout << "s3 ����";
	}
	else
	{
		cout << "s3 �� ����";
	}
	cout << "\n\n7_____________________\n";
	int mas[6];
	for (int i = 0; i < 6; i++)
	{
		mas[i] = rand() % 20;
	}
	List s4(mas, 6);
	cout << "s4: " << s4 << endl;
	found = s4.FindKey(25);
	cout << "�������� �������� 25 � s4" << endl;
	if (found != 0)
	{
		cout << found->Key() << endl;
	}
	found = s4.FindPos(3);
	s4.AddAfter(25, found);
	cout << "s4 ����� ���������� 25, ��������� � ������: " << s4;
	cout << "\n\n8_____________________\n";
	List s5(s2);
	cout << s5 << endl;
	cout << "�������� �� ������� �������� 4 � s5" << endl;
	if (s5.FindKey(4))
	{
		cout << "\n���";
		found = s5.FindKey(4);
		s5.Del(found);
	}
	else
	{
		s5.AddToTail(4);
	}
	cout << s5;
	cout << "\n\n9_____________________\n";
	cin >> s5;
	cout << "�������� �� ��������� s4 � s5\n";
	if (s4 == s5)
	{
		cout << "s4 = s5";
	}
	else
		cout << "s4 != s5";
	cout << "\n\n10_____________________\n";
	cout << "s4: " << s4 << endl;
	cout << "s1: " << s1 << endl;
	s5.AddToTail(s4);
	s5.AddToHead(s1);
	cout << s5;
	return 0;
}