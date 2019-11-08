// C++ program to find maximum sum in a grid such that 
// no two elements are adjacent. 
#include<bits/stdc++.h> 
#define MAX 1000 
using namespace std; 

// Function to find max sum without adjacent 
int maxSum(int grid[2][MAX], int n) 
{ 
	// Sum including maximum element of first column 
	int incl = max(grid[0][0], grid[1][0]); 

	// Not including first column's element 
	int excl = 0, excl_new; 

	// Traverse for further elements 
	for (int i = 1; i<n; i++ ) 
	{ 
		// Update max_sum on including or excluding 
		// of previous column 
		excl_new = max(excl, incl); 

		// Include current column. Add maximum element 
		// from both row of current column 
		incl = excl + max(grid[0][i], grid[1][i]); 

		// If current column doesn't to be included 
		excl = excl_new; 
	} 

	// Return maximum of excl and incl 
	// As that will be the maximum sum 
	return max(excl, incl); 
} 

// Driver code 
int main() 
{ 
	int grid[2][MAX] = {{ 1, 2, 3, 4, 5}, 
						{ 6, 7, 8, 9, 10}}; 

	int n = 5; 
	cout << maxSum(grid, n); 

	return 0; 
} 
