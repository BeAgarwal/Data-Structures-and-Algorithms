#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
int S[MAX_SIZE];
int top = -1;

void push(int data) {
	if (top == MAX_SIZE - 1) {
		cout << "Overflow" << endl;
		return;
	}
	S[++top] = data;
}

void pop() {
	if (top == -1) {
		cout << "Empty" << endl;
		return;
	}
	--top;
}

void peek() {
	cout << S[top] << endl;
}

bool isempty() {
	if (top == -1) return true;
	else return false;
}

void display() {
	for (int i = 0; i <= top; i++) {
		cout << S[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (isempty())
		cout << "Empty" << endl;
	else
		cout << "Not empty" << endl;

	push(10);
	push(20);
	push(30);
	push(40);
	display();
	pop();
	display();
	peek();
	push(50);
	display();
	if (isempty())
		cout << "Empty" << endl;
	else
		cout << "Not empty" << endl;

	return 0;
}
