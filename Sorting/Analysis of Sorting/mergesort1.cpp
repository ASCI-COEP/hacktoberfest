/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2];
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 


	i = 0; 
	j = 0; 
	k = l; 
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


void mergeSort(int arr[], int l, int r) 
{ 
	if (0 < r-l) 
	{ 
		 
		int m = l+(r-l)/2; 

		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 


void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 


int main() 
{ 	int m =100000;
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
		//printArray(a, m); 
	}
	cout<<"avg = "<<sum/10<<"milli seconds"<<endl;
	return 0; 
} 
