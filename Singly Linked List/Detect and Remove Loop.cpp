/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;

void detectAndRemoveLoop(Node* head)
{
	if (head == NULL || head->next == NULL)
		return;

	Node *slow = head, *fast = head;

	slow = slow->next;
	fast = fast->next->next;

	while (fast && fast->next) {
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast) {
		slow = head;
		while (slow->next != fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		fast->next = NULL;
	}
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
	head->next->next->next->next->next = head->next->next;
	detectAndRemoveLoop(head);
	display();

	return 0;
}

/*OUTPUT
10 20 30 40 50
*/
