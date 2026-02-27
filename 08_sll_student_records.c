/*
 * Program: Singly Linked List (SLL) for Student Records
 * Description:
 * This C program implements a singly linked list to manage student records.
 * Features:
 * 1. Create SLL of student nodes.
 * 2. Display all student nodes.
 * 3. Insert a student node at the end.
 * 4. Delete a student node from the end.
 * 5. Stack demo using SLL (insertion and deletion at the front).
 * Each student node stores: USN, Name, Branch, Semester, Phone number.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *link;
};
typedef struct node* NODE;

NODE start = NULL;
int count = 0;

/* Function Prototypes */
NODE create();
NODE insertfront();
NODE deletefront();
NODE insertend();
NODE deleteend();
void display();
void stackdemo();

/* Create a new student node */
NODE create() {
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));
    if (snode == NULL) {
        printf("\nMemory is not available");
        exit(1);
    }
    printf("\nEnter the USN, Name, Branch, Sem, PhoneNo of the student: ");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->link = NULL;
    count++;
    return snode;
}

/* Insert node at the front */
NODE insertfront() {
    NODE temp = create();
    if (start == NULL)
        return temp;
    temp->link = start;
    return temp;
}

/* Delete node from the front */
NODE deletefront() {
    NODE temp;
    if (start == NULL) {
        printf("\nLinked list is empty");
        return NULL;
    }
    if (start->link == NULL) {
        printf("\nThe student node with USN: %s is deleted", start->usn);
        count--;
        free(start);
        return NULL;
    }
    temp = start;
    start = start->link;
    printf("\nThe student node with USN: %s is deleted", temp->usn);
    count--;
    free(temp);
    return start;
}

/* Insert node at the end */
NODE insertend() {
    NODE cur, temp = create();
    if (start == NULL)
        return temp;
    cur = start;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = temp;
    return start;
}

/* Delete node from the end */
NODE deleteend() {
    NODE cur, prev;
    if (start == NULL) {
        printf("\nLinked list is empty");
        return NULL;
    }
    if (start->link == NULL) {
        printf("\nThe student node with USN: %s is deleted", start->usn);
        free(start);
        count--;
        return NULL;
    }
    prev = NULL;
    cur = start;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("\nThe student node with USN: %s is deleted", cur->usn);
    free(cur);
    prev->link = NULL;
    count--;
    return start;
}

/* Display all nodes */
void display() {
    NODE cur;
    int num = 1;
    if (start == NULL) {
        printf("\nNo contents to display in SLL\n");
        return;
    }
    printf("\nThe contents of SLL:\n");
    cur = start;
    while (cur != NULL) {
        printf("\n||%d|| USN:%s | Name:%s | Branch:%s | Sem:%d | Ph:%ld |", 
               num, cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->link;
        num++;
    }
    printf("\nNumber of student nodes: %d\n", count);
}

/* Stack demo using SLL (push/pop at front) */
void stackdemo() {
    int ch;
    while (1) {
        printf("\n~~~Stack Demo using SLL~~~\n");
        printf("1: Push operation\n2: Pop operation\n3: Display\n4: Exit\n");
        printf("Enter your choice for stack demo: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: start = insertfront(); break;
            case 2: start = deletefront(); break;
            case 3: display(); break;
            default: return;
        }
    }
}

int main() {
    int ch, i, n;
    while (1) {
        printf("\n~~~Menu~~~\n");
        printf("1: Create SLL of Student Nodes\n");
        printf("2: Display Status\n");
        printf("3: Insert at End\n");
        printf("4: Delete at End\n");
        printf("5: Stack Demo using SLL (Insertion and Deletion at Front)\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                printf("\nEnter the number of students: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++)
                    start = insertfront();
                break;
            case 2: display(); break;
            case 3: start = insertend(); break;
            case 4: start = deleteend(); break;
            case 5: stackdemo(); break;
            case 6: exit(0);
            default: printf("\nPlease enter a valid choice\n");
        }
    }
}

~~~Menu~~~
1: Create SLL of Student Nodes
2: Display Status
3: Insert at End
4: Delete at End
5: Stack Demo using SLL (Insertion and Deletion at Front)
6: Exit
Enter your choice: 1
Enter the number of students: 2
Enter the USN, Name, Branch, Sem, PhoneNo of the student: 11 UMA CS 3 6845741422
Enter the USN, Name, Branch, Sem, PhoneNo of the student: 10 SUNANDA CS 3 9874546547

Enter your choice: 2
The contents of SLL:
||1|| USN:10 | Name:SUNANDA | Branch:CS | Sem:3 | Ph:9874546547 |
||2|| USN:11 | Name:UMA | Branch:CS | Sem:3 | Ph:6845741422 |
Number of student nodes: 2

Enter your choice: 3
Enter the USN, Name, Branch, Sem, PhoneNo of the student: 14 POOJA CS 3 87413512126

Enter your choice: 2
The student node with USN:14 is deleted
