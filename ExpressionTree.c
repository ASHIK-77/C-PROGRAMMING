#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

typedef struct Node{
    char data;
    struct Node* lchild;
    struct Node* rchild;
}Node;

char c, stack[MAX], postfix[MAX];
Node* stackn[MAX];  // Now Node is defined
int top = -1, top1 = -1;

void pushn(Node* x)
{
    stackn[++top1] = x;
}

Node* popn()
{
    return stackn[top1--];
}

Node* newnode(char data){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

Node* Build(char postfix[])
{
    int i = 0;
    char c;

    while((c = postfix[i]) != '\0')
    {
        if(isalnum(c))
        {
            pushn(newnode(c));
        }
        else
        {
            Node* t = newnode(c);
            t->rchild = popn();
            t->lchild = popn();
            pushn(t);
        }
        i++;
    }
    return popn();
}

int isoperator(char c){
    return (c=='+'||c=='-'||c=='/'||c=='*'||c=='^');
}

void push(char c)
{
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return -1;
}

void InfixToPos(char infix[]){
    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        c = infix[i];

        if(c == '(')
            push(c);

        else if(isalnum(c))
            postfix[j++] = c;

        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }

        else if(isoperator(c))
        {
            while(top != -1 &&
                  precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
        i++;
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

void preorder(Node* root){
    if(root != NULL){
        printf("%c", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int main(){
    char arr[MAX];

    printf("Enter the expression: ");
    scanf(" %[^\n]", arr);

    InfixToPos(arr);

    printf("Postfix expression: %s\n", postfix);

    Node* exptree = Build(postfix);

    printf("Preorder tree:\n");
    preorder(exptree);

    return 0;
}

