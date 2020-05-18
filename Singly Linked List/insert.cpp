/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;	//global

void insertAtEnd(int data) {  //Inserting at the end of the list
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		Node *ptr = new Node;
		ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void insertAtBeg(int data) {  //Inserting at the beginning of list
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
}

void insertAfter(int ele, int data) {   //Inserting after any particular element
	Node *temp = new Node;
	Node *ptr = new Node;
	temp->info = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}
	ptr = head;
	while (ptr->next != NULL and ptr->info != ele) {
		ptr = ptr->next;
	}
	if (ptr->info != ele) {
		cout << "Element not found." << endl;
		return;
	}
	temp->next = ptr->next;
	ptr->next = temp;
}

void insertatNth(int pos, int data) {   //Inserting at any given position
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	if (pos == 1) {
		temp->next = head;
		head = temp;
		return;
	}
	if (pos < 1) {
		return;
	}
	Node *ptr = head;
	for (int i = 0; i < pos - 2; i++) {
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next = temp;
}

void insertinSortedList(int data) {   Inserting in the sorted list. Make sure, the list is sorted.
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	Node *ptr = head;
	Node *pptr = NULL;
	while (ptr != NULL and ptr->info < data) {
		pptr = ptr;
		ptr = ptr->next;
	}
	if (pptr == NULL) {
		temp->next = head;
		head = temp;
		return;
	}
	temp->next = pptr->next;
	pptr->next = temp;
}

void display() {    //Displaying the list
	if (head == NULL) {
		cout << "Empty" << endl;
	} else {
		Node *ptr = new Node;
		ptr = head;
		while (ptr != NULL) {
			cout << ptr->info << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
}

int main() {
/* #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("./output.txt", "w", stdout);
#endif  */

	display();
	insertAtEnd(30);
	display();
	insertAtBeg(20);
	display();
	insertAtBeg(10);
	display();
	insertAfter(30, 50);
	display();
	insertatNth(1, 5);
	display();
	insertatNth(3, 15);
	display();
	insertatNth(7, 65);
	display();
	insertinSortedList(70);
	display();
	insertinSortedList(35);
	display();

	return 0;
}

/*OUTPUT

Empty
30 
20 30 
10 20 30 
10 20 30 50 
5 10 20 30 50 
5 10 15 20 30 50 
5 10 15 20 30 50 65 
5 10 15 20 30 50 65 70 
5 10 15 20 30 35 50 65 70 

*/
