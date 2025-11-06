#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*createNode(int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));

    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    }

void insertAtEnd(struct Node**head, int data){
    struct Node*newNode = createNode(data);

    if(*head==NULL){
        *head = newNode;
        return;
    }
    struct Node*temp=*head;
    while (temp->next!=NULL){
        temp=temp->next;

    }
     temp->next=newNode;
}

void insertAtPosition(struct Node**head, int data, int position){
    if(position<1){
        printf("position should be >=1\n");
        return;
    }
    if (position==1){
        insertAtBeginning(head, data);
        return;
    }
    struct Node*newNode=createNode(data);
    struct Node*temp=*head;

    for(int i=1;i<position-1 && temp!=NULL;i++)
    temp=temp->next;

    if(temp==NULL){
        printf("position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(struct Node*head){
    struct Node*temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node*head){
    struct Node*temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    displayList(head);

    insertAtBeginning(&head, 5);
    displayList(head);

    insertAtPosition(&head, 15, 3);
    displayList(head);

    insertAtPosition(&head, 40, 10);
    displayList(head);

    freeList(head);
    return 0;
}
