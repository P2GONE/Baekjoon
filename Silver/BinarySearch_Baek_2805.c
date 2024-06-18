#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_N 1000000
#define MAX_M 2000000000
#define MAX_H 1000000000

// �ʿ��� ������ ���̸� ����ϴ� �Լ�
long long get_wood_amount(long long trees[], long long n, long long height) {
    long long total = 0;
    for (long long i = 0; i < n; i++) {
        if (trees[i] > height) {
            total += trees[i] - height;
        }
    }
    return total;
}

// ���ܱ��� �ִ� ���̸� ã�� �Լ�
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

    // �Է¹ޱ�
    //printf("������ ���� �ʿ��� ������ ���̸� �Է��ϼ���: ");
    scanf("%lld %lld", &N, &M);

    // �޸� �Ҵ�
    arr = (long long*)malloc(N * sizeof(long long));
    if (arr == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    // �������� ���̸� �Է¹ޱ�
    //printf("�������� ���̸� �Է��ϼ���: ");
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    // �ִ� ���ܱ� ���� ���
    long long result = find_max_height(arr, N, M);
    printf("%lld\n", result);

    // �޸� ����
    free(arr);

    return 0;
}
