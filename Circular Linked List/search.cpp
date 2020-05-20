/*Code is written by Shubham Agarwal. Feel free to contribute.*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int info;
	Node *next;
};

Node *last = NULL;	//global

int search(int data) {	//Search an element in the list
	Node *ptr = last->next;
	int cnt = 1;
	do {
		if (ptr->info == data) {
			return cnt;
		}
		cnt += 1;
		ptr = ptr->next;
	} while (ptr != last->next);
	return -1;
}

void insertAtEnd(int data) {	//Inserting at the end of the list
	Node *temp = new Node;
	temp->info = data;
	if (last == NULL) {
		last = temp;
		last->next = last;
	}
	else {
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void display() {	//Displaying the list
	Node *ptr;
	if (last == NULL)
		cout << "Empty" << endl;
	ptr = last->next;
	do {
		cout << ptr->info << " ";
		ptr = ptr->next;
	} while (ptr != last->next);
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
	insertAtEnd(60);
	display();
	cout << search(40);

	return 0;
}

/*OUTPUT
10 20 30 40 50 60 
4
*/
