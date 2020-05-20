/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;	//global

void findMiddle() {		//Finding middle element in the list
	if (head == NULL)
		return;
	Node *slow = head, *fast = head;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << slow->info << endl;
}

void insertAtEnd(int data) {	//Inserting at the end of list
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}
	Node *ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	findMiddle();
	insertAtEnd(10);
	display();
	findMiddle();

	insertAtEnd(20);
	display();
	findMiddle();

	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(50);
	display();
	findMiddle();

	insertAtEnd(60);
	display();
	findMiddle();
	return 0;
}

/*OUTPUT
10 
10
10 20 
20
10 20 30 40 50 
30
10 20 30 40 50 60 
40
*/
