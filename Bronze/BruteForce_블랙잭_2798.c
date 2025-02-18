#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// 정렬을 위한 비교 함수
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, total;
    scanf("%d %d", &N, &total);

    int* input_buffer = (int*)malloc(N * sizeof(int));
    if (input_buffer == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 입력 받기
    for (int i = 0; i < N; i++) {
        scanf("%d", &input_buffer[i]);
    }

    // 오름차순 정렬 (투 포인터를 위해 필요)
    qsort(input_buffer, N, sizeof(int), compare);

    int closestSum = 0;  // 가장 가까운 합 저장

    // 투 포인터 탐색 (O(N²))
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            int sum = input_buffer[i] + input_buffer[left] + input_buffer[right];

            // total을 넘지 않는 가장 큰 합을 갱신
            if (sum <= total && sum > closestSum) {
                closestSum = sum;
            }

            if (sum < total) left++;     // 합이 작으면 left 증가
            else right--;                // 합이 크면 right 감소
        }
    }

    printf("%d\n", closestSum);

    // 메모리 해제
    free(input_buffer);

    return 0;
}
