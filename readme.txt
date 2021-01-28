Assignment 1 - System Programming 1
Dale Daines - 16998416

How to compile and run:
	Connect through putty to the university's SCEM computer
	Log onto the computer
	Input the command "cc listSort.c sort_list.c -o listSortRun"
	input the command "./listSortRun"
	The program is now running
	

Pseudo Code
	Set random seed
	Remove print buffer
	Create a head pointer
	Print: 
		What would you like to do?
		1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
	Loop taking input to select from the following options:
		-1 - End the program
			Ends the loop, leading to program ending
		1 - Build the linked list of size specified in input
			Loop below a number of times equal to size
				Each loop randomise priority between 0 - 99
				Create new item with above priority
				Link the item onto the end of the list
			Once loop ends return pointer to head of new list
		2 - Display the current linked list
			Loop while not at the end of the linked list
				Print the position in the list
				Print the priority of the item
				Move on to the next item
		3 - Sort the linked list according to following input:
			0 - Sort according to Ascending order
				Loop while not at the end of the list (traverse)
					Loop through all items after above loop position looking for minimum item
						When minimum item found store it and the item before it in a pointer
					Link item before minimum to item after minimum
					Place minimum item in the location of the traverse loop moving the item replaced forward
					Move traverse forward one item
				Once loop ends return pointer to head of sorted list
				Print "List Sorted"
			1 - Sort according to Descending order
				 Loop while not at the end of the list (traverse)
					Loop through all items after above loop position looking for maximum item
						When maximum item found store it and the item before it in a pointer
					Link item before maximum to item after maximum
					Place maximum item in the location of the traverse loop moving the item replaced forward
					Move traverse forward one item
				Once loop ends return pointer to head of sorted list
				Print "List Sorted"
		4 - Delete the linked list and free memory
			Create a pointer to the head
			Loop along linked list while list still has items
				Previous item = current item
				current item = next item
				Free memory from previous item
			Once loop has ended free memory from last item
			Set head pointer to NULL
			Print "List deleted"
			return NULL head
			
Test Plan
	1. Run the program as above in the "How to compile and run" section
	2. A prompt will appear asking which action you would like to take. First select "Build list" by inputting 1
	3. This will ask you how many items you would like. Input any number E.g. 20
	4. After the list is build input 2 to display the list created
	5. Now we will sort the list. Input 3 to go into the sort list menu
	6. This will ask you whether you want to sort the list ascendingly or descendingly. Input 0 to sort ascendingly
	7. Once it is done sorting input 2 to display the sorted list
	8. Now repeat step 6 and input 1 to sort descendingly
	9. Input 2 to display the descendingly sorted list
	10. Input 4 to delete the list created
	11. Repeat steps 2 - 11 if you wish
	12. End program by entering -1
	
Test Run/Output
	1. 
		What would you like to do?
		1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program
		
		<Input: 1>
	2.
		How many items would you like?
		
		<Input: 20>
	3.
		List Built.

		What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
		
		<Input: 2>
	4.
		Item 1 Priority:	58
		Item 2 Priority:	96
		Item 3 Priority:	78
		Item 4 Priority:	41
		Item 5 Priority:	74
		Item 6 Priority:	93
		Item 7 Priority:	99
		Item 8 Priority:	49
		Item 9 Priority:	6
		Item 10 Priority:	2
		Item 11 Priority:	90
		Item 12 Priority:	1
		Item 13 Priority:	49
		Item 14 Priority:	84
		Item 15 Priority:	1
		Item 16 Priority:	21
		Item 17 Priority:	90
		Item 18 Priority:	90
		Item 19 Priority:	59
		Item 20 Priority:	42


		What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
		
		<Input: 3>
	5.
		Would you like to sort Ascending or Descending?.
		0: Ascending, 1: Descending
		
		<Input: 0>
	6.
		List Sorted.
		
		What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
		
		<Input: 2>
	7.
		Item 1 Priority:	1
		Item 2 Priority:	1
		Item 3 Priority:	2
		Item 4 Priority:	6
		Item 5 Priority:	21
		Item 6 Priority:	41
		Item 7 Priority:	42
		Item 8 Priority:	49
		Item 9 Priority:	49
		Item 10 Priority:	58
		Item 11 Priority:	59
		Item 12 Priority:	74
		Item 13 Priority:	78
		Item 14 Priority:	84
		Item 15 Priority:	90
		Item 16 Priority:	90
		Item 17 Priority:	90
		Item 18 Priority:	93
		Item 19 Priority:	96
		Item 20 Priority:	99


		What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
		
		<Input: 3>
	8.
		Would you like to sort Ascending or Descending?.
		0: Ascending, 1: Descending
		
		<Input: 1>
		
		List Sorted.

		What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
		
		<Input: 2>
	9.
		Item 1 Priority:	99
		Item 2 Priority:	96
		Item 3 Priority:	93
		Item 4 Priority:	90
		Item 5 Priority:	90
		Item 6 Priority:	90
		Item 7 Priority:	84
		Item 8 Priority:	78
		Item 9 Priority:	74
		Item 10 Priority:	59
		Item 11 Priority:	58
		Item 12 Priority:	49
		Item 13 Priority:	49
		Item 14 Priority:	42
		Item 15 Priority:	41
		Item 16 Priority:	21
		Item 17 Priority:	6
		Item 18 Priority:	2
		Item 19 Priority:	1
		Item 20 Priority:	1


		What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
		
		<Input: 4>
	10.
		List Deleted
		
		What next? 1: Build List, 2: Display List, 3: Sort List, 4: Delete List, -1: End Program.
		
		<Input: -1>
	12.
		