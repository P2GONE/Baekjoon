#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
// 문자열 비교 함수 (qsort()에 사용)
int compare(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // 동적 배열 할당 (각 문자열의 길이를 최대 20으로 가정)
    char** arrN = (char**)malloc(N * sizeof(char*));
    char** arrM = (char**)malloc(M * sizeof(char*));

    if (arrN == NULL || arrM == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        arrN[i] = (char*)malloc(21 * sizeof(char));  // 최대 길이 20 + NULL 문자
        scanf("%s", arrN[i]);
    }

    for (int i = 0; i < M; i++) {
        arrM[i] = (char*)malloc(21 * sizeof(char));
        scanf("%s", arrM[i]);
    }

    // 듣도 못한 사람을 해시 테이블(정렬 후 이진 탐색)로 활용
    qsort(arrN, N, sizeof(char*), compare);  // arrN 정렬

    // 듣보잡 리스트를 저장할 배열
    char** common = (char**)malloc((N < M ? N : M) * sizeof(char*));
    int count = 0;

    for (int i = 0; i < M; i++) {
        if (bsearch(&arrM[i], arrN, N, sizeof(char*), compare)) {  // 이진 탐색
            common[count] = arrM[i];  // 보도 못한 사람 중 듣도 못한 사람 추가
            count++;
        }
    }

    // 듣보잡 리스트 정렬 후 출력
    qsort(common, count, sizeof(char*), compare);

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", common[i]);
    }

    // 메모리 해제
    for (int i = 0; i < N; i++) free(arrN[i]);
    for (int i = 0; i < M; i++) free(arrM[i]);
    free(arrN);
    free(arrM);
    free(common);

    return 0;
}
