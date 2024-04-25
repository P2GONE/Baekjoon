#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// div_num = 5 *a + 3*b �������� ǥ����
// ���� 5*a + 3*b �������� ǥ����� �ʴ´ٸ� -1�� ����� return
// �Է°��� ��� ������ �������ٸ� ������ ������ ���� print��
// div_num�� 3���� ��� �� �� ������ ���������� ���θ� Ȯ����
// �ִ��� a�� ���� �������ؾ��� <- �� ������ �ٽ� 
// % : ������, / : ��
void divis(const int div_num) {
    int count_5 = 0, count = 0;
    int remain = div_num; 

    // 3�� ��� ���鼭 �ִ��� 5�� ��������� �� ���� �� ���� �ݺ���
    while (1) {
        //5�� �켱������ ���� �� �ִ��� Ȯ����
        if (remain % 5 == 0) {
            count_5 = remain / 5;
            break;
            //5�� �ִ��� �������� -> ��
        }
        remain = remain - 3;
        count++;
        if (remain <= 0) {
            break;
        }
    }
    // �̷��� �ϸ� ������ �������� �� ���� �ʱ�ȭ�� �ʿ䰡 ����
    // �׷��ٸ� ���� ���̽��� �߻��� �� �ִ� ��� (a,b) �������� ���� ������ ��츦 �����ص� ��
    if (remain < 0) {
        printf("-1");
    }
    else {
        printf("%d", count + count_5);
    }
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
