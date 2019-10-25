// C program for implementation of Bubble sort 
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

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
int i, j; 
for (i = 0; i < n-1; i++)	 

	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("n"); 
} 

// Driver program to test above functions 
int main() 
{ 
	int a[100000];
	for(int i=0;i<100000;i++)
	{
		a[i]=rand()%100000 +1;
	}

	clock_t begin, end;
	double time_spent,sum=0;
	
	begin = clock();
	int n = sizeof(a)/sizeof(a[0]); 
	bubbleSort(a, n); 

	end = clock();
	time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
	std::cout<<time_spent<<" milli seconds"<<endl;

	printf("Sorted array: \n"); 
	//printArray(arr, n); 
	return 0; 
} 
