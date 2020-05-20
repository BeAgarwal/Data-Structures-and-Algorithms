/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;	//global

void NthNodeFromEnd(int n) {	//Finding nth node from the end of the list
	if (head == NULL)
		return;
	Node *temp = new Node;
	int len = 0;
	for (temp = head; temp != NULL; temp = temp->next)
		len++;
	if (len < n)
		return;
	temp = head;
	for (int i = 1; i < len - n + 1; i++)
		temp = temp->next;
	cout << temp->info << endl;
}

void NthNodeFromEndMethod2(int n) {	//Efficient(Optimized) method than before
	if (head == NULL)
		return;
	Node *fast = head;
	for (int i = 0; i < n; i++) {
		if (fast == NULL)
			return;
		fast = fast->next;
	}						//Now fast pointer will be n nodes ahead from head

	Node *slow = head;
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
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

	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(50);
	display();
	NthNodeFromEnd(2);
	NthNodeFromEndMethod2(4);
	return 0;
}

/*OUTPUT
10 20 30 40 50 
40
20
*/
