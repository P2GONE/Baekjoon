#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)
#define MAXNUM 10000

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int LCM(int a, int b) {
	return (a / GCD(a, b)) * b;
}

int main() {
	int n = 0, m = 0;

	scanf("%d %d", &n, &m);
	int result_gcd = GCD(n, m);
	int result_lcm = LCM(n, m);

	printf("%d\n", result_gcd);
	printf("%d", result_lcm);
	return 0;
}
