#include<stdlib.h>
#include<stdio.h>

typedef struct term {
	int coeff, exp;
	struct term* next;
} term;

typedef struct term* poly;

void init(poly* );

void insert(poly* , int ,int );

void print(poly* );

poly* add(poly*, poly* );
