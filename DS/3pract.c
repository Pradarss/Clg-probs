#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Student{
	int rollnumber;
	char name[100];
	char phone[100];
	float percentage;
	struct Student *next;
};
struct Student *head;

void insert(int rollnumber, char* name, char* phone, float percentage){
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
	student->rollnumber = rollnumber;
	strcpy(student->name, name);
	strcpy(student->phone, phone);
	student->percentage = percentage;
	student->next = NULL;
	if(head==NULL){
		head = student;
	}
	else{
		student->next = head;
		head = student;
	}
}

void Delete(int rollnumber){
    struct Student * temp1 = head;
	struct Student * temp2 = head; 
	while(temp1!=NULL){
		if(temp1->rollnumber==rollnumber){
			printf("Record with roll number %d Found !!!\n", rollnumber);
			if(temp1==temp2){
				head = head->next;
				free(temp1);
			}
			else{
				temp2->next = temp1->next;
				free(temp1); 
			}
			printf("Record Successfully Deleted !!!\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	printf("Student with roll number %d is not found !!!\n", rollnumber);
}

void display(struct Student *head_ref){
    struct Student *temp = head_ref;
	while(temp!=NULL){
		printf("Roll Number: %d\n", temp->rollnumber);
		printf("Name: %s\n", temp->name);
		printf("Phone: %s\n", temp->phone);
		printf("Percentage: %0.4f\n\n", temp->percentage);
		temp = temp->next;
	}
}

void main(){
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float percentage;
    printf("1 to insert student details\n2 to delete student details\n3 to display students list in reverse order");
    do{
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                insert(rollnumber, name, phone, percentage);
                break;
            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 3:
                display(head);
                break;
        }
        
    }while (choice != 0);
}