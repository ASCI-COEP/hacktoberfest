// Infix to postfix converion using linked list
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
    char data;
    struct Node * next;
};

struct Node * top = NULL;

void push(char data){
    struct Node * temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = top;

    top = temp;
    return;
}

char pop(){
    if(top == NULL){
        printf("Stack is empty\n");
        return -1;
    }

    char temp = top->data;
    top = top->next;

    return temp;
}

int isEmpty(){
    return top==NULL;
}

char stackTop(){
    return top->data;
}

int precedence(char op){
    switch(op){
        case '+':
        case '-':
           return 1;

        case '*':
        case '/':
           return 2;

        case '^':
           return 3;   
    }

    return -1;
}
void postfix(char infix[], char out[]){
    int i, n = (sizeof(infix)/sizeof(char)), j=0;
    
    for(i=0; j < n; i++){
        if(isalpha(infix[i])){
           out[j++] = infix[i];
        }
        else
        {
            while(!isEmpty() && precedence(stackTop()) >= precedence(infix[i]) ){
                out[j++] = pop();
            }
            push(infix[i]);
        }
        
    }

    while(!isEmpty()){
         out[j++] = pop();
    }
    
    out[j++] = '\0';

    return;
}

int main(){
    char infix[] = "a+b";
    int n = (sizeof(infix)/sizeof(char));
    char out[n];
    
    printf("%s\n", infix);
    postfix(infix, out);
    printf("%s", out);
    return 0;
}