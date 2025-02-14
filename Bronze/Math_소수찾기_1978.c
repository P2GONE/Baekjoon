#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int find_prime(int num){
	if (num < 2) return 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n = 0, count = 0;
	int* arr;
	int prime_count = 0;

	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Memory Allocation Error!\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (find_prime(arr[i])){
			prime_count++;
		}
	}

	printf("%d", prime_count);
	//소수 판별, 소수면 출력
	//for (int i = 0; i < n; i++) {
	//	if (find_prime(arr[i])) {
	//		printf("%d\n", arr[i]);
	//	}
	//}
	free(arr);
	return 0;
}
