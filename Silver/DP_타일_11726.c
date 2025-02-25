#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_N 1000

int dp[MAX_N] = { 0};

void dynamicp(int value) {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= value; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
}

int main() {
    int num;                // 테스트 케이스 개수
    scanf("%d", &num);

    dynamicp(num);
    printf("%d", dp[num]);

    return 0;
}