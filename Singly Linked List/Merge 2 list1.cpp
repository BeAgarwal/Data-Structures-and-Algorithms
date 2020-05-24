/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *first = NULL;
Node *second = NULL;
Node *third = NULL;

Node *newNode(int data) {
	Node *temp = new Node;
	temp->info = data;
	temp->next = NULL;
	return temp;
}

Node *insert(Node *head, int data) {
	Node *temp = newNode(data);
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
	return head;
}

Node *merge(Node *first, Node *second) {
	Node *x = first;
	Node *y = second;
	while (1) {
		if (x == NULL and y == NULL) {
			break;
		}
		if (x != NULL and y != NULL) {
			if (x->info < y->info) {
				third = insert(third, x->info);
				x = x->next;
			}
			else {
				third = insert(third, y->info);
				y = y->next;
			}
		}
		if (x == NULL and y != NULL) {
			third = insert(third, y->info);
			y = y->next;
		}
		if (x != NULL and y == NULL) {
			third = insert(third, x->info);
			x = x->next;
		}

	}
	return third;
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

	first = insert(first, 3);
	first = insert(first, 5);
	first = insert(first, 7);
	first = insert(first, 8);
	first = insert(first, 9);
	display(first);

	second = insert(second, 4);
	second = insert(second, 6);
	second = insert(second, 10);
	second = insert(second, 12);
	second = insert(second, 18);
	display(second);

	third = SortedMerge(first, second);
	display(third);


	return 0;
}

/*OUTPUT
3 5 7 8 9 
4 6 10 12 18 
3 4 5 6 7 8 9 10 12 18 
*/
