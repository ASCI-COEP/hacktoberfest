
#include<stdio.h>
#include<stdlib.h>

#define and &&

#define pln   printf("\n");
#define plnn  printf("\n\n");
#define ptb   printf("\t");

#define PI(x) printf("%d ", x);
#define SI(x) scanf("%d",&x);

void swap(int*, int*);
void init_arr(int* , int);
void print_arr(int*, int);
void scan_arr(int*, int);

void mxh(int*, int, int);
void bmxh(int*, int);
void mxhs(int*, int);


int main(){
	int n=0;
	printf("Enter the size of array:\n");
	SI(n);
	
	int *arr = (int*)malloc(n*sizeof(int));
	init_arr(arr, n);
	printf("Enter the elements of array:\n");
	scan_arr(arr, n);

	printf("Array after applying heap sort:\n");
	mxhs(arr, n);
	print_arr(arr,n);
	
	return 0;
}

void swap(int* a, int* b){
	int t ;
	t = *a;
	*a = *b;
	*b = t;
}
void init_arr(int* a , int as){
	int i=0;
	for(i=0; i<as ;++i){
		a[i] = -1;
		
	}
}
void print_arr(int* a, int as){
	int i=0;
	for(i=0; i<as; ++i){
		PI(a[i]);
	
	}
	pln
}


void scan_arr(int* a, int as){
	int i=0;
	for(i=0; i<as; ++i){
		SI(a[i]);
	}	
}

void mxh(int* a, int as, int i){
	int l = 2*i+1, r = 2*i+2, lr = i;
	
	if(l<as and a[l]>a[lr])
		lr = l;
	if(r<as and a[r]>a[lr])
		lr = r;
	
	if(lr != i){
		swap(&a[lr], &a[i]);
		mxh(a, as, i);
	}			
}
void bmxh(int* a, int as){
	int i=0;
	for(i = as/2 -1; i >-1; --i){
		mxh(a, as , i);
	}
}
void mxhs(int* arr, int n){
	int c = n;
	bmxh(arr, n);
	
	int i=0;
	for(i=0 ; i<c-1 ;++i){
		swap(&arr[0], &arr[--n]);
		mxh(arr, n, 0);
	}
}
