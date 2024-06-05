#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int count_0;
    int count_1;
} FibonacciResult;

// ���� �迭�� �޸������̼� ���̺� ����
FibonacciResult memo[41];

FibonacciResult fibonacci(int n) {
    if (memo[n].value != -1) {
        return memo[n];
    }

    if (n == 0) {
        memo[n].value = 0;
        memo[n].count_0 = 1;
        memo[n].count_1 = 0;
    }
    else if (n == 1) {
        memo[n].value = 1;
        memo[n].count_0 = 0;
        memo[n].count_1 = 1;
    }
    else {
        FibonacciResult res1 = fibonacci(n - 1);
        FibonacciResult res2 = fibonacci(n - 2);
        memo[n].value = res1.value + res2.value;
        memo[n].count_0 = res1.count_0 + res2.count_0;
        memo[n].count_1 = res1.count_1 + res2.count_1;
    }

    return memo[n];
}

int main() {
    int T, * arr;
    FibonacciResult result;

    // �޸������̼� ���̺� �ʱ�ȭ
    for (int i = 0; i < 41; i++) {
        memo[i].value = -1;
        memo[i].count_0 = -1;
        memo[i].count_1 = -1;
    }

    scanf("%d", &T);

    // ���� �迭 �Ҵ�
    arr = (int*)malloc(T * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // �迭�� �� �Է�
    for (int i = 0; i < T; i++) {
        scanf("%d", &arr[i]);
    }

    // �� �迭 ��ҿ� ���� �Ǻ���ġ �Լ� ȣ�� �� ��� ���
    for (int i = 0; i < T; i++) {
        result = fibonacci(arr[i]);
        printf("%d %d\n", result.count_0, result.count_1);
    }

    free(arr);
    return 0;
}
