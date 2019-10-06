#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int detectLoop(struct Node* list){
    struct Node *slow_p = list;
    struct Node *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            printf("Found Loop\n");
            return 1;
        }
    }
    return 0;
}

int main(){
    /* Start with the empty list */
    struct Node* head = NULL;

    push(&head, 100);
    push(&head, 3);
    push(&head, 11);
    push(&head, 2);
    push(&head, 18);
    push(&head, 10);

    head->next->next->next->next->next->next = head;
    detectLoop(head);

    return 0;
}
