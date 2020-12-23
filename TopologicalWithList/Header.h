#pragma once
#include <iostream>

using namespace std;

struct  Trailer;
struct Lider
{
	int key, count;
	Lider* next;
	Trailer* tr;
	Lider() {
		key = count = NULL;
		next = NULL;
		tr = NULL;
	}
	void AddTrailer(Lider* p);
	void DelTrailer(Lider* p);
	void ReduceCount();
	void IncreaseCount();
};

struct Trailer
{
	Lider* pointer;
	Trailer* next;
	Trailer() {
		pointer = NULL;
		next = NULL;
	}
};

struct Graf
{
	Lider* head;
	Graf();
	~Graf();
	void AddToTail(Lider* p);
	void AddToHead(int k);
	void Del(Lider* p);
	void Exclude(Lider* p);
	Lider* FindKey(int);
	Lider* FindCount(int);
	int FormGraf();
	void SortGraf(Graf&);
	void Clear();
	bool Empty();
};

void Lider::AddTrailer(Lider* p) {
	Trailer* q = new Trailer;
	q->pointer = p;
	q->next = tr;
	tr = q;
}

void  Lider::DelTrailer(Lider* p) {
	Trailer* s, * t = p->tr;
	while (t != NULL) {
		s = t;
		p->tr = t->next;
		t = t->next;
		delete s;
	}
}

void  Lider::ReduceCount()
{
	Trailer* t = tr;
	while (t != NULL) {
		t->pointer->count--;
		t = t->next;
	}
}

Graf::Graf() {
	head = new Lider;
}

Graf:: ~Graf()
{
	Clear();
	delete head;
}

int Graf::FormGraf() {
	int n = 0;
	int x, y;
	Lider* px, * py;
	cout << "enter x and y: ";
	cin >> x >> y;
	while (x && y) {
		if (FindKey(x) == NULL) {
			AddToHead(x);
			px = head->next;
			n++;
		}
		else
			px = FindKey(x);
		if (FindKey(y) == NULL) {
			AddToHead(y);
			py = head->next;
			n++;
		}
		else
			py = FindKey(y);
		py->count++;
		px->AddTrailer(py);
		cout << "enter x and y: ";
		cin >> x >> y;
	}
	return n;
}

void Graf::SortGraf(Graf& newLD) {
	Lider* p, * q;
	while (!Empty())
	{
		p = FindCount(0);
		if (p != NULL)
		{
			Exclude(p);
			newLD.AddToTail(p);
			p->ReduceCount();
		}
		else
		{
			cout << "incorrect graf";
			exit(-1);
		}
	}
	q = newLD.head->next;
	while (q != NULL)
	{
		q->IncreaseCount();
		q = q->next;
	}
}

void Graf::AddToHead(int k)
{
	Lider* t;
	t = new Lider;
	t->key = k;
	t->next = head->next;
	head->next = t;
}

void Graf::AddToTail(Lider* q)
{
	Lider* p = head;
	for (; p->next != NULL; p = p->next);
	p->next = q;
	q->next = 0;
}

void Graf::Del(Lider* p)
{
	if (p->tr != 0) {
		p->DelTrailer(p);
	}
	Lider* t = head;
	while (t->next != p)
	{
		t = t->next;
	}
	if (p->next == NULL) {
		t->next = NULL;
	}
	else
		t->next = p->next;
	delete p;
}

void Graf::Exclude(Lider* q)
{
	Lider* t = head;
	while (t->next != q)
	{
		t = t->next;
	}
	if (q->next == NULL) {
		t->next = NULL;
	}
	else
		t->next = q->next;
}

void Lider::IncreaseCount()
{
	if (tr != 0)
	{
		Trailer* q = tr;
		q->pointer->count++;
		while (q->next != 0)
		{
			q = q->next;
			q->pointer->count++;
		}
		q->pointer->count++;
	}
}

Lider* Graf::FindKey(int k)
{
	Lider* q = head;
	if (!Empty())
	{
		for (q = q->next; (q->key != k) && (q->next != NULL); q = q->next);
		if (q->key != k)
			return 0;
		else
			return q;
	}
	else
	{
		return 0;
	}
}

Lider* Graf::FindCount(int x)
{
	Lider* q = head;
	if (!Empty())
	{
		for (q = q->next; q->count != x && q->next != NULL; q = q->next);
		if (q->count != x)
			return 0;
		else
			return q;
	}
	else
	{
		return 0;
	}
}

void Graf::Clear()
{
	while (!Empty())
		Del(head->next);
}

bool Graf::Empty()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}

