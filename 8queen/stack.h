#define MAX 8
typedef struct node{
	int row;
	int col;
}node;
typedef struct stack{
	node arr[MAX];
	int i;
}stack;
void init(stack *s);
int isfull(stack *s);
int isempty(stack *s);
void push(stack *s, node curr);
node* pop(stack *s);
int stackcopy(stack *s, node* n);
