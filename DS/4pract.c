#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
	char *name;
	int salary;
	int age;
	struct Node *next;
	struct Node *prev;
};
struct Node *tail = NULL;
struct Node *head = NULL;
void deleteAtEnd()
{
	struct Node *temp = tail;
	tail->prev->next = tail->next;
	tail = tail->prev;
	temp->prev = NULL;
	free(temp);
}
void insertAtHead(int age, int salary, char *name)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->age = age;
	newNode->name = name;
	newNode->salary = salary;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}
void printLL()
{
	printf("\n");
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("(%d , %s , %d)<=>", temp->age, temp->name, temp->salary);
		temp = temp->next;
	}
	printf("\n");
}
void main()
{
	struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
	node1->name = "Gaurav";
	node1->salary = 100000;
	node1->age = 19;
	node1->next = NULL;
	node1->prev = NULL;
	head = node1;
	tail = node1;
	insertAtHead(20, 5000000, "Heramb");
	insertAtHead(21, 100000, "Jagrit");
	insertAtHead(21, 250000, "Rishabh");
	printf("\n");
	printf("----------------------------Original Queue-----------------------------\n");
	printLL();
	while (1)
	{
		printf("press 1 for Inserting at Head doubly LL\npress 2 for Deleting at Tail doubly LL\n");
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("Enter name of the employee\n");
			char name[30];
			scanf("%s", name);
			printf("Enter age of the employee\n");
			int age;
			scanf("%d", &age);
			printf("Enter Salary of the employee\n");
			int salary;
			scanf("%d", &salary);
			insertAtHead(age, salary, name);
			printLL();
			break;
		case 2:
			deleteAtEnd();
			printf("Deleted Node at the End");
			printLL();
			break;
		}
	}
}
