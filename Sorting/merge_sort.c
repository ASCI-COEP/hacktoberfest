/*
 * =====================================================================================
 *
 *       Filename:  merge_sort_final.c
 *
 *    Description:  Merge Sort
 *
 *        Version:  1.0
 *        Created:  07/13/19 13:58:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vasu Sharma (111803127), sharmav18.comp@coep.ac.in
 *        Company:  SY COMP
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<malloc.h>
int n;
int* merge(int *b,int *c,int t,int z){
    int *out = (int *)calloc(t+z,sizeof(int));
    int i =0,j=0,k=0;
    for(k=0;i<t && j<z;k++){
        if(b[i] < c[j]){
            out[k] = b[i];
            i++;

    }
    else{
        out[k] = c[j];
            j++;

    }
    }
    while(j<z){
        out[k++] = c[j++];
    }
     while(i<t){
        out[k++] = b[i++];
    }
    return out;
}

int* sort(int *a,int m){
    int mid =0;
    if(m != 1){
        if(!(m%2)){
            mid  = m/2;
        }
        else{
            mid= (m+1)/2;
        }
        int *temp1,*temp2;
        temp1 = &a[0];

        temp2 = &a[mid];
        return merge(sort(temp1,mid),sort(temp2,m-mid),mid,m-mid);
    }
    else{
        return a;

    }


}



int main(){
    int i;
    printf("Enter the size of array:\t");
    scanf("%d",&n);

    int *a = (int *)calloc(n,sizeof(int));

    for(i=0;i<n;i++){
        printf("Enter element %d\t",i+1);
        scanf("%d",a+i);
    }
    printf("Entered Array Is:\n");

    for(i=0;i<n;i++){
        printf("%d \t",*(a+i));
    }
    printf("\n");

    int *t;
         t = sort(a,n);


    printf("The sorted array is:\n");

    for(i=0;i<n;i++){
        printf("%d \t",*(t+i));
    }
    printf("\n");

}
