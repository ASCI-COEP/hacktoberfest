#include<stdio.h>
#include<stdlib.h>
#include "qUsingStack.h"

void Qinit(queue *q) {
    init(&q -> s1);
    init(&q -> s2);
}

void nQ(queue *q, int data) {
    push(&q -> s1, data);
}

int dQ(queue *q) {
    int dQueued;
    while(!isEmpty(&q -> s1)) {
        push(&q -> s2, pop(&q -> s1));
    }
    dQueued = pop(&q -> s2);
    while(!isEmpty(&q -> s2)) {
        push(&q -> s1, pop(&q -> s2));
    }
    return dQueued;
}

int isQempty(queue *q){
    return isEmpty(&q -> s1);
}

//int isQfull(queue *q);
int main()
{
    queue q;
    Qinit(&q);
    int i;
    for(i = 1; i <= 10; i++)
        nQ(&q, i * 10);
    for(i = 1; i <= 10; i++)
        printf("%d\n", dQ(&q));
    return 0;
}
