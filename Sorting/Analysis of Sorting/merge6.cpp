/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();
void CopyArray(int A[], int iBegin,int  iEnd, int B[])
{
    for(int k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd,int B[])
{
    int i = iBegin;
    int j = iMiddle;
 
    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    if(iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

void mergeSort(int A[], int B[],int n)
{
    CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}




void printArray(int A[], int l,int r) 
{ 
    int i; 
    for (i=l; i <=r; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 


int main() 
{ 
	int m =100000;
    int a[m];
    for(int i=0;i<m;i++)
    {
        a[i]=i+1;
    }
    srand(time(NULL));
    double sum=0;
    for(int i=0;i<10;i++)
    {
        clock_t begin, end;
        double time_spent;
        random_shuffle(a,a+m);
       // printArray(a, 0,m-1);
        
        begin = clock();
        int n = sizeof(a)/sizeof(a[0]);
        int b[m];
		mergeSort(a,b,n);
        end = clock();
        time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        std::cout<<time_spent<<" milli seconds"<<endl;
        sum=sum+time_spent;
        //printArray(a, 0,m-1); 
    }
    cout<<"avg = "<<sum/10<<"milli seconds"<<endl;

	return 0; 
} 
