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

void deleteBeg() {	//Deleting first element from the list
	Node *ptr = head;
	if (ptr->next == NULL) {
		head = tail = NULL;
		free(ptr);
	}
	else {
		head = ptr->next;
		head->prev = NULL;
		free(ptr);
	}
}

void deleteEnd() {	//Deleting end element from the list
	Node *ptr = tail;
	if (ptr->prev == NULL) {
		head = tail = NULL;
		free(ptr);
	}
	else {
		tail = ptr->prev;
		tail->next = NULL;
		free(ptr);
	}
}

void deleteElement(int ele) {	//Deleting particular element from the list
	Node *ptr = new Node;
	ptr = head;
	if (ptr->info == ele) {
		head = ptr->next;
		free(ptr);
		return;
	}
	while (ptr->info != ele) {
		ptr = ptr->next;
	}
	if (ptr->next != NULL)
		ptr->next->prev = ptr->prev;

	if (ptr->prev != NULL)
		ptr->prev->next = ptr->next;

	free(ptr);
}

void deleteNth(int pos) {	//Deleting element at particular position
	if (head == NULL or pos <= 0)
		return;

	Node *ptr = head;

	if (pos == 1) {
		head = ptr->next;
		free(ptr);
		return;
	}
	for (int i = 1; ptr != NULL and i < pos; i++)
		ptr = ptr->next;

	if (ptr == NULL)
		return;

	if (ptr->next != NULL)
		ptr->next->prev = ptr->prev;

	if (ptr->prev != NULL)
		ptr->prev->next = ptr->next;

	free(ptr);
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

void display() {	//Displaying a list
	Node *ptr = head;
	while (ptr != NULL) {
		cout << ptr->info << " ";
		ptr = ptr->next;
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

	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(50);
	display();
	deleteNth(4);
	display();
	deleteEnd();
	display();
	deleteBeg();
	display();


	return 0;
}
/*OUTPUT
10 20 30 40 50 
10 20 30 50 
10 20 30 
20 30 

*/
