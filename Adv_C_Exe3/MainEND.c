#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	//main for checking Stack.c
	char f, e, d;
	char str[] = {"remem#reb# thi#carp s#tice"};
	int i = 0;
	Stack* s = (Stack*)malloc(sizeof(Stack));
	initStack(s);
	push(s, 'f');
	push(s, 'e');
	push(s, 'd');
	pop(s);
	pop(s);
	pop(s);
	printf("Check if POP and PUSH are working:\n");
	if (isEmptyStack(s) == 1)
		printf("The stack is empty\n");
	else printf("The stack is not empty\n");
	push(s, 'n');
	push(s, 'o');
	destroyStack(s);
	printf("Check if isEmptystack is working:\n");
	if (isEmptyStack(s) == 1)
		printf("The stack is empty\n");
	else printf("The stack is not empty\n");
	flipBetweenHashes(str); 
	printf("\n");
	push(s, 'n');
	push(s, 'o');
	push(s, 'o');
	push(s, 'n');
	printf("Check if isPalindrome is working:\n");
	if (isPalindrome(s))
		printf("The stack is palindrom\n"); 
	else printf("This isnot palindrom\n");
	destroyStack(s);
	push(s, 'A');
	push(s, 'B');
	push(s, 'C');
	push(s, 'D');
	push(s, 'E');
	push(s, 'F');
	rotateStack(s, 3);

	//main for checking Queue.c
	Queue* q = (Queue*)malloc(sizeof(Queue));
	initQueue(q);
	enqueue(q, 6);
	enqueue(q, 5);
	dequeue(q);
	dequeue(q);
	if (isEmptyQueue(q) == 1)
		printf("The queue is empty\n");
	else printf("The queue is not empty\n");
	enqueue(q, 6);
	enqueue(q, 1);
	enqueue(q, 5);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 1);
	enqueue(q, 9);
	printf("Items by order: \n");
	printQueue(q);
	printf("Items by small to biggest item: \n");
	sortKidsFirst(q);
	printQueue(q);
	destroyQueue(q);
	if (isEmptyQueue(q) == 1)
		printf("The queue is empty\n");
	else printf("The queue is not empty\n");
	enqueue(q, 6);
	enqueue(q, 1);
	enqueue(q, 5);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 1);
	enqueue(q, 9);
	printf("Items after cut and replace: \n");
	cutAndReplace(q);
	printQueue(q);
	printf("Items after rotate: \n");
	rotateQueue(q);
	printQueue(q);
}