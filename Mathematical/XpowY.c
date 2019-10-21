#include <stdio.h>
#include <math.h>
double mypow(int x, int y) {
	double prod, t;
	int sign;
	sign = 0;
	if(x == 0 && y == 0) {
		return NAN;
	}
	if(y < 0) {
		sign = 1;
		y = -y;
	}
	/* assert: y > 0 */
	prod = 1.0;
	t = (double) x;
	while(y > 0) {
		if(y % 3 == 2)
			prod = prod * t * t;
		if(y % 3 == 1)
			prod = prod * t;
		t = t * t * t;
		y = y / 3;
	}
	if(sign == 1)
		prod = 1.0 / prod;
	return prod;
}
int main() {
	int x, y;
	double z;
	while(scanf("%d%d", &x, &y) != -1) {
		z = mypow(x, y);
		printf("%lf\n", z);
	}
	return 0;
}
