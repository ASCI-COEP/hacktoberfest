#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"poly.h"

void init(pol *a){
	a->ptr = NULL;
	a->count = 0;
}

void insert(pol *a,int c, int p){
	term *temp = (term *) malloc (sizeof(term));
	term *tr;
	//if(!temp) return;
	if(a->count == 0){
		a->ptr = temp;
		a->ptr->coef = c;
		a->ptr->po = p;
		a->ptr->next = NULL;
		a->count++ ;
		tr = a->ptr;
	}
	else{
		tr->next = temp;
		temp->coef = c;
		temp->po = p;
		a->count++;
		tr = tr->next;
		tr->next = NULL;
	}

}

void sort(pol *a){
	term* pt1 = a->ptr;
	term* pt2 = NULL;
	int i,j;
	int t1,t2;
	for(i = 0 ; i < a->count ;i++){
		pt2 = pt1->next;
		for(j = i+1 ; j < a->count ; j++){
			if(pt1->po < pt2 ->po){
				t1 = pt1->coef;
				pt1->coef = pt2->coef;
				pt2->coef = t1;
				t2 = pt1->po;
				pt1->po = pt2->po;
				pt2->po = t2;
			}
			pt2 = pt2->next;
		}
		pt1 = pt1->next;
	}


}

void traverse(pol *a){
	sort(a);
	term *p = a->ptr;
	int i = 0 ;
	while(i < a->count){
		if(i != 0)
			printf("+ %dx^%d",p->coef,p->po);
		else
			printf("%dx^%d",p->coef,p->po);	
		p = p->next;
		i++;
		
	}
}
void concat(pol *p1, pol *p2, pol *p3){
	int i;
	term *pt1 = p1->ptr;
	term *pt2 = p2->ptr;
	for(i = 0 ;i < p1->count-1 ;i++){
		pt1 = pt1->next;
	}
	pt1->next = pt2;
	for(i = 0 ;i < p2->count-1 ;i++){
		pt2 = pt2->next;
	}
	
	pt2->next = p3->ptr;
	p3->count = p3->count + p1->count + p2->count;
	//printf("%d",p3->count);
	p3->ptr = p1->ptr;
	traverse(p3);
}
pol add(pol *p1, pol *p2){
	pol ad;
	init(&ad);
	term *pt1 = p1->ptr;
	term *pt2 = p2->ptr;
	int s;
	while(pt1 && pt2){
		if(pt1->po > pt2->po){
			insert(&ad,pt1->coef,pt1->po);
			pt1 = pt1->next;
		}
		else if(pt1->po < pt2->po){
			insert(&ad,pt2->coef,pt2->po);
			pt2 = pt2->next;
		}
		else if(pt1->po == pt2->po){
			s = pt1->coef + pt2->coef;
			insert(&ad,s,pt1->po);	
			pt1 = pt1->next;
			pt2 = pt2->next;
		}
			
	}
	
	if(pt1 == NULL){
		while(pt2){
		insert(&ad,pt2->coef,pt2->po);
		pt2 = pt2->next;
		}
	}
	if(pt2 == NULL){
		while(pt1){
		insert(&ad,pt1->coef,pt1->po);
		pt1 = pt1->next;
		}
	}
	traverse(&ad);
}



int main(){
	pol p1;
	init(&p1);
	int coe;
	int po;
	while(scanf("%d %d",&coe,&po) != -1){
		insert(&p1,coe,po);
	}
	traverse(&p1);
	pol p2;
	init(&p2);
	while(scanf("%d %d",&coe,&po) != -1){
		insert(&p2,coe,po);
	}
	printf("\n");	
	traverse(&p2);
	printf("\n");
	add(&p1,&p2);
	return 0;
}
