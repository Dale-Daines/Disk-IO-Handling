//Dale Daines - 16998416 - System Programming 1 - Assignment 1
#include <stdio.h>
#include <stdlib.h>
#include "sort_list.h"



//Sorts the linked list - Ascending = 0, Descending = 2
POINTER sort_list(POINTER head, int operation) {
	if (operation != 1 && operation != 0) {
		printf("Error: Operation must equal 0 or 1.\n");
		return head;
	}

	POINTER traverse = head, prevChange = traverse;
	while ( traverse != NULL ) {
		POINTER search = traverse, operLink = traverse, prevLink = NULL;

		//Search linked list by priority
		while ( search->link != NULL ) {
			if ( operation == 0 && search->link->base_pri < operLink->base_pri) {
							operLink = search->link;
							prevLink = search;
			}
			if ( operation == 1 && search->link->base_pri > operLink->base_pri) {
				operLink = search->link;
				prevLink = search;
			}
			search = search->link;
		}
		//If the first unsorted location is in the correct location do nothing
		if (operLink != traverse) {
			//Replace link to selected item with next item
			prevLink->link = operLink->link;

			//If this is the first item, replace with selected item
			if ( traverse == head ) {
				operLink->link = head;
				head = operLink;
				traverse = head;
			}
			//Otherwise place selected item between last selected and the rest of the list
			else
			{
				prevChange->link = operLink;
				operLink->link = traverse;
				traverse = operLink;
			}
		}
		//Keep track of previous item for linking
		prevChange = traverse;
		traverse = traverse->link;
	}


	return head;
}
