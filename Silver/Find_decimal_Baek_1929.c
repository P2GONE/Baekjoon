#include <stdio.h>
#pragma warning(disable : 4996)
// �Ҽ��� �׽�Ʈ 

int main(void) {
    int m, n, arr[1000001] = { 0, };
    arr[1] = 1;

    scanf("%d %d", &m, &n);
    // ������ ������� ����, ���ϸ鼭 ��� Ȯ�� 
    for (int i = 2; i <= n; i++) {
        for (int j = 2; i * j <= n; j++) {
            arr[i * j] = 1; // �Ҽ��� �ƴ� 
        }
    }

    for (int i = m; i <= n; i++) {
        if (arr[i] == 0)
            printf("%d\n", i);
    }

    return 0;
}