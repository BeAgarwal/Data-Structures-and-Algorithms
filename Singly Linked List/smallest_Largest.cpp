/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *head = NULL;

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


void maximumNode() {
	if (head == NULL)
		return;
	int max, min;
	max = head->info;
	min = head-> info;
	for (Node *j = head; j != NULL; j = j->next) {
		if (max < j->info) {
			max = j->info;
		}
		if (min > j->info) {
			min = j->info;
		}
	}
	cout << "Minimum: " << min << endl << "Maximum: " << max;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	insert(123);
	insert(110);
	insert(70);
	insert(90);
	insert(115);
	insert(145);
	display();
	maximumNode();

	return 0;
}

/*OUTPUT

123 110 70 90 115 145 
Minimum: 70
Maximum: 145

*/
