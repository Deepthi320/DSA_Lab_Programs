/* Program: Stack Operations with Palindrome Check
Description: This C program demonstrates basic stack operations including push, pop, display, and palindrome checking using a menu-driven interface.
Features:
1. Push an element to the stack with overflow handling.
2. Pop an element from the stack with underflow handling.
3. Check if the current stack elements form a palindrome.
4. Display the current stack elements. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int s[MAX]; 
int top = -1;

void push(int item); 
int pop(); 
void palindrome(); 
void display();

void main() {
    int choice, item;

    while (1) {
        printf("\n\n~~~~~~Menu~~~~~~\n");
        printf("1. Push an element to stack (Overflow demo)\n");
        printf("2. Pop an element from stack (Underflow demo)\n");
        printf("3. Palindrome demo\n");
        printf("4. Display stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter an element to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if(item != -1)
                    printf("Element popped is: %d\n", item);
                break;
            case 3:
                palindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Please enter a valid choice\n");
        }
    }
}

void push(int item) {
    if(top == MAX - 1) {
        printf("~~~~Stack overflow~~~~\n");
        return;
    }
    top++;
    s[top] = item;
}

int pop() {
    int item;
    if(top == -1) {
        printf("~~~~Stack underflow~~~~\n");
        return -1;
    }
    item = s[top];
    top--;
    return item;
}

void display() {
    int i;
    if(top == -1) {
        printf("~~~~Stack is empty~~~~\n");
        return;
    }
    printf("Stack elements are:\n");
    for(i = top; i >= 0; i--)
        printf("| %d |\n", s[i]);
}

void palindrome() {
    int flag = 1, i;
    printf("Stack content:\n");
    for(i = top; i >= 0; i--)
        printf("| %d |\n", s[i]);

    printf("Reverse of stack content:\n");
    for(i = 0; i <= top; i++)
        printf("| %d |\n", s[i]);

    for(i = 0; i <= top/2; i++) {
        if(s[i] != s[top - i]) {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("It is a palindrome number\n");
    else
        printf("It is not a palindrome number\n");
}

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 1
Enter an element to be pushed: 11

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 1
Enter an element to be pushed: 22

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 1
Enter an element to be pushed: 11

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 3
Stack content:
| 11 |
| 22 |
| 11 |
Reverse of stack content:
| 11 |
| 22 |
| 11 |
It is a palindrome number

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 2
Element popped is: 11

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 4
Stack elements are:
| 22 |
| 11 |

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 1
Enter an element to be pushed: 33

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 3
Stack content:
| 33 |
| 22 |
| 11 |
Reverse of stack content:
| 11 |
| 22 |
| 33 |
It is not a palindrome number

~~~~~~Menu~~~~~~
1. Push an element to stack (Overflow demo)
2. Pop an element from stack (Underflow demo)
3. Palindrome demo
4. Display stack
5. Exit
Enter your choice: 2
Element popped is: 33
