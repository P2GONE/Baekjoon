#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
// Function to swap two elements 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Merge 알고리즘 (병합)
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

// Merge sort 알고리즘
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

    // 저장할 총 갯수를 입력받음
    scanf("%d", &total_num);

    // 동적으로 배열 할당
    arr = (int*)malloc(total_num * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return -1; // indicate failure
    }

    // 입력들을 배열에 저장함
    for (int i = 0; i < total_num; i++) {
        scanf("%d", &arr[i]);
    }

    // Merge sort 호출하여 배열 정렬
    merge_sort(arr, 0, total_num - 1);

    // 정렬된 값 출력
    for (int i = 0; i < total_num; i++) {
        printf("%d\n", arr[i]);
    }

    // 동적으로 할당한 메모리 해제
    free(arr);

    return 0;
}
