/*
 * Program: Circular Queue using Array
 * Description:
 * This C program implements a circular queue using a fixed-size array.
 * Users can perform the following operations via a menu-driven interface:
 * 1. Insert an element into the circular queue (with overflow handling)
 * 2. Delete an element from the circular queue (with underflow handling)
 * 3. Display all elements in the circular queue
 * Features:
 * - Circular queue logic to efficiently use array space.
 * - Handles overflow and underflow gracefully.
 * - Fixed queue size defined by SIZE.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int CQ[SIZE];
int front = -1;
int rear = -1;
int ch;

int IsCQ_Full();
int IsCQ_Empty();
void CQ_Insert(int item);
void CQ_Delet();
void CQ_Display();

int main() {
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while(1) {
        int ele;
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                if (IsCQ_Full()) {
                    printf("Circular Queue Overflow\n");
                } else {
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &ele);
                    CQ_Insert(ele);
                }
                break;
            case 2:
                if (IsCQ_Empty()) {
                    printf("Circular Queue Underflow\n");
                } else {
                    CQ_Delet();
                }
                break;
            case 3:
                if (IsCQ_Empty()) {
                    printf("Circular Queue Underflow\n");
                } else {
                    CQ_Display();
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void CQ_Insert(int item) {
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    CQ[rear] = item;
}

void CQ_Delet() {
    int item = CQ[front];
    printf("Deleted element is: %d\n", item);
    if (front == rear)
        front = rear = -1; // Queue becomes empty
    else
        front = (front + 1) % SIZE;
}

void CQ_Display() {
    int i;
    printf("Elements of the circular queue are: ");
    for (i = front; i != rear; i = (i + 1) % SIZE)
        printf("%d\t", CQ[i]);
    printf("%d\n", CQ[i]);
}

int IsCQ_Full() {
    return (front == (rear + 1) % SIZE);
}

int IsCQ_Empty() {
    return (front == -1);
}

1.Insert
2.Delete
3.Display
4.Exit

Enter your choice: 1
Enter the element to be inserted: 5

Enter your choice: 1
Enter the element to be inserted: 10

Enter your choice: 1
Enter the element to be inserted: 15

Enter your choice: 1
Enter the element to be inserted: 20

Enter your choice: 1
Enter the element to be inserted: 25

Enter your choice: 3
Elements of the circular queue are: 5   10  15  20  25

Enter your choice: 1
Circular Queue Overflow

Enter your choice: 2
Deleted element is: 5

Enter your choice: 2
Deleted element is: 10

Enter your choice: 2
Deleted element is: 15

Enter your choice: 2
Deleted element is: 20

Enter your choice: 2
Deleted element is: 25

Enter your choice: 2
Circular Queue Underflow
