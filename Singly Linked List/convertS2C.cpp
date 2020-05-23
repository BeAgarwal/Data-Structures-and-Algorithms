/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void convert() {
	if (head == NULL)
		return;
	Node *ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = head;
	tail = ptr;
}

void insert(int data) {
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
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
}

void display() {
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

void displayCircularList() {
	Node *ptr = tail->next;
	do {
		cout << ptr->info << " ";
		ptr = ptr->next;
	} while (ptr != tail->next);
	cout << endl;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	insert(123);
	insert(110);
	insert(70);
	insert(90);
	insert(115);
	insert(145);
	display();
	convert();
	cout << "Circular List" << endl;
	displayCircularList();

	return 0;
}
