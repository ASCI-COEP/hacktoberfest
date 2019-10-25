// C program for implementation of selection sort 
#include <stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();
void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
	int a[1000];
	for(int i=0;i<1000;i++)
	{
		a[i]=rand()%1000 +1;
	}

	clock_t begin, end;
	double time_spent,sum=0;
	
	begin = clock();
	int n = sizeof(a)/sizeof(a[0]); 

	selectionSort(a, n); 
	end = clock();
	time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
	std::cout<<time_spent<<" milli seconds"<<endl;
	//printf("Sorted array: \n"); 
	//printArray(arr, n); 
	return 0; 
} 
