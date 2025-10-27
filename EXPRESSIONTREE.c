#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

// Node structure for Expression Tree
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

// Stack for operators (char)
char stack[MAX];
int top = -1;

// Stack for tree nodes (Node pointers)
Node *nodeStack[MAX];
int nodeTop = -1;

// ---------- Utility Functions ----------
void push(char c) {
    stack[++top] = c;
}
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
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

// ---------- INFIX → POSTFIX ----------
void InfixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        } else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// ---------- Build Expression Tree from Postfix ----------
Node *buildExpressionTree(char postfix[]) {
    int i = 0;
    char c;

    while ((c = postfix[i++]) != '\0') {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = c;
        newNode->lchild = newNode->rchild = NULL;

        if (isOperator(c)) {
            Node *right = nodeStack[nodeTop--];
            Node *left = nodeStack[nodeTop--];
            newNode->lchild = left;
            newNode->rchild = right;
        }
        nodeStack[++nodeTop] = newNode;
    }
    return nodeStack[nodeTop];
}

// ---------- Postorder Traversal (Left, Right, Root) ----------
void postOrder(Node *root) {
    if (root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%c", root->data);
}

// ---------- MAIN FUNCTION ----------
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    InfixToPostfix(infix, postfix);
    printf("\nPostfix Expression: %s\n", postfix);

    Node *root = buildExpressionTree(postfix);
    printf("Postorder Traversal (Postfix form): ");
    postOrder(root);
    printf("\n");

    return 0;
}
