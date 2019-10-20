typedef struct node {
	char data;
	struct node* next;
} node;

typedef struct node* stack;

void push(stack * , char );

char pop(stack * );

int isEmpty(stack * );

int isFull(stack * );

void init(stack * );
