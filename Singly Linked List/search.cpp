/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;

int search(int data) {  //Search a particular element in a list
	Node *ptr = head;
	int pos = 0;
	while (ptr != NULL) {
		if (ptr->info == data) {
			return pos;
		}
		ptr = ptr->next;
		pos += 1;
	}
	return -1;
}


void insertAtEnd(int data) {  //Inserting
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

void display() {    //Displaying
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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("./output.txt", "w", stdout);
#endif

	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(55);
	insertAtEnd(60);
	insertAtEnd(70);
	insertAtEnd(80);
	display();
	cout << search(10) << endl;
	cout << search(80) << endl;


	return 0;
}

/*OUTPUT

10 20 30 40 55 60 70 80 
0
7

*/
