#include "Stack.h"
#define NULL 0

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* temp = s->head;
	while (s->head != NULL) {
		s->head = s->head->next;
		temp->data = NULL; // delete the data
		free(temp);
		temp = s->head;
	}
}

void push(Stack* s, char data)
{
	charNode* newVar = (charNode*)malloc(sizeof(charNode));
	if (newVar == NULL)
		printf("allocation failed");
	if (s->head == NULL) {
		s->head = newVar;
		newVar->next = NULL;
		newVar->data = data;
	}
	else {
		newVar->data = data;
		newVar->next = s->head;
		s->head = newVar;
	}
	
}

char pop(Stack* s)
{
	char tempo;
	tempo = s->head->data;
	charNode* temp = s->head;
	s->head = s->head->next;
	temp->data = NULL;
	free(temp);
	temp = NULL;
	return tempo;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;
	else return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* HelpS = (Stack*)malloc(sizeof(Stack));
	if (HelpS == NULL)
		printf("allocation failed");
	int i = 0, counter = 0;
	while (sentence[i] != '\0') {
		if (sentence[i] != '#')
			printf("%c", sentence[i]);
		else {
			counter++; // count the number of #
			i++;
			int intemp = 0;
			while (sentence[i] != '#') {
				push(HelpS, sentence[i]); // Push the items between 2 asterisks to new stack
				i++;
				intemp++; // count how much letters between 2 asterisks
			}
			counter++; // Here we get to the second asterisk
			if (counter % 2 == 0 && counter != 0) { // if you get to another asterisks (the second) - start print 
				while (intemp != 0) {
					printf("%c", HelpS->head->data);
					pop(HelpS);
					intemp--;
				}
			}
			
		}
		i++;
		
	}
	free(HelpS);
}

int isPalindrome(Stack* s)
{
	if (s->head == NULL) 
		return 1;

	int size = 0, counter = 1;
	charNode* temp1 = s->head;
	charNode* temp2 = s->head;

	while (temp1 != NULL) {
		size++;
		temp1 = temp1->next;
	}
	temp1 = s->head;
	for (int i = 1; i <= (size + 1) / 2; i++) {
		for (int j = 1; j < size; j++) {
			temp2 = temp2->next;
		}
		if (temp2->data != temp1->data) {
			return 0;
		}
		temp1 = temp1->next;
		size -= 2;
		temp2 = temp1;
		if (size == 1 || size == 0) {
			return 1;

		}

	}
}

void rotateStack(Stack* s, int n)
{
	if (n < 0 || s->head == NULL)
		return;
	Stack* temp1 = (Stack*)malloc(sizeof(Stack));
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	if (temp == NULL || temp1 == NULL)
		printf("allocation failed");
	initStack(temp1);
	initStack(temp);
	charNode* temp2 = s->head;
	temp->head = s->head;
	int count = 0;
	while (temp2 != NULL) {
		count++;
		temp2 = temp2->next;
	}
	if (n > count)
	{
		return;
	}
	for (int i = 0; i < count - n; i++) // cut the stack by count - n letters to new stack
	{
		char tav = pop(s);
		push(temp, tav);
	}
	for (int i = 0; i < n; i++) //  cut the stack by n letters to new stack
	{
		char tav = pop(s);
		push(temp1, tav);
	}

	for (int i = 0; i < count - n; i++) // push the items to stack by order
	{
		char tav = pop(temp);
		push(s, tav);
	}
	for (int i = 0; i < n; i++) //push the items to stack by order
	{
		char tav = pop(temp1);
		push(s, tav);
	}
	while (s->head != NULL) // print new stack
	{
		printf("%c\n", s->head->data);
		s->head = s->head->next;
	}
	free(temp);
	free(temp1);
}