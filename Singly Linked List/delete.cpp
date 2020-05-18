/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;  //global

void deleteAtBeg() {  //Deleting first element from the list
	Node *ptr = head;
	head = ptr->next;
	free(ptr);
}

void deleteAtEnd() {  //Deleting last element from the list
	Node *ptr = head;
	Node *pptr = new Node;
	while (ptr->next != NULL) {
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = NULL;
	free(ptr);
}

void deleteElement(int data) {  //Deleting any particular element from the list
	Node *ptr = head;
	Node *pptr = new Node;
	if (ptr->info == data) {
		head = ptr->next;
		free(ptr);
		return;
	}
	while (ptr->info != data) {
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = ptr->next;
	free(ptr);
}

void deleteNthPosition(int pos) { //Deleting an element at particular position
	Node *ptr = head;
	if (pos == 1) {
		head = ptr->next;
		free(ptr);
		return;
	}

	for (int i = 0; i < pos - 2; i++) {
		ptr = ptr->next;
	}
	Node *temp = ptr->next;
	ptr->next = temp->next;
	free(temp);
}

void display() {
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

void insertAtEnd(int data) {
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

int main() {
/* #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("./output.txt", "w", stdout);
#endif  */

	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(55);
	insertAtEnd(60);
	insertAtEnd(70);
	insertAtEnd(80);
	display();
	deleteNthPosition(5);
	display();
	deleteAtBeg();
	display();
	deleteAtEnd();
	display();
	deleteElement(40);
	display();
	deleteElement(70);
	display();
	insertAtEnd(80);
	display();
	deleteElement(60);
	display();
  
	return 0;
}
/* OUTPUT

10 20 30 40 55 60 70 80 
10 20 30 40 60 70 80 
20 30 40 60 70 80 
20 30 40 60 70 
20 30 60 70 
20 30 60 
20 30 60 80 
20 30 80 
*/
