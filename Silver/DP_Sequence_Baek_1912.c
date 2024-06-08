#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_STACK_SIZE 100000

int main() {
    int count;
    int* arr;
    int* dp;  // DP �迭 ����
    int max;

    scanf("%d", &count);

    arr = (int*)malloc(count * sizeof(int));
    dp = (int*)malloc(count * sizeof(int));  // DP �迭 ���� �Ҵ�
    if (arr == NULL || dp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // �迭�� �� �Է�
    for (int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
    
    // DP �ʱⰪ ����
    dp[0] = arr[0];
    max = arr[0];

    // DP
    // condition ? value_if_true : value_if_false;
    // condition : ����
    // value_if_true : ���� �� ��ȯ
    // value_if_false : ������ �� ��ȯ 
    for (int i = 1; i < count; i++) {
        // dp[0]�� �迭�� ù ��° ��ҷ� �ʱ�ȭ
        // ������ ��ġ������ ���� ������ ���� ��Ҹ� ���ؼ� max���� Ȯ��
        // ������ ��ġ���� ���� �����ų� 0�̶�� ���� ��Ҹ� ���ο� �κ� ������ �������� �ٲ�
        dp[i] = (dp[i - 1] > 0) ? dp[i - 1] + arr[i] : arr[i];
        // �ִ� �κ� �� ����
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    printf("%d", max);

    // �޸� ����
    free(arr);
    free(dp);

    return 0;


}
