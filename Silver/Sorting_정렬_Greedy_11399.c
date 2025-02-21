#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

// 오름차순
int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;

    if (num1 >= num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

int main() {
    int total_num = 0, sum = 0;
    int* arr;
    int check = 0;

    scanf("%d", &total_num);

    // 동적 배열 할당
    arr = (int*)malloc(total_num * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < total_num; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, total_num, sizeof(int), compare);

    for (int i = 0; i < total_num; i++) {
        sum += (arr[i] * (total_num - i));
    }
    
    printf("%d", sum);
    free(arr);
    return 0;
}
