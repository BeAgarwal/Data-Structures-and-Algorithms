/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;

Node *segregate() {
	Node *evenStart = NULL;
	Node *evenEnd = NULL;
	Node *oddStart = NULL;
	Node *oddEnd = NULL;
	for (Node *current = head; current != NULL; current = current->next) {
		int data = current->info;

		if (data % 2 == 0) {
			if (evenStart == NULL) {
				evenStart  = evenEnd = current;
			}
			else {
				evenEnd->next = current;
				evenEnd = evenEnd->next;
			}
		}
		else {
			if (oddStart == NULL) {
				oddStart = oddEnd = current;
			}
			else {
				oddEnd->next = current;
				oddEnd = oddEnd->next;
			}
		}
	}
	if (evenStart == NULL or oddStart == NULL) {
		return head;
	}
	evenEnd->next = oddStart;
	oddEnd->next = NULL;
	return evenStart;
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

void display(Node *head) {
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
	insert(13);
	insert(17);
	insert(20);
	insert(5);
	insert(6);
	insert(7);
	display(head);
	Node *even = segregate();
	display(even);

  return 0;
}

/*OUTPUT
10 13 17 20 5 6 7 
10 20 6 13 17 5 7 
*/
