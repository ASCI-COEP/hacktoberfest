#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 1;
int phi[N];
// upper bound for the generated phi values
// totient value of a number
// phi(n) : the count of numbers less than n which are coprime to n
// phi(n) is multipicative in nature
// i.e phi(a * b) = phi(a) * phi(b) iff gcd(a, b) = 1
// ref : https://en.wikipedia.org/wiki/Euler%27s_totient_function
void totient_sieve(){
   for (int i = 1; i < N; i++) phi[i] = i;
   // initially assume all numbers have phi value equal to its value
   for (int i = 2; i < N; i++){
   	  if (phi[i] == i){
   	  	phi[i] = i - 1; // this is a prime number
   	  	for (int j = 2 * i; j < N; j += i){
   	  		phi[j] -= phi[j] / i; // as per formula
   	  	}
   	  }
   }
   // [O(N * log(log(N)))]	
}

int32_t main(){
  totient_sieve();
  // program to compute the totient values of given input fast
  // input must be <= 10 ^ 7
  int n;
  cin >> n;
  int ret = phi[n];
  cout << "the totient value of " << n << " is :" << endl;
  cout << ret << endl;
  return 0;
}