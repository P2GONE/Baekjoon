#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// % : ������, / : ��

void divis(const int div_num) {
    int count_5 = 0, count_3 = 0;
    int remain = div_num; // ���� ���� �ʱ�ȭ

    // 5�� ���� �� �ִ¸�ŭ ������, ���� ���� 3���� ������ ������ ������ �ݺ�
    while (remain % 5 != 0 && remain >= 0) {
        remain -= 3; // 5�� ���� �� ������ 3�� ����
        count_3++;   // 3���� ä��
    }

    // �������� 3���� ������ ��������
    if (remain % 3 == 0) {
        count_3 += remain / 3; // 3���� ������ �������� �κ��� 3���� ä��
        remain = 0;            // ���� �� �ʱ�ȭ
    }

    // ���� ���� 0�� �ƴϸ� 5�� 3���� ǥ���� �� ����
    if (remain != 0) {
        printf("-1\n");
        return;
    }

    // 5�� 3���� ǥ���� ������ ���� ���
    printf("5�� ����: %d, 3�� ����: %d\n", div_num / 5 - count_5, count_3);
}

int main() {
    int total_num;
    // ��ü ������ �Է¹���
    // �Է��� 3���� 5000������ ����
    scanf("%d", &total_num);
    if (total_num < 3 || total_num > 5000) {
        printf("Wrong input!");
        return 0;
    }
    divis(total_num);

    return 0;
}
