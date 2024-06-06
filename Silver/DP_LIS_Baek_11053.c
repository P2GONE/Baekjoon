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
	// �� ���ҿ� ���� �ʱ� LIS ���̸� 1�� ����
	for (int i = 0; i < length; i++) {
		lis[i] = 1;
	}

	// DP �˰��� ����
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < i; j++) {
			// array[i]�� array[j]�� ���Ͽ� �����ϴ°� ã�� && ���� ���Ҹ� ������ LIS�� ���̰� ������ ����� ���̺��� ū�� Ȯ���ϱ�
			if (array[i] > array[j] && lis[i] < lis[j] + 1) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	// LIS �迭���� �ִ� ���� ã��
	int max_lis = 0;
	for (int i = 0; i < length; i++) {
		// ���� ���Ұ� max_lis���� ū ��� max_lis�� lis[i]�� ������Ʈ
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
	// ��ü ���� ����
	scanf("%d", &total_num);

	// ���� �迭 �Ҵ�
	arr = (int*)malloc(total_num * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	// �迭�� �κ� ���� ���� 
	for (int i = 0; i < total_num; i++) {
		scanf("%d", &arr[i]);
	}

	// �������� Ȯ��
	check_inc(arr, total_num);
	
	free(arr);
	return 0;
}