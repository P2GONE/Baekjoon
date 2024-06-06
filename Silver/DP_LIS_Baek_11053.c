#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_LINE 1000

void check_inc(int array[], int length) {

	int* lis = (int*)malloc(length * sizeof(int));
	if (lis == NULL) {
		printf("Memory allocation failed\n");
		return -1;
	}
	// 각 원소에 대해 초기 LIS 길이를 1로 설정
	for (int i = 0; i < length; i++) {
		lis[i] = 1;
	}

	// DP 알고리즘 적용
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < i; j++) {
			// array[i]와 array[j]를 비교하여 증가하는거 찾기 && 현재 원소를 포함한 LIS의 길이가 기존에 저장된 길이보다 큰지 확인하기
			if (array[i] > array[j] && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	// LIS 배열에서 최대 값을 찾기
	int max_lis = 0;
	for (int i = 0; i < length; i++) {
		// 현재 원소가 max_lis보다 큰 경우 max_lis를 lis[i]로 업데이트
		if (max_lis < lis[i]) {
			max_lis = lis[i];
		}
	}

	printf("%d", max_lis);
	free(lis);
	return 0;
}

int main() {
	int total_num, * arr;
	// 전체 개수 저장
	scanf("%d", &total_num);

	// 동적 배열 할당
	arr = (int*)malloc(total_num * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	// 배열에 부분 수열 저장 
	for (int i = 0; i < total_num; i++) {
		scanf("%d", &arr[i]);
	}

	// 증가여부 확인
	check_inc(arr, total_num);
	
	free(arr);
	return 0;
}