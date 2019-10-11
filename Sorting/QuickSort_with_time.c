#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(long long* a,long long* b) 
{ 
    long long t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (long long arr[], int low, int high) 
{ 
    long long pivot = arr[high];    // pivot 
    long long i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(long long arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main() {
	long long *a, i, n, count = 0, num, size = 1024, sum; 
	struct timeval tv1, tv2;
	time_t t1,t2,time_taken;
	int j ,temp = 0;
	a = (long long *)malloc(sizeof(long long) * size);
	/* Do "man scanf". Scanf returns -1 when there is "no input" 
	 * To tell scanf that there is no input, you can press "control-d" 
	 * in stdio.h EOF is #defined to be -1 */
	/*this code is for dynamic memry allocation*/
	while(scanf("%lld", &num) != EOF) {
		a[count] = num;
		count++;
		if(count == size) {
			size *= 2;
			a = (long long *)realloc(a, sizeof(long long) * size);
			if(a == NULL) {
				printf("Failed for %lld\n", size);
				exit(1);
			}
		}
	}
		
	tv1.tv_usec = gettimeofday(&tv1,NULL);	
	quickSort(a,0,count-1);	
	
	tv2.tv_usec = gettimeofday(&tv2,NULL);
	time_taken = ( ( tv2.tv_sec * 1000000 + tv2.tv_usec) - ( tv1.tv_sec * 1000000 + tv1.tv_usec) ) / 1000000;	
	
	//printing the sorted elements
	// we can use ctrl + d to stop the input or the standard output of other program can also be provided as input
	printf("\n***Sorted Elements are:-\n");
	 for(i = 0; i < count; i++)
		printf("%lld  ",a[i]);
	printf("\n");
	printf("Time taken for sorting(in sec) :- %ld\n",time_taken);
	free(a);
	return 0;
}

