#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

char c, stack[MAX];
int top = -1;

int isoperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return 1;
    return 0;
}

void push(char c){
    if(top == MAX-1){
        printf("Stack overflow");
    } else {
        stack[++top] = c;
    }
}

char pop(){
    if(top == -1){
        printf("Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

void InfixToPos(char infix[]){
    char postfix[MAX];
    int i = 0, j = 0;

    while(infix[i] != '\0'){
        c = infix[i];

        if(c == '('){
            push(c);
        }
        else if(isalnum(c)){
            postfix[j++] = c;
        }
        else if(c == ')'){
            while(top != -1 && stack[top] != '('){
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        else if(isoperator(c)){
            while(top != -1 &&
                  ((precedence(stack[top]) > precedence(c)) ||
                  (precedence(stack[top]) == precedence(c) && c != '^'))){
                postfix[j++] = pop();
            }
            push(c);
        }

        i++;
    }

    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main(){
    char arr[MAX];
    printf("Enter the expression: ");
    scanf(" %[^\n]", arr);
    InfixToPos(arr);
    return 0;
}
