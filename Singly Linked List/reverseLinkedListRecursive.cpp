/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;

Node* reverseRecursiveMethod1(Node *head) {
	if (head == NULL or head->next == NULL)
		return head;
	Node *rest_head = reverseRecursiveMethod1(head->next);
	Node *rest_tail = head->next;
	rest_tail->next = head;
	head->next = NULL;
	return rest_head;
}

Node* reverseRecursiveMethod2(Node *current, Node *previous) {
	if (current == NULL)
		return previous;
	Node *following = current->next;
	current->next = previous;
	return reverseRecursiveMethod2(following, current);
}


void insert(int data) {
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		Node *ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void display() {
	if (head == NULL) {
		cout << "Empty" << endl;
		return;
	}
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
	cout.tie(0);


	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	display();
	head = reverseRecursiveMethod1(head);
	display();
	head = reverseRecursiveMethod2(head, NULL);
	display();

	return 0;
}

/*OUTPUT

10 20 30 40 50 
50 40 30 20 10 
10 20 30 40 50 

*/
