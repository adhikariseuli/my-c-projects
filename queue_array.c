#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
int isFull() {
    return (rear == MAX_SIZE - 1);
}

// Function to add an element to the rear of the queue (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the front of the queue (dequeue)
int dequeue() {
    int item;

    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else if (front == rear) {
        item = queue[front];
        front = rear = -1;
    } else {
        item = queue[front];
        front++;
    }

    printf("Dequeued: %d\n", item);
    return item;
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, v;
    
    printf("\n\t QUEUE OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.Enqueue (Insertion)\n\t 2.Dequeue (Deletion)\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value :-");
                scanf("%d",&v);
                enqueue(v);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);

    return 0;
}
