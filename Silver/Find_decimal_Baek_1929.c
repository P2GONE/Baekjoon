#include <stdio.h>
#pragma warning(disable : 4996)
// 소수성 테스트 

int main(void) {
    int m, n, arr[1000001] = { 0, };
    arr[1] = 1;

    scanf("%d %d", &m, &n);
    // 마지막 배수까지 저장, 곱하면서 배수 확인 
    for (int i = 2; i <= n; i++) {
        for (int j = 2; i * j <= n; j++) {
            arr[i * j] = 1; // 소수가 아님 
        }
    }

    for (int i = m; i <= n; i++) {
        if (arr[i] == 0)
            printf("%d\n", i);
    }

    return 0;
}