	return head->key;
}

bool Stack::Empty() {
	if (head == NULL)
		return true;
	return false;
}

void Stack::Output() {
	Node* p;
	for (p = head; p != 0; p = p->next) cout << p->key << " ";
}