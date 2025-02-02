#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>  // INT_MAX 사용
#pragma warning(disable : 4996)
#define MAX_LEN 10000  // 문자열 최대 길이

// 특정 문자가 정확히 K개 포함된 가장 짧은 연속 문자열 찾기 (O(N))
int findShortestSubstring(char* str, char target, int k) {
    int n = strlen(str);
    int left = 0, right = 0, count = 0;
    int min_length = INT_MAX;

    while (right < n) {
        if (str[right] == target) {
            count++;
        }

        while (count == k) {
            min_length = (right - left + 1) < min_length ? (right - left + 1) : min_length;
            if (str[left] == target) {
                count--;
            }
            left++;
        }

        right++;
    }

    return (min_length == INT_MAX) ? -1 : min_length;
}

// target : a~z
int findLongestSubstring(char* str, char target, int k) {
    int n = strlen(str);
    int max_length = -1;
    int left = 0, right = 0, count = 0;

    while (right < n) {  
        if (str[right] == target) {
            count++;
        }

        while (count == k) {  // 정확히 K개일 때 왼쪽 포인터 조정
            if (str[left] == target && str[right] == target) {
                max_length = (right - left + 1 > max_length) ? right - left + 1 : max_length;
            }
            if (str[left] == target) {
                count--;
            }
            left++;
        }

        right++;
    }

    return max_length;
}


int main() {
    int T;
    scanf("%d", &T);

    // 동적 할당을 통한 입력 저장
    char** strArray = (char**)malloc(T * sizeof(char*));
    int* kArray = (int*)malloc(T * sizeof(int));
    int** results = (int**)malloc(T * sizeof(int*));

    if (!strArray || !kArray || !results) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < T; i++) {
        strArray[i] = (char*)malloc((MAX_LEN + 1) * sizeof(char));
        results[i] = (int*)malloc(2 * sizeof(int));  // [0]: 최소 길이, [1]: 최대 길이

        if (!strArray[i] || !results[i]) {
            printf("메모리 할당 실패\n");
            return 1;
        }

        scanf("%s", strArray[i]);
        scanf("%d", &kArray[i]);
    }

    // 입력된 모든 문자열을 처리하여 결과 저장
    for (int i = 0; i < T; i++) {
        int k = kArray[i];
        int min_result = INT_MAX;
        int max_result = -1;

        for (char target = 'a'; target <= 'z'; target++) {
            int min_length = findShortestSubstring(strArray[i], target, k);
            int max_length = findLongestSubstring(strArray[i], target, k);

            if (min_length != -1) {
                min_result = (min_length < min_result) ? min_length : min_result;
            }
            if (max_length != -1) {
                max_result = (max_length > max_result) ? max_length : max_result;
            }
        }

        if (min_result == INT_MAX) {
            results[i][0] = -1;
            results[i][1] = -1;
        }
        else {
            results[i][0] = min_result;
            results[i][1] = max_result;
        }
    }

    // 최종적으로 모든 결과를 한 번에 출력
    for (int i = 0; i < T; i++) {
        if (results[i][0] == -1) {
            printf("-1\n");
        }
        else {
            printf("%d %d\n", results[i][0], results[i][1]);
        }
    }

    // 동적 할당 해제
    for (int i = 0; i < T; i++) {
        free(strArray[i]);
        free(results[i]);
    }
    free(strArray);
    free(kArray);
    free(results);

    return 0;
}
