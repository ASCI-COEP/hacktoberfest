typedef struct term{
	int coef;
	int po;
	struct term *next;
}term;

typedef struct pol{
	term *ptr;
	int count;
}pol;

void init(pol *);

void insert(pol *,int ,int);

void sort(pol *);

void traverse(pol *);


