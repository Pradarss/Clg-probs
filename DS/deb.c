#include <stdio.h>
struct student{
	char name[30];
	int rollno;
	float percentage;
	
};
void main(){
}
struct node{
	struct student S;
	struct node *NEXT;
};