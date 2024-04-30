#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_NUM 100000

// % : ������, / : ��
void divid(const int num) {
    int remain = num, count = 0;
    while (remain > 1) {
        // X�� 3���� ������ ��������, 3���� ������.
        if (remain % 3 == 0 && remain > 3) {
            remain /= 3;
        }
        // 3���� ���� �������� 1�� ���, 1�� ���� 3���� ������.
        else if (remain % 3 == 1 && remain > 3) {
            remain = remain - 1;
            remain /= 3;
            count++;
        }
        // 3���� ���� �������� 2�� ���, 1�� �� �� ����
        else if (remain % 3 == 2 && remain > 3) {
            remain--;
            count++;
        }
        // X�� 2�� ������ ��������, 2�� ������.
        else if (remain % 2 == 0) {
            remain /= 2;
        }
        // 2�� ���� �������� 1�� ���, 1�� �� �� ����
        else {
            remain--;
            count++;
        }
    }
    printf("%d", count+1);
}





int main() {
    int total_num;
    // ��ü ������ �Է¹���
    // �Է��� 3���� 5000������ ����
    scanf("%d", &total_num);
    if (total_num < 1 || total_num > MAX_NUM) {
        printf("Wrong input!");
        return 0;
    }
    divid(total_num);
}