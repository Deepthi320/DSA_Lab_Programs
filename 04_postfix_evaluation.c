/*
 * Program: Postfix Expression Evaluation
 * Description:
 * This C program evaluates a valid postfix expression containing single-digit operands
 * and operators (+, -, *, /, %, ^, $) using a stack.
 * Features:
 * 1. Supports integer arithmetic and exponentiation.
 * 2. Uses a stack to evaluate expressions from left to right.
 * 3. Handles basic error scenarios by defaulting unknown operators to 0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>  // for isdigit()

int i, top = -1;
int op1, op2, res, s[20];
char postfix[90], symb;

// Push item onto stack
void push(int item) {
    top = top + 1;
    s[top] = item;
}

// Pop item from stack
int pop() {
    int item = s[top];
    top = top - 1;
    return item;
}

void main() {
    printf("\nEnter a valid postfix expression:\n");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++) {
        symb = postfix[i];

        if(isdigit(symb)) {
            push(symb - '0');  // Convert char to int
        } else {
            op2 = pop();
            op1 = pop();
            switch(symb) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
                case '^':
                case '$': push(pow(op1, op2)); break;
                default:  push(0); break;
            }
        }
    }

    res = pop();
    printf("\nResult = %d\n", res);
}

Enter a valid postfix expression:
623+-382/+*2$3+
Result = 52
