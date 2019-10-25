#include <stdio.h> 
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
int rand();

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
		sort(a, a+n); 

		end = clock();
		time_spent = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
		std::cout<<time_spent<<" milli seconds"<<endl;
		sum=sum+time_spent;
		//printArray(a, m); 
	}
	cout<<sum/10<<"milli seconds"<<endl;
	//printf("Sorted array: \n"); 
	//printArray(arr, n); 
	return 0; 
} 