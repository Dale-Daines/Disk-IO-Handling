//Dale Daines - 16998416 - System Programming 1 - Assignment 1
//Used to declare struct and sort_list
typedef struct iorb {
	int base_pri;
	struct iorb *link;
	char filler[100];
} IORB;

typedef struct iorb *POINTER;

POINTER sort_list(POINTER head, int operation);
