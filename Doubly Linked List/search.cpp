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

int search(int data) {
	Node *ptr = head;
	int pos = 1;
	while (ptr != NULL) {
		if (ptr->info == data) {
			return pos;
		}
		pos += 1;
		ptr = ptr->next;
	}
	return -1;
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
	cout << search(50);

	return 0;
}

/*OUTPUT
10 20 30 40 50 
5
*/
