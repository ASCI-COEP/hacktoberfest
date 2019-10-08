#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 11;
vector<int> v(N + 1), t(N + 1);

void merge(int l, int mid, int r){
	int p1 = l, p2 = mid;
	for (int i = l; i < r; i++){
	  if (p1 >= mid) t[i] = v[p2++];
	  else if (p2 >= r) t[i] = v[p1++];
	  else if (v[p1] < v[p2]) t[i] = v[p1++];
	  else t[i] = v[p2++];	
	}
    for (int i = l; i < r; i++)
       v[i] = t[i];
}

void mergeSort(int l, int r){
  if (l >= r - 1) return;
  int mid = (l + r) >> 1;
  mergeSort(l, mid);
  mergeSort(mid, r);
  merge(l, mid, r);	
}

int32_t main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  v.resize(n);
  mergeSort(0, n);
  cout << "The sorted array is :" << endl;
  for (int i = 0; i < n; i++){
  	if (i == n - 1) cout << v[i];
  	else cout << v[i] << " ";
  }	
}