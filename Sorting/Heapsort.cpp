#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int N, a;
	cin >> N;
	vector<int>vec, sarr;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		vec.push_back(a);
	}
	make_heap(vec.begin(), vec.end());
	for (int i = N - 1; i >= 0; i--)
	{
		vector<int>::iterator it = vec.begin();
			sarr.push_back(*it);
		vec.erase(it);
		make_heap(vec.begin(), vec.end());
	}
	for (int i = N-1; i >=0; i--)
	{
		cout << sarr[i] << " ";
	}
}