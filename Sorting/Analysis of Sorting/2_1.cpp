#include<bits/stdc++.h>
#include<iostream>
#include <cstdlib>
#include<time.h>

using namespace std;
int rand();

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int j=low+1;
	for(int i=low+1;i<=high;i++)
	{
		if(pivot>a[i])
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
		quicksort(a, 0, n - 1); 

		end = clock();
		time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
		std::cout<<time_spent<<" milli seconds"<<endl;
		sum=sum+time_spent;
		//printArray(a, m); 
	}
	cout<<sum/10<<" milli seconds"<<endl;
	/*for(int i=0;i<100000;i++)
	{
		printf("%d ",a[i]);
	}*/
}