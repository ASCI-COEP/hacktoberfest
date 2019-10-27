#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

};
void printarray(int *arr, int n){

    int i=0;

    for( i=0; i<n; ++i){

        printf("%d ",arr[i]);

    }

    printf("\n");

};
int partition(int *arr, int start, int end){

    int pivot=arr[end];

    int i=(start-1),j=0;

    for( j=start; j<end; j++){

        if(arr[j]<pivot){

            i++;
            swap(&arr[i],&arr[j]);

        }

    }

    swap(&arr[i+1],&arr[end]);

    return i+1;

};
void quicksort(int *arr, int start, int end){

    if(start<end){

        int pn=partition(arr,start,end);

        quicksort(arr,start,pn-1);

        quicksort(arr,pn+1,end);

    }

};

int main(){

    int n=0,i=0;

    printf("Enter the bumber of elements to be sorted\n");

    scanf("%d",&n);

    int *arr=(int*)malloc(sizeof(int)*n);

    for( i=0; i<n; i++){

        scanf("%d",&arr[i]);
    }

    quicksort(arr,0,n-1);

    printf("The sorted array is\n");

    printarray(arr,n);

}
