#include <stdio.h>

#define MAX_SIZE 5 

int circularQueue[MAX_SIZE];
int front = -1;
int rear = -1;


int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}


int isEmpty() {
    return front == -1;
}


void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow: Cannot insert element %d, queue is full.\n", value);
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; 
        }
        circularQueue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

void delete() {
    if (isEmpty()) {
        printf("Queue Empty: Cannot delete, queue is empty.\n");
    } else {
        int deletedValue = circularQueue[front];
        if (front == rear) { 
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; 
        }
        printf("Deleted %d from the queue.\n", deletedValue);
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", circularQueue[rear]); 
    }
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}