/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *last = NULL;	//global

void deleteFirst() {	//Deleting first element from the list
	if (last == NULL)
		return;
	Node *ptr = last;
	if (last->next == ptr) {
		last = NULL;
		free(ptr);
		return;
	}
	ptr = last->next;
	last->next = ptr->next;
	free(ptr);
}

void deleteEnd() {	//Deleting end element from the list
	if (last == NULL)
		return;
	Node *ptr = last->next;
	if (ptr == last) {
		last = NULL;
		free(ptr);
		return;
	}
	Node *pptr = new Node;
	while (ptr != last) {
		pptr = ptr;
		ptr = ptr->next;
	}
	pptr->next = last->next;
	last = pptr;
	free(ptr);
}

void deleteElement(int ele) {	//Deleting any particular element from the list
	if (last == NULL)	//if list is empty
		return;

	Node *ptr = last->next;
	if (ptr->info == ele) {	//if element is at beginning
		deleteFirst();
		return;
	}
	Node *pptr = new Node;

	do {
		if (ptr->info == ele) {		//if element is between first and last element
			pptr->next = ptr->next;
			if (last == ptr)	//if element is at last
				last = pptr;
			free(ptr);
			return;
		}
		pptr = ptr;
		ptr = ptr->next;
	} while (ptr != last->next);
}

void insertAtEnd(int data) {	//Inserting at the end of the list
	Node *temp = new Node;
	temp->info = data;
	if (last == NULL) {
		last = temp;
		last->next = last;
	}
	else {
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void display() {	//Displaying the list
	Node *ptr;
	if (last == NULL)
		cout << "Empty" << endl;
	ptr = last->next;
	do {
		cout << ptr->info << " ";
		ptr = ptr->next;
	} while (ptr != last->next);
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(50);
	insertAtEnd(60);
	display();
	deleteFirst();
	display();
	deleteEnd();
	display();
	deleteElement(50);
	display();

	return 0;
}

/*OUTPUT
10 20 30 40 50 60 
20 30 40 50 60 
20 30 40 50 
20 30 40 

*/
