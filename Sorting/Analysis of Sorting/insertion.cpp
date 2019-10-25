// C program for insertion sort 
#include <math.h> 
#include <stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

/* Driver program to test insertion sort */
int main() 
{ 
	int a[1000000];
	for(int i=0;i<1000000;i++)
	{
		a[i]=rand()%1000000 +1;
	}

	clock_t begin, end;
	double time_spent,sum=0;
	
	begin = clock(); 
	int n = sizeof(a)/sizeof(a[0]);
	insertionSort(a, n); 

	end = clock();
	time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
	std::cout<<time_spent<<" milli seconds"<<endl;
	//printArray(arr, n); 

	return 0; 
} 
