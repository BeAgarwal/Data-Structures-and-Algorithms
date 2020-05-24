/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *third = NULL;

Node *newNode(int data) {
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	return temp;
}

Node *merg(Node *a, Node *b) {
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	Node *head = NULL;
	Node *tail = NULL;
	if (a->info <= b->info) {
		head = tail = a;
		a = a->next;
	} else {
		head = tail = b;
		b = b->next;
	}
	while (a != NULL and b != NULL) {
		if (a->info <= b->info) {
			tail->next = a;
			tail = a;
			a = a->next;
		} else {
			tail->next = b;
			tail = b;
			b = b->next;
		}
	}
	if (a == NULL)
		tail->next = b;
	else
		tail->next = a;
	return head;
}

Node *insert(Node *head, int data) {
	Node *temp = newNode(data);
	if (head == NULL) {
		head = temp;
	}
	else {
		Node *ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	return head;
}

void display(Node *head) {
	if (head == NULL) {
		cout << "Empty" << endl;
		return;
	}
	Node *ptr = head;
	while (ptr != NULL) {
		cout << ptr->info << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	first = insert(first, 3);
	first = insert(first, 5);
	first = insert(first, 7);
	first = insert(first, 8);
	first = insert(first, 9);
	display(first);

	second = insert(second, 4);
	second = insert(second, 6);
	second = insert(second, 10);
	second = insert(second, 12);
	second = insert(second, 19);
	display(second);

	third = merg(first, second);
	display(third);

	return 0;
}
