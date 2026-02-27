/*
 * Program: Doubly Linked List (DLL) for Employee Records
 * Description:
 * This C program implements a doubly linked list to manage employee records.
 * Features:
 * 1. Create DLL of employee nodes.
 * 2. Display all employee nodes.
 * 3. Insert a node at the end or front.
 * 4. Delete a node from the end or front.
 * 5. Double-ended queue demo using DLL (insert/delete from both ends).
 * Each employee node stores: SSN, Name, Department, Designation, Salary, Phone number.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    struct node *llink;
    struct node *rlink;
};
typedef struct node* NODE;

NODE first = NULL;
int count = 0;

/* Create a new employee node */
NODE create() {
    NODE enode = (NODE)malloc(sizeof(struct node));
    if (enode == NULL) {
        printf("\nRunning out of memory");
        exit(0);
    }
    printf("\nEnter the SSN, Name, Department, Designation, Salary, PhoneNo of the employee: \n");
    scanf("%s %s %s %s %d %ld", enode->ssn, enode->name, enode->dept, enode->designation, &enode->sal, &enode->phone);
    enode->llink = enode->rlink = NULL;
    count++;
    return enode;
}

/* Insert node at front */
NODE insertfront() {
    NODE temp = create();
    if (first == NULL)
        return temp;
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

/* Delete node from front */
NODE deletefront() {
    NODE temp;
    if (first == NULL) {
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("\nThe employee node with SSN:%s is deleted", first->ssn);
        free(first);
        count--;
        return NULL;
    }
    temp = first;
    first = first->rlink;
    first->llink = NULL;
    printf("\nThe employee node with SSN:%s is deleted", temp->ssn);
    free(temp);
    count--;
    return first;
}

/* Insert node at end */
NODE insertend() {
    NODE cur, temp = create();
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->rlink != NULL)
        cur = cur->rlink;
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

/* Delete node from end */
NODE deleteend() {
    NODE prev = NULL, cur = first;
    if (first == NULL) {
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if (first->rlink == NULL) {
        printf("\nThe employee node with SSN:%s is deleted", first->ssn);
        free(first);
        count--;
        return NULL;
    }
    while (cur->rlink != NULL) {
        prev = cur;
        cur = cur->rlink;
    }
    printf("\nThe employee node with SSN:%s is deleted", cur->ssn);
    free(cur);
    prev->rlink = NULL;
    count--;
    return first;
}

/* Display all nodes */
void display() {
    NODE cur = first;
    int nodeno = 1;
    if (cur == NULL) {
        printf("\nNo Contents to display in DLL\n");
        return;
    }
    while (cur != NULL) {
        printf("\nENode:%d||SSN:%s|Name:%s|Department:%s|Designation:%s|Salary:%d|Phone no:%ld",
               nodeno, cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phone);
        cur = cur->rlink;
        nodeno++;
    }
    printf("\nNo of employee nodes: %d\n", count);
}

/* Double Ended Queue demo */
void deqdemo() {
    int ch;
    while (1) {
        printf("\nDouble Ended Queue Demo using DLL");
        printf("\n1: Insert at Front\n2: Delete from Front\n3: Insert at Rear\n4: Delete from Rear\n5: Display Status\n6: Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: first = insertfront(); break;
            case 2: first = deletefront(); break;
            case 3: first = insertend(); break;
            case 4: first = deleteend(); break;
            case 5: display(); break;
            default: return;
        }
    }
}

int main() {
    int ch, i, n;
    while (1) {
        printf("\n~~~Menu~~~");
        printf("\n1: Create DLL of Employee Nodes");
        printf("\n2: Display Status");
        printf("\n3: Insert at End");
        printf("\n4: Delete at End");
        printf("\n5: Insert at Front");
        printf("\n6: Delete at Front");
        printf("\n7: Double Ended Queue Demo using DLL");
        printf("\n8: Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                printf("\nEnter the number of Employees: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++)
                    first = insertend();
                break;
            case 2: display(); break;
            case 3: first = insertend(); break;
            case 4: first = deleteend(); break;
            case 5: first = insertfront(); break;
            case 6: first = deletefront(); break;
            case 7: deqdemo(); break;
            case 8: exit(0);
            default: printf("\nPlease enter a valid choice\n");
        }
    }
}

~~~Menu~~~
1: Create DLL of Employee Nodes
2: Display Status
3: Insert at End
4: Delete at End
5: Insert at Front
6: Delete at Front
7: Double Ended Queue Demo using DLL
8: Exit
Please enter your choice: 1
Enter the number of Employees: 2
Enter the SSN, Name, Department, Designation, Salary, PhoneNo of the employee:
1 POO CS PROF 50000 654648674
Enter the SSN, Name, Department, Designation, Salary, PhoneNo of the employee:
2 SWETHA DS PROF 64000 54766874

Please enter your choice: 2
ENode:1||SSN:1|Name:POO|Department:CS|Designation:PROF|Salary:50000|Phone no:654648674
ENode:2||SSN:2|Name:SWETHA|Department:DS|Designation:PROF|Salary:64000|Phone no:54766874
No of employee nodes: 2
