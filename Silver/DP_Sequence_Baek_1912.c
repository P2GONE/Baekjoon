#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_STACK_SIZE 100000

int main() {
    int count;
    int* arr;
    int* dp;  // DP 배열 선언
    int max;

    scanf("%d", &count);

    arr = (int*)malloc(count * sizeof(int));
    dp = (int*)malloc(count * sizeof(int));  // DP 배열 동적 할당
    if (arr == NULL || dp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // 배열에 값 입력
    for (int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
    
    // DP 초기값 설정
    dp[0] = arr[0];
    max = arr[0];

    // DP
    // condition ? value_if_true : value_if_false;
    // condition : 조건
    // value_if_true : 참일 때 반환
    // value_if_false : 거짓일 때 반환 
    for (int i = 1; i < count; i++) {
        // dp[0]은 배열의 첫 번째 요소로 초기화
        // 이전의 위치까지의 합이 양수라면 현재 요소를 더해서 max여부 확인
        // 이전의 위치까지 합이 음수거나 0이라면 현재 요소를 새로운 부분 수열의 시작으로 바꿈
        dp[i] = (dp[i - 1] > 0) ? dp[i - 1] + arr[i] : arr[i];
        // 최대 부분 합 갱신
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    printf("%d", max);

    // 메모리 해제
    free(arr);
    free(dp);

    return 0;


}
