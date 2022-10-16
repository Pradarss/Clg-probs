//  write a code snippet for declaring the node of a simgly link list that  stores students- related data 

#include <stdio.h>
struct student{
	char name[30];
	int rollno;
	float percentage;
    struct student *S;
};
struct node{
	struct node *NEXT;
};
typedef struct node NODE;