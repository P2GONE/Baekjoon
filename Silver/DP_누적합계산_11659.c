#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

// 누적 합(prefix sum) 배열을 미리 계산하는 함수
void preprocess(int* prefix, int* arr, int N) {
    prefix[0] = 0;  // 초기값 설정 (0부터 시작)
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + arr[i];  // 누적 합 계산
/*
prefix[0] = 0
prefix[1] = 0 + 5  = 5
prefix[2] = 5 + 4  = 9
prefix[3] = 9 + 3  = 12
prefix[4] = 12 + 2 = 14
prefix[5] = 14 + 1 = 15

*/
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 배열 동적 할당
    int* arr = (int*)malloc((N + 1) * sizeof(int));
    int* prefix = (int*)malloc((N + 1) * sizeof(int));

    if (arr == NULL || prefix == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 입력 받기
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    // 누적 합 미리 계산
    preprocess(prefix, arr, N);

    // 구간 합 계산
    for (int i = 0; i < M; i++) {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", prefix[right] - prefix[left - 1]);  // O(1) 연산
/*
sum(1, 3) = prefix[3] - prefix[0] = 12 - 0 = 12
sum(2, 4) = prefix[4] - prefix[1] = 14 - 5 = 9
sum(5, 5) = prefix[5] - prefix[4] = 15 - 14 = 1

*/
    }

    // 메모리 해제
    free(arr);
    free(prefix);

    return 0;
}