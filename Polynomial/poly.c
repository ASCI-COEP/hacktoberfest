#include "poly.h"

term* createTerm(int coeff, int exp) {
	term* t = (term*) malloc(sizeof(term));
	t->coeff = coeff;
	t->exp = exp;
	t->next = NULL;
	return t;
}
void init(poly* p) {
	*p = NULL;
}

void insert(poly* p, int coeff, int exp) {
	if(coeff == 0)
		return;
	if(*p == NULL) {
		*p = createTerm(coeff, exp);
		return;
	}
	term* temp = *p;
	if(exp > temp->exp) {
		*p = createTerm(coeff, exp);
		(*p)->next = temp;
		return;
	}
	term* temp3 = *p;
	while(temp3) {
		if(temp3->exp == exp) {
			temp3->coeff += coeff;
			return;
		}
		temp3 = temp3->next;
	}
	if(temp->next == NULL) {
		temp->next = createTerm(coeff, exp);
		return;
	}
	while(temp->next->exp > exp) {
		temp = temp->next;
		if(temp->next == NULL)
			break;
	}
	if(temp->next == NULL) {
		temp->next = createTerm(coeff, exp);
		return;
	}else {
		term* temp2 = temp->next;
		temp->next = createTerm(coeff, exp);
		temp->next->next = temp2;
		return;
	}
}

void print(poly* p) {
	term* temp = *p;
	if(!temp)
		return;
	printf("%dx^%d ", temp->coeff, temp->exp);
	temp = temp->next;
	while(temp) {
		printf("+ %dx^%d ", temp->coeff, temp->exp);
		temp = temp->next;
	}
	printf("\n");
	return;
}

poly* add(poly *p1, poly *p2) {
	poly *p3;
	init(p3);
	term* temp1 = *p1;
	term* temp2 = *p2;
	if(temp1 == NULL && temp2 == NULL)
		return NULL;
	if(temp1 == NULL)
		return p2;
	if(temp2 == NULL)
		return p1;
	while(temp1!= NULL && temp2 != NULL) {
		if(temp1->exp > temp2->exp) {
			insert(p3, temp1->coeff, temp1->exp);
			temp1 = temp1->next;
		}else if(temp1->exp < temp2->exp) {
			insert(p3, temp2->coeff, temp2->exp);
			temp2 = temp2->next;
		}else {
			insert(p3, temp1->coeff + temp2->coeff, temp1->exp);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	while(temp1 != NULL) {
		insert(p3, temp1->coeff, temp1->exp);
		temp1 = temp1->next;
	}
	while(temp2) {
		insert(p3, temp2->coeff, temp2->exp);
		temp2 = temp2->next;
	}
	return p3;
}
