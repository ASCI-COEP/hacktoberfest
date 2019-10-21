// HARDY-RAMANUJAM ALGORITHM C++ IMPLEMENTATION
#include <bits/stdc++.h> 
using namespace std; 
//ALGORITHM
int prime_factor(int n) 
{ 
	int x=log(log(n));

  
	return x; 
} 
int main() 
{ 
	int n;
  cout <<"GIVE THE NUMBER"<<endl;
  cin>>n;
	cout << "The number of distinct prime factors using hardy ramanujam algoritm can be - "
		<< prime_factor(n)<<"  or  "<<prime_factor(n)+1 << endl; 
	return 0; 
} 
