/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *prev, *next;
};

Node *head = NULL;	//global
Node *tail = NULL;


void insertAtBeg(int data) {	//Inserting at the beginning of list
	Node *temp = new Node;
	temp->prev = NULL;
	temp->info = data;
	temp->next = NULL;
	if (head == NULL) {
		head = tail = temp;
	}
	else {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}
void insertAtEnd(int data) {	//Inserting at the end of list
	Node *temp = new Node;
	temp->prev = NULL;
	temp->info = data;
	temp->next = NULL;
	if (head == NULL) {
		head = tail = temp;
	} else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

void insertAtPos(int pos, int data) {	//Inserting at particular position
	Node *temp = new Node;
	temp->prev = NULL;
	temp->info = data;
	temp->next = NULL;
	if (pos == 1) {
		temp->next = head;
		head->prev = temp;
		head = temp;
		return;
	}
	Node *ptr = head;
	for (int i = 0; i < pos - 2; i++) {
		ptr = ptr->next;
	}
	temp->prev = ptr;
	temp->next = ptr->next;
	temp->next->prev = temp;
	ptr->next = temp;
}

void display() {	//Displaying a list
	Node *ptr = head;
	while (ptr != NULL) {
		cout << ptr->info << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

void reverseDisplay() {	//Displaying in a reverse order
	Node *ptr = tail;
	while (ptr != NULL) {
		cout << ptr->info << " ";
		ptr = ptr->prev;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("./output.txt", "w", stdout);
#endif

	insertAtBeg(30);
	insertAtBeg(20);
	insertAtBeg(10);
	insertAtEnd(40);
	insertAtEnd(50);
	display();
	reverseDisplay();
	insertAtPos(4, 35);
	display();
	return 0;
}

/*OUTPUT
10 20 30 40 50 
50 40 30 20 10 
10 20 30 35 40 50 

*/
