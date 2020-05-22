/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;

void reverseIterativeMethod() {
	std::vector<int> v;
	for (Node *current = head; current != NULL; current = current->next) {
		v.push_back(current->info);
	}
	for (Node *current = head; current != NULL; current = current->next) {
		current->info = v.back();
		v.pop_back();
	}
}

void reverse() {
	Node *current = head;
	Node *previous = NULL;
	while (current != NULL) {
		Node *following = current->next;
		current->next = previous;
		previous = current;
		current = following;
	}
	head = previous;
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
	reverseIterativeMethod();
	display();
	reverse();
	display();

	return 0;
}

/*OUTPUT

10 20 30 40 50 
50 40 30 20 10 
10 20 30 40 50 

*/
