/*Code written by Shubham Agarwal. Feel free to contribute*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *top = NULL;

void push(int data) {
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	if (top == NULL) {
		top = temp;
	}
	else {
		temp->next = top;
		top = temp;
	}
}

void pop() {
	if (top == NULL)
		return;
	Node *ptr = top;
	top = ptr->next;
	free(ptr);
}

int peek() {
	return top->info;
}

void display() {
	if (top == NULL)
		cout << "Empty" << endl;
	Node *ptr = top;
	while (ptr != NULL) {
		cout << ptr->info << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

bool isempty() {
	if (top == NULL)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	push(10);
	push(20);
	push(30);
	push(40);
	display();
	pop();
	display();
	cout << peek() << endl;
	push(50);
	display();
	cout << isempty();

	return 0;
}
