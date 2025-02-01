#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 10000

int n = 0;

void calc(char* str, int num) {
	n = strlen(str);
	int left = 0, right = 0, count = 0;
	while (right < n) {
		if (str[right] == num)
	}
}

void print(char* str, int num) {

}

int main() {

	scanf_s("%d", &n);
	getchar();

	if (n < 1 || n > 100) {
		printf("error!\n");
		return 1;
	}

	// 문자열과 숫자를 저장할 동적 배열 생성
	char** arr = (char**)malloc(n * sizeof(char*));
	int* numbers = (int*)malloc(n * sizeof(int));

	if (arr == NULL || numbers == NULL) {
		printf("Memory allocation failed.\n");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = (char*)malloc((MAXLEN + 1) * sizeof(char));
		if (arr[i] == NULL) {
			printf("Memory allocation failed.\n");
			return -1;
		}
		scanf("%s", arr[i]);
		scanf("d", &numbers[i]);
	}

	for (int i = 0; i < n; i++) {
		calc(arr[i], numbers[i]);
	}

	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
	free(numbers);

	return 0;
}
