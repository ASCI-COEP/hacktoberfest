#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N,w;                          // N is the number of items, w is total allowed weight
	cin >> N >> w;
	int *W = new int[N + 1];          // Weight matrix to hold weights of individual items
	int *V = new int[N + 1];          // Value matrix to hold values of individual items
	int **A = new int*[N + 1];
	for (int i = 1; i < N + 1; i++)
	{
		cin >> W[i];
	}
	for (int i = 1; i < N + 1; i++)
	{
		cin >> V[i];
	}
	for (int i = 0; i < N + 1; i++)
	{
		A[i] = new int[w + 1];
	}
	for (int i = 0; i < w + 1; i++)
	{
		A[0][i] = 0;
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int x = 0; x < w + 1; x++)
		{
			if (x < W[i])
			{
				A[i][x] = A[i - 1][x];
			}
			else
			{
				A[i][x] = max(A[i - 1][x], A[i-1][x - W[i]] + V[i]);
			}
		}
	}
	cout << A[N][w] << endl;
}
