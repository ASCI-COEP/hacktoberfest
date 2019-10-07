#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 11;
// upper bound for primes to be generated
bool isprime[N]; // boolean array to mark primes and composites
vector<int> primes; // vector to store the primes generated

void sieve(){
  fill (isprime + 2, isprime + N, true);
  // initially we mark all numbers as prime
  // then we proceed to mark only primes as true and their multiples
  // which are composite numbers as false
  for (int i = 2; i < N; i++){
  	if (isprime[i]){
  	  primes.push_back(i);
  	  for (int j = 2; i * j < N; j++){
  	  	isprime[i * j] = false;
  	  }
  	}
  }
  // complexity : O(n*log(log(n)))
}

int32_t main(){
    sieve();
    // program to check if a number is prime
    int n;
    cin >> n;
    if (isprime[n]) cout << "Prime" << endl;
    else cout << "Composite" << endl;
}