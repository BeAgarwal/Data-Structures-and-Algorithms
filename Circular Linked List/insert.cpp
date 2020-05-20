/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *last = NULL;	//global

void insertAtBeg(int data) {	//Inserting at beginning of the list
	Node *temp = new Node;
	temp->info = data;
	if (last == NULL) {
		last = temp;
		last->next = last;
	}
	else {
		temp->next = last->next;
		last->next = temp;
	}
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

void insertAfter(int ele, int data) {	//Inserting after any particular element in the list
	if (last == NULL) {
		return;
	}
	Node *temp = new Node;
	temp->info = data;
	Node *ptr = last->next;
	do {
		if (ptr->info == ele) {
			temp->next = ptr->next;
			ptr->next = temp;

			if (ptr == last)
				last = temp;

			return;
		}
		ptr = ptr->next;
	} while (ptr != last->next);
}

void insertBefore(int ele, int data) {	//Inserting before any particular element in the list
	if (last == NULL)
		return;

	Node *temp = new Node;
	temp->info = data;
	Node *ptr = last->next;
	Node *pptr = last;
	do {
		if (ptr->info == ele) {
			temp->next = pptr->next;
			pptr->next = temp;
		}
		pptr = ptr;
		ptr = ptr->next;
	} while (ptr != last->next);
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
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	insertAtBeg(20);
	insertAtBeg(10);
	insertAtEnd(40);
	insertAtEnd(50);
	insertAtEnd(70);
	display();
	insertAfter(20, 30);
	display();
	insertBefore(70, 60);
	display();


	return 0;
}

/*OUTPUT
10 20 40 50 70 
10 20 30 40 50 70 
10 20 30 40 50 60 70 

*/
