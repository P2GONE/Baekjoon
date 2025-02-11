#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// Cycle Sort 알고리즘 (정수 배열 정렬)
void cycleSort(int arr[], int n) {
    for (int cycle_start = 0; cycle_start < n - 1; cycle_start++) {
        int item = arr[cycle_start];  // 현재 정렬할 값
        int pos = cycle_start;        // 올바른 위치 찾기

        // 현재 요소(item)가 있어야 할 위치(pos) 찾기
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) {
                pos++;
            }
        }

        // 이미 정렬된 경우
        if (pos == cycle_start) {
            continue;
        }

        // 중복된 값이 있는 경우 위치 조정
        while (item == arr[pos]) {
            pos++;
        }

        // 현재 요소(item)를 올바른 위치(pos)에 삽입
        if (pos != cycle_start) {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
        }

        // 다른 요소들도 사이클을 따라 정렬
        while (pos != cycle_start) {
            pos = cycle_start;

            // 새 위치 찾기
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) {
                    pos++;
                }
            }

            // 중복된 값이 있으면 위치 조정
            while (item == arr[pos]) {
                pos++;
            }

            // 스왑
            if (item != arr[pos]) {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
            }
        }
    }
}

int main() {
    int total_num;
    scanf("%d", &total_num);  // 정수 개수 입력

    // 정수 배열 동적 할당
    int* arr = (int*)malloc(total_num * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // 정수 입력 받기
    for (int i = 0; i < total_num; i++) {
        scanf("%d", &arr[i]);
    }

    // Cycle Sort 실행
    cycleSort(arr, total_num);

    // 정렬된 결과 출력
    for (int i = 0; i < total_num; i++) {
        printf("%d\n", arr[i]);
    }

    // 메모리 해제
    free(arr);

    return 0;
}
