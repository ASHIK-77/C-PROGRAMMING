#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c; 
    }
}
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i = 0, j = 0;
    char c;

    while (infix[i] != '\0') {
        c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c; 
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while ((stack[top] != '(') && (top != -1)) {
                postfix[j++] = pop();
            }
            pop();  // Remove '('
        } else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}
int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}
