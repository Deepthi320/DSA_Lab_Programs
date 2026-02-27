/*
 * Program: Infix to Postfix Conversion
 * Description:
 * This C program converts a valid infix expression into its corresponding postfix expression using a stack.
 * Features:
 * 1. Supports operators: +, -, *, /, %, ^, $
 * 2. Handles parentheses for grouping.
 * 3. Maintains correct operator precedence and associativity.
 * 4. Displays both the original infix expression and the converted postfix expression.
 */

#include <stdio.h>
#include <stdlib.h>

void evaluate();
void push(char);
char pop();
int prec(char);

char infix[30], postfix[30], stack[30];
int top = -1;

void main() {
    printf("\nEnter the valid infix expression: ");
    scanf("%s", infix);

    evaluate();

    printf("\nThe entered infix expression is :\n %s \n", infix);
    printf("\nThe corresponding postfix expression is :\n %s \n", postfix);
}

void evaluate() {
    int i = 0, j = 0;
    char symb, temp;

    push('#'); // Sentinel for stack bottom

    for (i = 0; infix[i] != '\0'; i++) {
        symb = infix[i];
        switch(symb) {
            case '(':
                push(symb);
                break;
            case ')':
                temp = pop();
                while(temp != '(') {
                    postfix[j++] = temp;
                    temp = pop();
                }
                break;
            case '+': case '-': case '*': case '/': case '%': case '^': case '$':
                while(prec(stack[top]) >= prec(symb)) {
                    postfix[j++] = pop();
                }
                push(symb);
                break;
            default:
                postfix[j++] = symb;
        }
    }

    while(top > 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void push(char item) {
    top = top + 1;
    stack[top] = item;
}

char pop() {
    char item = stack[top];
    top = top - 1;
    return item;
}

int prec(char symb) {
    switch(symb) {
        case '#': return -1;
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': case '$': return 3;
        default: return -1;
    }
}

Enter the valid infix expression: (4+2)+5/10*6

The entered infix expression is :
(4+2)+5/10*6

The corresponding postfix expression is :
42+510/6*+
