/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void reverse(int k) {
	Node *current = head;
	Node *following = NULL;
	Node *prevfirst = NULL;
	bool firstpass = true;
	while (current != NULL) {
		Node *first = current;
		int cnt = 0;
		Node *previous = NULL;
		while (cnt < k and current != NULL) {
			following = current->next;
			current->next = previous;
			previous = current;
			current = following;
			cnt++;
		}
		if (firstpass) {
			head = previous;
			firstpass = false;
		}
		else {
			prevfirst->next = previous;
		}
		prevfirst = first;
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

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	display();
	reverse(2);
	display();
	reverse(3);
	display();

	return 0;
}

/*OUTPUT

1 2 3 4 5 6 7 
2 1 4 3 6 5 7 
4 1 2 5 6 3 7 


*/
