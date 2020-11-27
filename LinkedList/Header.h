#pragma once
#include <conio.h>
#include <iostream>

using namespace std;

struct node
{
	int key;
	node* next;
};

struct list
{
	node* head;

	list() { head = new node; head->next = 0; }
	~list() { Clear(); delete head; }

	void AddToTail(int k);
	void AddToHead(int k);
	void AddAfter(int k, node* pr);
	void FormRand(int n);
	void DelHead();
	void DelTail();
	void DelAfter(node* pr);
	node* FindKey(int k);

	node* FindPos(int pos)
	{
		node* p=head;
		int i = 1;
		while (p->next && i < pos)
		{
			p = p->next;
			i++;
		}
		if (p->next) return p;
		
		else { puts ("search error"); return NULL; }
	}
	bool Empty()
	{
		if (head->next)
			return 0; 
		return 1;
	}
	void PrintList();
	void Clear();
};

void list::AddAfter(int k, node* pr)
{
	node* q = new node;
	q->key = k;
	q->next = pr->next;
	pr->next = q;

}

void list::AddToTail (int k)
{
	node* p = head;
	while (p->next) p = p->next;
	AddAfter(k, p);
}

void list::AddToHead(int k)
{
	AddAfter(k, head);
}

void list::DelAfter(node* pr)
{
	if (pr->next == NULL) puts("Node is tail");
	else 
	{
		node* q = pr->next;
		pr->next = q->next;
		delete q;
	}
}

void list::DelHead()
{
	DelAfter(head);
}

void list::DelTail()
{
	if (head->next == NULL) puts("list is empty");
	else
	{
		{
			node* p = head;
			while (p->next->next != 0) p = p->next;
				DelAfter(p);
		}
	}
}

void list::FormRand(int n)
{
	int x;
	for (int i = 1; i <= n; i++)
	{
		x = rand() % 100;
		AddToTail(x);
	}
}

node* list::FindKey(int k)
{
	node* p = head;
	while (p->next != NULL && p->next->key != k)
	
		p = p->next;
		if (p->next == NULL) return NULL;
		else return p;
}

void list::PrintList()
{
	node* p = head->next;
	while (p) 
	{
		cout << p->key << ' ';
		p = p->next;
	}
}

void list::Clear()
{
	while (head->next) DelHead();
}
