typedef struct data{
	char name[16];
	long long mob;
}data;
typedef struct node{
	data d;
	struct node *front;
	struct node *back;	
}node;

typedef struct queue{
	node *head;
	node *tail;
	int count;
}queue;

void init(queue *);

int isEmpty(queue *);

//int isFull(queue *);

void nq(queue *,data);

data dq(queue *);
