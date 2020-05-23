/*Code is written by Shubham Agarwal. Feel free to contribute.*/

/*Given two numbers represented by two linked lists, 
write a function that returns the sum list. 
The sum list is linked list representation of the addition of two input numbers.
Example: List1: 1->2->3->4          4321
         List2: 3->5->7->8          8753
         Result: 4->7->0->3->1     13074  */

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

Node *addTwoLists(Node* first, Node* second) {
	Node *temp = NULL;
	Node *res = NULL;
	Node *prev = NULL;
	int carry = 0, sum;

	while (first != NULL or second != NULL)
	{
		sum = carry + (first ? first -> info : 0) + (second ? second -> info : 0);

		carry = (sum >= 10) ? 1 : 0;

		sum = sum % 10;
		temp = newNode(sum);

		if (res == NULL) {
			res = temp;
		}
		else {
			prev->next = temp;
		}

		prev = temp;

		if (first != NULL) {
			first = first->next;
		}
		if (second != NULL) {
			second = second->next;
		}
	}

	if (carry > 0) {
		temp = newNode(carry);
		prev->next = temp;
	}
	return res;
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
	first = insert(first, 4);
	first = insert(first, 9);
	first = insert(first, 8);
	display(first);

	second = insert(second, 5);
	second = insert(second, 4);
	second = insert(second, 8);
	second = insert(second, 4);
	second = insert(second, 7);
	second = insert(second, 4);
	display(second);

	third = addTwoLists(first, second);
	display(third);
  
	return 0;
}

/*OUTPUT
3 5 7 4 9 8 
5 4 8 4 7 4 
8 9 5 9 6 3 1 

*/
