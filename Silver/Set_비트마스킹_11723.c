#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
int main() {
    int M, S = 0, x;
    char command[10];

    scanf("%d", &M);

    while (M--) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%d", &x);
            S |= (1 << (x - 1));  // x번째 비트 ON
            // 특정 비트를 1로 설정
        }
        else if (strcmp(command, "remove") == 0) {
            scanf("%d", &x);
            S &= ~(1 << (x - 1));  // x번째 비트 OFF
            // 비트 반전, x번째 비트를 0으로 설정, 집합에서 제거
        }
        else if (strcmp(command, "check") == 0) {
            scanf("%d", &x);
            printf("%d\n", (S & (1 << (x - 1))) ? 1 : 0);  // x번째 비트 확인
            // x번째 비트가 1이면 1, 0이면 0을 출력
        }
        else if (strcmp(command, "toggle") == 0) {
            scanf("%d", &x);
            S ^= (1 << (x - 1));  // x번째 비트 반전
            // x번째 비트를 반전 
        }
        else if (strcmp(command, "all") == 0) {
            S = (1 << 20) - 1;  // {1, 2, ..., 20} 모든 비트 ON
            // 1 << 20은 100000000000000000000
            // (1 << 20) -1 하면 20비트 모두 1 
        }
        else if (strcmp(command, "empty") == 0) {
            S = 0;  // 공집합으로 설정 (모든 비트 OFF)
            // 모든 비트를 0으로 변경 
        }
    }

    return 0;
}
