#include<iostream>
#include <cstdlib>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();
int medianof3(int a[], int l, int r)
{		
	int b1=a[l];
	int b2=a[(l+r)/2];
	int b3=a[r];
	if(b1>b2 && b1>b3)
	{
		if(b2>b3)
			return b2;
		else
			return b3;
	}
	if(b2>b1 && b2>b3)
	{
		if(b1>b3)
			return b1;
		else
			return b3;
	}
	if(b3>b1 && b3>b2)
	{
		if(b2>b1)
			return b2;
		else
			return b1;
	}

	
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int low,int high)
{
	int pivot=medianof3(a,low,high);
	int s=a[pivot];
	swap(&a[pivot], &a[low]);
	//cout<<"pivot="<<a[pivot]<<endl;
	int new_pivot=a[low];
	int j=low+1;
	for(int i=low+1;i<=high;i++)
	{
		if(new_pivot>a[i])
		{
			swap(&a[j],&a[i]);
			j++;
		}
	}
	swap(&a[low],&a[j-1]);
	return j-1;
}
void quicksort(int a[],int low, int high)
{
	if(low<high)
	{
		int pi=partition(a,low,high);
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	}
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
		//printArray(a, m);
		
		begin = clock();
		int n = sizeof(a)/sizeof(a[0]); 
		quicksort(a, 0, n - 1); 

		end = clock();
		time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
		std::cout<<time_spent<<" milli seconds"<<endl;
		sum=sum+time_spent;
		//printArray(a, m); 
	}
	cout<<sum/10<<"milli seconds"<<endl;
	/*for(int i=0;i<m;i++)
	{
		printf("%d ",a[i]);
	}*/
}