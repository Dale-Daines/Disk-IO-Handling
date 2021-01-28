//Dale Daines - 16998416 - System Programming 1 - Assignment 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_list.h"


//Creates a new item
POINTER newItem() {
	POINTER temp;
	temp = malloc(sizeof(struct iorb));
	temp->link = NULL;
	return temp;
}

//Adds an item to the linked list and sets priority
POINTER addLink(POINTER head, int priority) {
	POINTER temp;
	temp = newItem();
	temp->base_pri = priority;
	if ( head == NULL ) {
		head = temp;
	}
	else {
		POINTER traverse = head;
		while ( traverse->link != NULL ) {
			traverse = traverse->link;
		}
		traverse->link = temp;
	}
	return head;
}

//Creates a linked list of defined size
POINTER build_list(POINTER head, int size) {
	int i;
	for (i = 0; i < size; i++) {
		int priority = rand() % 100;
		head = addLink(head, priority);
	}
	return head;
}

//Displays all items in the linked list
void display_list(POINTER head) {
	POINTER traverse = head;
	int i = 1;
	while ( traverse != NULL ) {
		printf("Item %d Priority:	", i);
		printf("%d\n", traverse->base_pri);
		traverse = traverse->link;
		i++;
	}
}

//Deletes the list and frees memory allocated for it
POINTER delete_list(POINTER head) {
	POINTER traverse = head, previous;
	while ( traverse->link != NULL ) {
		previous = traverse;
		traverse = traverse->link;
		free(previous);
	}
	free(traverse);
	head = NULL;
	printf("List Deleted\n\n");
	return head;
}

//Series of prompts to run the program
//Asks if you want to Build List, Sort List, Display List or Exit
void run_program(POINTER head) {
	int input = 0, first = 0;
	//Until exit code given repeat prompts
	while ( input != -1 ) {
		if ( first == 0 ) {
			printf("What would you like to do?\n1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.\n");
			first = 1;
		}
		else
			printf("What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.\n");
		scanf("%d", &input);
		//Function 1 is Build List of custom length
		if ( input == 1 ) {
			int items = 0;
			if ( head != NULL ) {
				int del = 0;
				printf("Would you like to delete the old list?\n1: Yes, 2: No\n");
				scanf("%d", &del);
				if ( del == 1 ) {
					head = delete_list(head);
				}
			}

			printf("How many items would you like?\n");
			scanf("%d", &items);
			if ( items > 0 ) {
				head = build_list(head, items);
				printf("List Built.\n\n");
			}
			else
				printf("Too Few Items.\n");

		}

		//Test to see if a list was built to use
		if ( ( input == 2 || input == 3 || input == 4 ) && head == NULL )
			printf("Please build list before attempting to sort, display or delete.\n");
		//Displays the list
		if ( head != NULL && input == 2) {
			printf("\n\n");
			display_list(head);
			printf("\n\n");
		}

		//Sorts the list in Ascending or Descending order
		if ( head != NULL && input == 3 ) {
			int order = -1;
			printf("Would you like to sort Ascending or Descending?.\n0: Ascending, 1: Descending\n");
			while ( order != 1 && order != 0 ) {
				scanf("%d", &order);
				if ( order == 1 || order == 0) {
					head = sort_list(head, order);
					printf("List Sorted.\n\n");
				}
			}
		}

		//Deletes the list and frees memory
		if ( head != NULL && input == 4 ) {
			head = delete_list(head);
		}

	}
}

int main() {
	srand(time(NULL));
	setbuf(stdout, NULL);
	POINTER head;
	head = (POINTER) NULL;
	run_program(head);
	return 0;
}
