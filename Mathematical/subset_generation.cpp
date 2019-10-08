#include <bits/stdc++.h>
using namespace std;

#define int long long
//Algorithm to generate all possible subsets of a given set
//A given set of size n has 2 ^ n subsets
// We use a technique called "bitmasking" to generate subsets

// custom sorting function to sort sets based on their sizes
bool cmp(string a, string b){
	return a.length() < b.length();
}

vector<string> subset_gen(vector<int> v){
	int plen = (int)v.size(); // total size of set
	vector<string> ret; // vector to store all possible subsets
    
    for (int i = 0; i < 1 << plen; i++){
    	string subset = "";
    	for (int mask = 0; mask < plen; mask++){
    		if (i & (1 << mask)){
    			// checks it ith bit is set
    			subset += to_string(v[mask]);
    		}
    	}
      ret.push_back(subset);
    }
   return ret; // returns vector containing all subsets
} // O([2 ^ n])

void print(vector<string> v){
	for (int i = 0; i < (int)v.size(); i++){
		int plen = (int)v[i].length();
		for (int it = 0; it < plen; it++){
			if (it == plen - 1) cout << v[i][it] << endl;
			else cout << v[i][it] << " ";
		}
	}
}

int32_t main(){
   int n;
   cin >> n;
   // n = size of set
   vector<int> v(n);
   for (int i = 0; i < n; i++)
     cin >> v[i];
   vector<string> ret = subset_gen(v);
   cout << "The subsets are as follows :" << endl;
   cout << "____________________________" << endl;
   // print the subsets
   sort(ret.begin(), ret.end(), cmp);
   print(ret);
}