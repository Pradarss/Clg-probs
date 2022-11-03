#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
char *name;
int age;
int rollNo;
struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
//display the list
void printList() {
struct node *ptr = head;
printf("\n[ ");
//start from the beginning
while(ptr != NULL) {
printf("%s %d %d",ptr->name,ptr->age,ptr->rollNo);
printf(" -> ");
ptr = ptr->next;
}
printf(" ]");
// printf("\n");
}
void insertFirst(char *name,int age,int roll) {
struct node *link = (struct node*) malloc(sizeof(struct node));
link->name=name;
link->age = age;
link->rollNo=roll;
link->next = head;
head = link;
}
void InsertAtPos(int pos,char *name,int age,int rollNo){
struct node *link1 = (struct node*) malloc(sizeof(struct node));
link1->name=name;
link1->age = age;
link1->rollNo=rollNo;
if(pos == 1){
insertFirst(name,age,rollNo);
return;
}
int count=1;
struct node* temp=head;
while(count < pos-1){
temp=temp->next;
count++;
}
if(temp->next == NULL){
link1->next = temp->next;
temp->next = link1;
return;
}
else{
link1->next = temp->next;
temp->next = link1;
return;
}
}
void deleteNode(int rollno){
struct node* curr = head;
struct node* prev= NULL;
int count=1;
while(curr !=NULL){
if(curr->rollNo == rollno){
break;
}
count++;
prev=curr;
curr=curr->next;
}
if(count == 1){
struct node*temp=head;
head=head->next;
temp->next=NULL;
free(temp);
return;
}
prev->next=curr->next;
curr->next=NULL;
free(curr);
}
void reverse() {
struct node* prev = NULL;
struct node* current = head;
struct node* next;
while (current != NULL) {
next = current->next;
current->next = prev; 
prev = current;
current = next;
}
head = prev;
}
void main() {
insertFirst("Heramb",12,24);
insertFirst("Jagrit",20,42);
insertFirst("Gaurav",19,18);
InsertAtPos(4,"Ashu",16,2);
insertFirst("Rishabh",19,10);
// insertFirst(5,40);
// insertFirst(6,56); 
printf("Original List: "); 
//print list
printList();
printf("\n");
printf("Deleting Node of given Roll Number\n");
int n;
printf("Enter Roll No (24,42,18,2,10) to be deleted: ");
scanf("%d",&n);
deleteNode(n);
printf("Node Deleted with roll No %d\n",n);
printList();
reverse();
printf("\n");
printf("reverse list : ");
printf("\n");
printList();
}