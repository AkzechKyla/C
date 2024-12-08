/* Sample linked list */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *nextptr;
};

struct node *currentnode, *head, *tail;

//struct node sample;

int main() {
	//printf("%p\n", currentnode);
	
	currentnode = malloc(sizeof(struct node));
	currentnode->data = 5;
	currentnode->nextptr = NULL;
	head = currentnode;
	tail = currentnode;
	
	//sample.data = 6;
	
	//printf("%d\n", currentnode);
	//printf("%d\n", currentnode->data);

	currentnode = malloc(sizeof(struct node));
	currentnode->data = 2;
	currentnode->nextptr = NULL;
	
	tail->nextptr = currentnode;
	tail = currentnode;

	currentnode = malloc(sizeof(struct node));
	currentnode->data = 10;
	currentnode->nextptr = NULL;
	
	tail->nextptr = currentnode;
	tail = currentnode;

	currentnode = malloc(sizeof(struct node));
	currentnode->data = 50;
	currentnode->nextptr = NULL;
	
	tail->nextptr = currentnode;
	tail = currentnode;
	
	// display the contents of the linked list
	currentnode = head;
	while (currentnode != NULL) {
		printf("%d\n", currentnode);
		printf("%d\n", currentnode->data);
		currentnode = currentnode->nextptr;
	}
	
	return 0;
}
