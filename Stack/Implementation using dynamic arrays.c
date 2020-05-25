//Code written by Shubham Agarwal. Feel free to contribute.

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct StackRecord *stack;
#define MINSTACKSIZE 5
#define EMPTYTOS -1

struct StackRecord {
	int capacity;
	int top;
	int *array;
};

stack createStack(int size) {
	stack s;
	if (size < MINSTACKSIZE) {
		printf("\nStack size is too small. Please give the size above 5.");
	}
	else {
		s = (stack)malloc(sizeof(stack));
		s->array = (int*)malloc(sizeof(int) * size);
		s->capacity = size;
		s->top = EMPTYTOS;
		printf("\nStack created.\n");
	}
	return s;
}

int isFull(stack s) {
	return (s->top == s->capacity - 1);
}

int isEmpty(stack s) {
	return (s->top == EMPTYTOS);
}

void push(int element, stack s) {
	if (isFull(s)) {
		printf("\nStack is full. Can't push more element into it.");
	}
	else {
		s->top++;
		s->array[s->top] = element;
		printf("\nElement pushed to stack.");
	}
}

void pop(stack s) {
	if (isEmpty(s)) {
		printf("\nStack is empty. Can't pop any element.");
	}
	else {
		printf("\n%d is popped from the stack.", s->array[s->top]);
		s->top--;
	}
}

void peek(stack s) {
	if (isEmpty(s)) {
		printf("\nStack is empty.");
	}
	else {
		printf("\n%d is at top of the stack.", s->array[s->top]);
	}
}

void displayStack(stack s) {
	int i;
	printf("Displaying elements in a Stack:\n");
	for (i = 0; i <= s->top; i++) {
		printf("%d\t", s->array[i]);
	}
	printf("\n");
}

int main() {
	int choice, data, size;
	stack s;
	s = createStack(10);
	push(10, s);
	push(20, s);
	push(30, s);
	push(40, s);
	push(50, s);
	push(60, s);
	push(70, s);
	push(20, s);
	push(30, s);
	push(40, s);
	push(50, s);
	push(60, s);
	pop(s);
	peek(s);
	isEmpty(s);
	isFull(s);
	displayStack(s);

	return 0;
}
/*OUTPUT


Stack created.

Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Element pushed to stack.
Stack is full. Can't push more element into it.
Stack is full. Can't push more element into it.
40 is popped from the stack.
30 is at top of the stack.Displaying elements in a Stack:
10	20	30	40	50	60	70	20	30	

*/
