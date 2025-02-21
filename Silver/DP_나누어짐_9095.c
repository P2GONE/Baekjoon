#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_N 10  // 문제에서 n ≤ 10이므로 최대 10까지 처리

int dp[MAX_N + 1];  // DP 배열을 전역 변수로 선언

// DP를 미리 계산하여 모든 n(1~10)에 대한 결과 저장
void preprocess() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= MAX_N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

int main() {
    int T;  // 테스트 케이스 개수
    scanf("%d", &T);

    int* arr = (int*)malloc(T * sizeof(int));  // 동적 배열 할당
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < T; i++) {
        scanf("%d", &arr[i]);
    }

    preprocess();  // DP 배열 미리 계산

    for (int i = 0; i < T; i++) {
        printf("%d\n", dp[arr[i]]);
    }

    free(arr);  // 메모리 해제
    return 0;
}
