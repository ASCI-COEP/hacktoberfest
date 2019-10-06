#include <iostream>
using namespace std;

// Function to find contiguous sub-array with the largest sum
// in given set of integers
int kadane(int arr[], int n)
{
	
	int max_so_far = 0;

	
	int max_ending_here = 0;

	
	for (int i = 0; i < n; i++)
	{
		
		max_ending_here = max_ending_here + arr[i];

		max_ending_here = max(max_ending_here, 0);

		max_so_far = max(max_so_far, max_ending_here);
	}

	return max_so_far;
}


int main()
{
	int n;
	cin >> n; // input of number of elements in array

	int arr[n + 1];

	// input of array elements
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		/* code */
	}

	cout << "The sum of contiguous sub-array with the largest sum is " <<
			kadane(arr, n) << endl;

	return 0;
}