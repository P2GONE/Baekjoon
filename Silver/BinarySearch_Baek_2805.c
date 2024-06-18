#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_N 1000000
#define MAX_M 2000000000
#define MAX_H 1000000000

// 필요한 나무의 길이를 계산하는 함수
long long get_wood_amount(long long trees[], long long n, long long height) {
    long long total = 0;
    for (long long i = 0; i < n; i++) {
        if (trees[i] > height) {
            total += trees[i] - height;
        }
    }
    return total;
}

// 절단기의 최대 높이를 찾는 함수
long long find_max_height(long long trees[], long long n, long long M) {
    long long start = 0;
    long long end = trees[0];

    for (long long i = 1; i < n; i++) {
        if (trees[i] > end) {
            end = trees[i];
        }
    }

    long long answer = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long wood = get_wood_amount(trees, n, mid);

        if (wood >= M) {
            answer = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return answer;
}

int main() {
    long long N;
    long long M;
    long long* arr;

    // 입력받기
    //printf("나무의 수와 필요한 나무의 길이를 입력하세요: ");
    scanf("%lld %lld", &N, &M);

    // 메모리 할당
    arr = (long long*)malloc(N * sizeof(long long));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 나무들의 높이를 입력받기
    //printf("나무들의 높이를 입력하세요: ");
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    // 최대 절단기 높이 계산
    long long result = find_max_height(arr, N, M);
    printf("%lld\n", result);

    // 메모리 해제
    free(arr);

    return 0;
}
