typedef struct node {
	char *data;
	struct node *next;
}node;

typedef struct list {
	node *head;
	node *tail;
	int nodeCount;
}list;

void init(list *l);
void insert(list *l, char *str, int pos); 
char *traverse(list *l);
void remDuplicate(list *l);
void Interseclist(list *l1, list*l2);

	

