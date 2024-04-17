#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
// Function to swap two elements 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Merge �˰��� (����)
void merge(int* array, int left_start, int left_end, int right_start, int right_end) {
    int left_size = left_end - left_start + 1;
    int right_size = right_end - right_start + 1;
    int merged_size = left_size + right_size;
    int* merged_array = (int*)malloc(sizeof(int) * merged_size);
    int i = left_start, j = right_start, k = 0;

    while (i <= left_end && j <= right_end) {
        if (array[i] <= array[j]) {
            merged_array[k++] = array[i++];
        }
        else {
            merged_array[k++] = array[j++];
        }
    }

    while (i <= left_end) {
        merged_array[k++] = array[i++];
    }

    while (j <= right_end) {
        merged_array[k++] = array[j++];
    }

    for (int m = 0; m < merged_size; m++) {
        array[left_start + m] = merged_array[m];
    }

    free(merged_array);
}

// Merge sort �˰���
void merge_sort(int* array, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, mid + 1, end);
    }
}

int main() {
    int total_num = 0;
    int* arr;

    // ������ �� ������ �Է¹���
    scanf("%d", &total_num);

    // �������� �迭 �Ҵ�
    arr = (int*)malloc(total_num * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return -1; // indicate failure
    }

    // �Էµ��� �迭�� ������
    for (int i = 0; i < total_num; i++) {
        scanf("%d", &arr[i]);
    }

    // Merge sort ȣ���Ͽ� �迭 ����
    merge_sort(arr, 0, total_num - 1);

    // ���ĵ� �� ���
    for (int i = 0; i < total_num; i++) {
        printf("%d\n", arr[i]);
    }

    // �������� �Ҵ��� �޸� ����
    free(arr);

    return 0;
}
