/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand(); 
void merge(int arr[], int l, int m, int r) 
{  
    int i,j,k=l;
    int x=0;
    int y=0;
    int n1=m - l + 1;
    int n2 = r - m; 
    if(arr[l+n1-1]<=arr[m+1])
    {
        return;
    }
    else{
    i = 0;     
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (arr[l+i] <= arr[m+1+j]) 
        { 
            arr[k] = arr[l+i]; 
            i++; 
        } 
        else
        { 
            arr[k] = arr[m+1+j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = arr[l+i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = arr[m+1+j]; 
        j++; 
        k++; 
    } 
    
    }
} 

void insertionSort(int arr[], int l,int r) 
{ 
    int i, key, j; 
    for (i = l+1; i < r; i++) { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= l && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void printArray(int A[], int l,int r) 
{ 
    int i; 
    for (i=l; i <=r; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

void mergeSort(int arr[], int beg, int end) 
{ 
    if ( end-beg>100) { 
        int mid = (beg + end) / 2; 
        mergeSort(arr, beg, mid); 
        mergeSort(arr, mid + 1, end); 
        merge(arr, beg, mid, end); 
    } 
    else{
        insertionSort(arr,beg,end+1);
    }
} 


int main() 
{ 
    int m =100;
    int a[m];
    for(int i=0;i<m;i++)
    {
        a[i]=i+1;
    }
    srand(time(NULL));
    double sum=0;
    for(int i=0;i<1;i++)
    {
        clock_t begin, end;
        double time_spent;
        random_shuffle(a,a+m);
       printArray(a, 0,m-1);
        
        begin = clock();
        int n = sizeof(a)/sizeof(a[0]); 
        mergeSort(a, 0, n - 1); 

        end = clock();
        time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        std::cout<<time_spent<<" milli seconds"<<endl;
        sum=sum+time_spent;
        printArray(a, 0,m-1); 
    }
    cout<<"avg = "<<sum/10<<"milli seconds"<<endl;
    return 0; 
} 
