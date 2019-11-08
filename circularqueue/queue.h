typedef struct data{
	char name[16];
	unsigned int age;
	struct data *next;
}data;

typedef struct queue{
	data *front;
	data *end;
}queue;

void qinit(queue *);
void enq(queue * , data);
data deq(queue *);
int qfull(queue *);
int qempty(queue *);