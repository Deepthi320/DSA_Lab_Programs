/*
 * Program: Queue using Array
 * Description:
 * This C program implements a simple queue using a fixed-size array.
 * Users can perform the following operations via a menu-driven interface:
 * 1. Insert an element into the queue (with overflow handling)
 * 2. Delete an element from the queue (with underflow handling)
 * 3. Peek at the front element of the queue
 * 4. Display all elements in the queue
 * Features:
 * - Handles queue overflow and underflow gracefully.
 * - Fixed queue size defined by MAX.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue_arr[MAX];
int front = -1, rear = -1;

void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main() {
    int choice, item;
    while (1) {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display element at the front\n");
        printf("4.Display all elements of the queue\n");
        printf("5.Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nInput the element for adding in queue: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                item = del();
                printf("\nDeleted element is %d\n", item);
                break;
            case 3:
                printf("\nElement at the front is %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong choice\n");
        }
    }
    return 0;
}

void insert(int item) {
    if (isFull()) {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item;
}

int del() {
    if (isEmpty()) {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    int item = queue_arr[front];
    front = front + 1;
    return item;
}

int peek() {
    if (isEmpty()) {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX - 1);
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue is:\n");
    for (int i = front; i <= rear; i++)
        printf("%d  ", queue_arr[i]);
    printf("\n");
}

1.Insert
2.Delete
3.Display element at the front
4.Display all elements of the queue
5.Quit

Enter your choice: 1
Input the element for adding in queue: 5

Enter your choice: 1
Input the element for adding in queue: 10

Enter your choice: 1
Input the element for adding in queue: 15

Enter your choice: 4
Queue is:
5  10  15

Enter your choice: 2
Deleted element is 5

Enter your choice: 3
Element at the front is 10

Enter your choice: 5
