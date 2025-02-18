#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// 이진 탐색 함수
int binarySearch(long long arr[], int low, int high, long long key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)  // 찾으면 1 반환
            return 1;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0; // 찾지 못하면 0 반환
}

// 정렬을 위한 비교 함수
// overflow를 고려해서 if로 비교문으로 함
int compare(const void* a, const void* b) {
    long long num1 = *(const long long*)a;
    long long num2 = *(const long long*)b;

    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

int main() {
    long long N, M;

    // 첫 번째 입력: M개의 정수를 저장
    scanf("%lld", &M);
    long long* input_buffer = (long long*)malloc(M * sizeof(long long));
    if (input_buffer == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    for (long long i = 0; i < M; i++) {
        scanf("%lld", &input_buffer[i]);
    }

    // 배열 정렬 (이진 탐색을 수행하려면 반드시 정렬이 필요함)
    qsort(input_buffer, M, sizeof(long long), compare);

    // 두 번째 입력: N개의 정수를 체크
    scanf("%lld", &N);
    long long* check_buffer = (long long*)malloc(N * sizeof(long long));
    if (check_buffer == NULL) {
        printf("메모리 할당 실패!\n");
        free(input_buffer);
        return 1;
    }

    for (long long i = 0; i < N; i++) {
        scanf("%lld", &check_buffer[i]);
    }

    // 차이를 계산 (check_buffer의 값이 input_buffer에 존재하는지 확인)
    for (long long i = 0; i < N; i++) {
        long long key = check_buffer[i];
        int exists = binarySearch(input_buffer, 0, M - 1, key);
        if (exists)
            printf("1\n");
            //printf("%lld: 존재함\n", key);
        else
            printf("0\n");
            //printf("%lld: 없음\n", key);
    }

    // 메모리 해제
    free(input_buffer);
    free(check_buffer);

    return 0;
}
