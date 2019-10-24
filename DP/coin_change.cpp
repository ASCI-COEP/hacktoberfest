/*
You are given an infinite supply of coins, each having a some value.
You have to find the number of ways to use the coins to sum-up to a required value.
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll numberofways(int n, vector <int> &coins, int value) {
	
	vector <ll > ways(value + 1);
	ways[0] = 1;

	for(auto coin : coins) {
		for(int i = 1; i < value + 1; i++) {
			if(i >= coin) {
				ways[i] += ways[i - coin];
			}
		}
	}
	return ways[value];

}

void solve() {
	int n;//number of coins
	cin >> n;
	vector <int > coins(n); //values of the coins
	
	for(int i = 0; i < n; i++) 
		cin >> coins[i];

	int value; // required value;
	cin >> value;

	cout << numberofways(n, coins, value) << endl;

}

int main() {
	int t;//number of testcases
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
