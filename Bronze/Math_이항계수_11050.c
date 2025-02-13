#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_SIZE 10

int factorial(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) {
		result *= i;
	}
	return result;
}

int calc(int a, int b) {
	return factorial(a) / (factorial(b) * factorial(a - b));
}

int main() {
	int n = 0;
	int k = 0;
	long long answer = 0;
	if (scanf("%d %d", &n, &k) !=2 || n > 10 || n < 1) {
		printf("Wrong Input!\n");
		return 1;
	}
	answer = calc(n, k);
	printf("%d\n", answer);
	return 0;

}
