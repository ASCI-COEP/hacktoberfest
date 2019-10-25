/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();

void merge(int arr[], int beg, int mid, int end, int maxele) 
{ 
    int i = beg; 
    int j = mid + 1; 
    int k = beg;
     if(arr[mid]<=arr[mid+1])
    {
        return;
    }
    while (i <= mid && j <= end) { 
        if (arr[i] % maxele <= arr[j] % maxele) { 
            arr[k] = arr[k] + (arr[i] % maxele) * maxele; 
            k++; 
            i++; 
        } 
        else { 
            arr[k] = arr[k] + (arr[j] % maxele) * maxele; 
            k++; 
            j++; 
        } 
    } 
    while (i <= mid) { 
        arr[k] = arr[k] + (arr[i] % maxele) * maxele; 
        k++; 
        i++; 
    } 
    while (j <= end) { 
        arr[k] = arr[k] + (arr[j] % maxele) * maxele; 
        k++; 
        j++; 
    } 
  
    // Obtaining actual values 
    for (int i = beg; i <= end; i++) 
        arr[i] = arr[i] / maxele; 
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
// Recursive merge sort with extra parameter, naxele 
void mergeSortRec(int arr[], int beg, int end, int maxele) 
{ 
    if (end-beg >0) { 
        int mid = (beg + end) / 2; 
        mergeSortRec(arr, beg, mid, maxele); 
        mergeSortRec(arr, mid + 1, end, maxele); 
        merge(arr, beg, mid, end, maxele); 
    }
     else{
        insertionSort(arr,beg,end+1);
    }
} 
  
// This functions finds max element and calls recursive 
// merge sort. 
void mergeSort(int arr[], int n) 
{ 
   int maxele = *max_element(arr, arr+n) + 1; 
   mergeSortRec(arr, 0, n-1, maxele); 
} 

 
/* Function to print an array */
void printArray(int A[], int l,int r) 
{ 
    int i; 
    for (i=l; i <=r; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 


 

int main() 
{ 
    int m =1000000;
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
        //printArray(a, 0,m-1);
        
        begin = clock();
        int n = sizeof(a)/sizeof(a[0]); 
        mergeSort(a, n); 

        end = clock();
        time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        std::cout<<time_spent<<" milli seconds"<<endl;
        sum=sum+time_spent;
        //printArray(a, 0,m-1); 
    }
    cout<<"avg = "<<sum/10<<"milli seconds"<<endl;
    return 0; 
} 
