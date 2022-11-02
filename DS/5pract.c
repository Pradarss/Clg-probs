// C++ program for the above methods
 
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* addToEmpty(struct Node* last, int data)
{
    // This function is only for empty list
    if (last != NULL)
        return last;
 
    // Creating a node dynamically.
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
 
    // Assigning the data.
    temp->data = data;
    last = temp;
 
    // Creating the link.
    last->next = last;
    return last;
}
 
struct Node* addBegin(struct Node* last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    return last;
}
 
struct Node* addEnd(struct Node* last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
 
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
 
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;
 
    return last;
}
 
struct Node* addAfter(struct Node* last, int data, int item)
{
    if (last == NULL)
        return NULL;
 
    struct Node *temp, *p;
    p = last->next;
 
    do {
        if (p->data == item) {
            temp
                = (struct Node*)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);
 
    cout << item << " not present in the list." << endl;
    return last;
}
 
void traverse(struct Node* last)
{
    struct Node* p;
 
    // If list is empty, return.
    if (last == NULL) {
        cout << "List is empty." << endl;
        return;
    }
 
    // Pointing to first Node of the list.
    p = last->next;
 
    // Traversing the list.
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != last->next);
}
 
// Driver code
int main()
{
    struct Node* last = NULL;
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
 
    // Function call
    traverse(last);
    return 0;
}



#include<stdio.h>
#include<stdlib.h>
// structure for Circular Linked List
struct Node
{
   int data;
   struct Node *next;
};

int calcSize(struct Node* head);

void deleteFront(struct Node** head){
    
    struct Node* temp = *head;
  
    // if there are no nodes in Linked List can't delete
    if(*head == NULL){
        printf("Linked List Empty, nothing to delete");
        return;
    }
    
    // if only 1 node in CLL
    if(temp->next == *head){
        *head = NULL;
        return;
    }
    
    struct Node* curr = *head;
    
    // traverse till last node in CLL
    while(curr->next != *head)
        curr = curr->next;
    
    // assign last node's next to 2nd node in CLL
    curr->next = (*head)->next;

    // move head to next node
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct Node** head){
    struct Node* temp = *head;
    struct Node* previous;
    
    // if there are no nodes in Linked List can't delete
    if(*head == NULL){
        printf("Linked List Empty, nothing to delete");
        return;
    }
    
    // if Linked List has only 1 node
    if(temp->next == *head){
        *head = NULL;
        return;
    }
    
    // else traverse to the last node
    while (temp->next != *head) 
    {
        // store previous link node as we need to change its next val
        previous = temp; 
        temp = temp->next; 
    }
    // Curr assign 2nd last node's next to head
    previous->next = *head;
    // delete the last node
    free(temp);
    // 2nd last now becomes the last node
}

void deletePos(struct Node** head, int n){
    
    int size = calcSize(*head);
    
    if(n < 1 || size < n) 
    { 
        printf("Can't delete, %d is not a valid position\n", n); 
    } 
    else if(n == 1) 
        deleteFront(head); 
    else if(n == size) 
        deleteEnd(head); 
    else 
    { 
        struct Node* temp = *head; 
        struct Node* previous; 

        // traverse to the nth node 
        while (--n) 
        { 
            // store previous link node as we need to change its next val 
            previous = temp; 
            temp = temp->next; 
        }
    
        // change previous node's next node to nth node's next node
        previous->next = temp->next;
        // delete this nth node
        free(temp);
    }
}

void insert(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    
    if(*head == NULL){
        *head = newNode;
        (*head)->next = *head;
        return;
    }
    
    struct Node* curr = *head;
    
    while(curr->next != *head){
        curr = curr->next;
    }
    
    curr->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

int calcSize(struct Node* head){
    int size = 0;
    struct Node* temp = head;

    if(temp == NULL)
        return size;

    do{
        size++;
        temp = temp->next;
        
    }while(temp!=head);
    
    return size;
}

void display(struct Node* head){
    // if there are no node in CLL
    if(head == NULL)
        return;
    
    struct Node* temp = head;
    
    //need to take care of circular structure of CLL
    do{
        printf("%d ", temp->data);
        temp = temp->next;
        
    }while(temp!=head);
    printf("\n");
}

int main(){
    
    // first node will be null at creation    
    struct Node* head = NULL;
    
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    insert(&head,70);

    display(head);
    
    deleteFront(&head);

    display(head);
    
    deleteEnd(&head);
    
    display(head);
    
    deletePos(&head, 3);
    
    display(head);

  	return 0;
}