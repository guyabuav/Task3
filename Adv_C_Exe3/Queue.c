#include "Queue.h"
#define NULL 0


/***************** Queue ADT Implementation *****************/
void reverse(Queue *queue);
void initQueue(Queue* q)
{
	q->tail =  NULL; // initialize new queue
	q->head = NULL;
	
}

void destroyQueue(Queue* q)
{
	intNode* temp = q->head;
	while (q->head != NULL) {
		q->head = q->head->next;
		temp->data = 0; // delete the exist data
		free(temp); // free the item
		temp = q->head;
	}
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* New = (intNode*)malloc(sizeof(intNode));
	if (New == NULL)
		printf("allocation failed");
	New->data = data;
	New->next = NULL;
	if (q->head == NULL) { // if the queue is empty
		q->head = New;
		q->tail = New;
	}
	else // if there is items in the queue
	{
		q->tail->next = New;
		q->tail = New;
	}
}

unsigned int dequeue(Queue* q)
{
	int tempd = q->head->data;
	intNode* temp = q->head;
	if (q->head == q->tail) { // if there is only one item in queue
		q->head = NULL;
		q->tail = NULL;
	}
	else {
		// if there are more than one items in queue
		q->head = q->head->next;
	}


	free(temp); // free the item the was removed
	return tempd;
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL) // if the queue is empty return 1, else return 0
		return 1;
	else return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	int NumOfItems = 1;
	if (q == NULL) { // is queue is empty
		printf("There is no queue");
		return;
	}
	intNode* temp1 = q->head;
	intNode* temp2 = q->tail;
	intNode* temp3 = NULL;
	while (temp1 != temp2) {
		temp1 = temp1->next;
		if (temp1->next->next == NULL) { // save the one before last item.
			temp3 = temp1;
			break;
		}
	}
	q->tail->next = q->head;
	q->head = q->tail;
	q->tail = temp3;
	q->tail->next = NULL;
}

void cutAndReplace(Queue* q)
{
	Queue* NewQ1 = (Queue*)malloc(sizeof(Queue));
	if (NewQ1 == NULL) 
		printf("allocation failed");
	initQueue(NewQ1);
	intNode* temp1 = q->head;
	intNode* temp2 = q->tail;
	int QueueCounter = 0; 
	int QueueDataSum = 0; 
	while (q->head != 0) { // count the queue items in queue and the sum of data.
		QueueDataSum += q->head->data;
		q->head = q->head->next;
		QueueCounter++;
	}
	q->head = temp1;
	q->tail = temp2;
	if (QueueCounter % 2 != 0) { // if the queue items are odd - enqueue more item.
		enqueue(q, (QueueDataSum / QueueCounter));
		QueueCounter++;
	}
	for (int i = 0; i < (QueueCounter / 2); i++) { // seperate queue by 2
		enqueue(NewQ1, dequeue(q));
	}
	reverse(q); // reverse half of the q
	q->tail->next = NewQ1->head; // connect between 2 new queues
	q->tail = NewQ1->tail;
	free(NewQ1); 
}

void sortKidsFirst(Queue* q)
{
	intNode* temp1 = q->head;
	intNode* temp2 = q->tail;
	intNode* temp3 = (intNode*)malloc(sizeof(intNode));
	if (temp3 == NULL)
		printf("allocation failed");
	int min = q->head->data;
	int QueueCounter = 0;
	Queue* NewQ = (Queue*)malloc(sizeof(Queue));
	initQueue(NewQ);
	while (q->head != 0) { // count the queue items in queue
		q->head = q->head->next;
		QueueCounter++;
	}
	q->head = temp1;
	q->tail = temp2;
	for (int j = 0; j < QueueCounter; j++) {
		for (int i = 0; i < QueueCounter; i++) {
			if (q->head->data < min && q->head->data != 0) { //find the lowest data and put him in newq
				min = q->head->data;
				temp3 = q->head;
			}
			q->head = q->head->next;

		}
		temp3->data = 0;
		enqueue(NewQ, min); // put in the newq the items be order
		q->head = temp1;
		q->tail = temp2;
		if (q->head->data == NewQ->tail->data) {
			q->head->data = 0;
			min = 1000;
		}
		else
			min = q->head->data;

	}
	q->head = NewQ->head;
	free(temp3);
}


//move the head  to tail
void RotateQueue2(Queue* q) {
	intNode* temp1 = q->head;
	intNode* temp2 = q->tail;
	intNode* temp3 = NULL;
	while (temp1 != temp2) {
		temp1 = temp1->next;
		if (temp1->next->next == NULL) { // save the one before last item
			temp3 = temp1;
			break;
		}
	}
	q->tail->next = q->head;
	q->head = q->head->next;
	q->tail = q->tail->next;
	q->tail->next = NULL;

}

void reverse(Queue *queue) {
	int element;
	if (isEmptyQueue(queue)) { // if the queue is empty, return
		return;
	}
	element = dequeue(queue);
	reverse(queue);
	enqueue(queue, element);
}


void printQueue(Queue* q) {
	intNode* temp1 = q->head;
	intNode* temp2 = q->tail;
	int inter = 1;
	while (temp1 != NULL) {
		printf("the %d item is: %d\n", inter, temp1->data);
		temp1 = temp1->next;
		inter++;
	}

}