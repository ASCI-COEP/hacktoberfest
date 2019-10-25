/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
	k=l;
	if(L[n1-1]<=R[0])
	{
		return;
	}
	else{
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) 
	{ 
		arr[k] = R[j]; 
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
/* Function to print an array */
void printArray(int A[], int l,int r) 
{ 
	int i; 
	for (i=l; i <=r; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 
/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (r-l>100) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r);
		//printArray(arr, l,r); 
	}
	else{
		//sort(arr+l,arr+r+2);
		insertionSort(arr,l,r+1); 
		//printArray(arr,l,r); 
	} 
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
		//printArray(a, m);
		
		begin = clock();
		int n = sizeof(a)/sizeof(a[0]); 
		mergeSort(a, 0, n - 1); 

		end = clock();
		time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
		std::cout<<time_spent<<" milli seconds"<<endl;
		sum=sum+time_spent;
		//printArray(a, 0,m-1); 
	}
	cout<<"avg = "<<sum/10<<"milli seconds"<<endl;
	//printArray(a, 0,m-1);
	return 0; 
} 
