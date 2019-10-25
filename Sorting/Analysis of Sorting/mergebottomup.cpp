/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();
/*
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
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

void mergeSort(int arr[], int l, int r) 
{ 
	
	for(int m=1;m<=r-l;m=2*m)
	{
		for(int i=0;i<=r-l;i=i+2*m)
		{
			int start=l;
			int mid =i+m-1;
			int end=min(i+2*m-1,r); 
			merge(arr,start,mid,end);
		}
	}
} 
*/
int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
  void merge(int a[], int iLeft, int iMiddle, int iRight,  int tmp[])
   {
   		int i = iLeft, j = iMiddle+1; 
   		for (int k = iLeft; k <=iRight; k++)   
	 	{      
	 		if (i > iMiddle) 
	          	tmp[k] = a[j++];  
	        else if (j > iRight)
	        	tmp[k] = a[i++];
	        else if (min(a[j], a[i])) 
	        	tmp[k] = a[j++];
	        else   
	        	tmp[k] = a[i++];
   		}
/*
      int i, j, k;

      i = iLeft;
      j = iMiddle;
      k = iLeft;

      while ( i < iMiddle || j < iRight )
      {
         if ( i < iMiddle && j < iRight )
         {  // Both array have elements
            if ( a[i] < a[j] )
               tmp[k++] = a[i++];
            else
               tmp[k++] = a[j++];
         }
         else if ( i == iMiddle )
            tmp[k++] = a[j++];     // a is empty
         else if ( j == iRight )
            tmp[k++] = a[i++];     // b is empty
      }*/
   }

 void mergeSort(int a[],int tmp[],int n)
   {
      int width;

      for ( width = 1; width < n; width = 2*width )
      {
         // Combine sections of array a of width "width"
         int i;

         for ( i = 0; i < n; i = i + 2*width )
         {
            int left, middle, right;

		    left = i;
		    middle = i + width-1;
		    right  = min(i+2*width-1,n); 

            merge( a, left, middle, right, tmp );

         }
         /*
         for ( i = 0; i < n; i++ )
            a[i] = tmp[i];*/      
   	  }
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
	int m =10;
	int a[m];
	for(int i=0;i<m;i++)
	{
		a[i]=i +1;
	}
	srand(time(NULL));

	for(int i=0;i<1;i++)
	{
		clock_t begin, end;
		double time_spent,sum=0;
		random_shuffle(a,a+m);
		//printArray(a, m);
		int tmp[m];
		begin = clock();
		int n = sizeof(a)/sizeof(a[0]); 
		mergeSort(a, tmp,n); 

		end = clock();
		time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
		std::cout<<time_spent<<" milli seconds"<<endl;
		printf("\nSorted array is \n"); 
		printArray(a, 0,m-1); 
	}
	return 0; 
} 
