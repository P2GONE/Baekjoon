#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAXNUM 20000
#define MAXLEN 50

// 문자열 비교 함수
int compare(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    // 먼저 문자열의 길이를 비교
    int lengthCompare = strlen(str1) - strlen(str2);
    if (lengthCompare != 0) // 길이가 다르면 길이에 따라 비교
        return lengthCompare;
    else // 길이가 같으면 알파벳 순서로 비교
        return strcmp(str1, str2);
}

int main() {
    int total_num = 0;
    char** arr;

    // 저장할 총 갯수를 입력받음
    scanf("%d", &total_num);

    // 동적으로 배열 할당
    arr = (char**)malloc(total_num * sizeof(char*));
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return -1; // indicate failure
    }

    // 입력들을 배열에 저장함
    for (int i = 0; i < total_num; i++) {
        arr[i] = (char*)malloc((MAXLEN + 1) * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation failed.");
            return -1; // indicate failure
        }
        // 문자열 입력받음
        scanf("%s", arr[i]);
    }

    // 문자열을 정렬
    qsort(arr, total_num, sizeof(char*), compare);

    // 중복 제거 후 출력
    printf("%s\n", arr[0]);
    for (int i = 1; i < total_num; i++) {
        if (strcmp(arr[i], arr[i - 1]) != 0) {
            printf("%s\n", arr[i]);
        }
    }

    // 동적 할당 해제
    for (int i = 0; i < total_num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
