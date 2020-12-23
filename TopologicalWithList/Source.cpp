#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	Graf LD, newLD;
	int n, i = 0;
	n = LD.FormGraf();
	LD.SortGraf(newLD);
	int* res = new int[n];
	Lider* t = newLD.head->next;
	while (t != NULL) {
		res[i] = t->key;
		t = t->next;
		i++;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}