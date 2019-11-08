#include "stack.h"

typedef struct queue {
    stack s1, s2;
}queue;

void Qinit(queue *q);
void nQ(queue *q, int data);
int dQ(queue *q);
int isQempty(queue *q);
int isQfull(queue *q);
