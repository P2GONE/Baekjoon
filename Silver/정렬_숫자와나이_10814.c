#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_SIZE 100000
#define MAX_LEN 101  // 문자열 최대 길이

// 데이터를 저장할 구조체
typedef struct {
    int number;        // 숫자
    char str[MAX_LEN]; // 문자열
    int index;         // 입력된 순서
} Data;

// 비교 함수 (숫자 내림차순, 숫자가 같으면 입력 순서 유지)
int compare(const void* a, const void* b) {
    Data* d1 = (Data*)a;
    Data* d2 = (Data*)b;

    if (d1->number != d2->number) {
        return d1->number - d2->number;  
    }
    return d1->index - d2->index;  // 숫자가 같으면 입력 순서 유지
}

int main() {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    Data* arr = (Data*)malloc(n * sizeof(Data));
    if (!arr) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d %100s", &arr[i].number, arr[i].str) != 2) {
            printf("입력 오류\n");
            free(arr);
            return 1;
        }
        arr[i].index = i;  // DataIndex
    }

    qsort(arr, n, sizeof(Data), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].number, arr[i].str);
    }

    free(arr);
    return 0;
}
