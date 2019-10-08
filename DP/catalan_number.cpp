#include <bits/stdc++.h>

using namespace std; 

// function to find nth catalan number

long long int catalan(long long int n) 
{ 
	
	long long int dp[n + 1]; 
 
	dp[0] = dp[1] = 1; 

	for (int i = 2; i <= n; i++) { 
		dp[i] = 0; 
		for (int j = 0; j < i; j++) 
			dp[i] += dp[j] * dp[i - j - 1]; 
	} 

	return dp[n]; 
} 


int main() 
{ 
	long long n;

	cin >> n;

	cout << "nth catalan number is " << catalan(n) << endl;
	return 0; 
} 
