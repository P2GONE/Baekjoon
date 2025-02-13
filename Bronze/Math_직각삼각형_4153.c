#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		if (a > c) (swap(&a, &b));
		if (b > c) (swap(&b, &c));
		if (a > b) (swap(&a, &b));

		if (c * c == b * b + a * a) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
		
	}

	return 0;

}
