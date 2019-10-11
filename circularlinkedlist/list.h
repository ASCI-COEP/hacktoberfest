typedef struct node{
	char data[50];
	struct node* next;
}node;
typedef node* list;

void init(list *);
void append(list *, char *);
void traverse(list l,char *);
void insert(list *l, char *, int pos);
int length(list l);
void delete(list *l, int pos);
void removeDuplicate(list *l);
void intersect(list *l1, list *l2);	
