#include<stdio.h>
#include"Josephus_problem.h"
int main() {
	int p, k, ans;
	scanf("%d%d", &p, &k);
	ans = winner(p, k);
	printf("%d", ans);
	return 0;
}
