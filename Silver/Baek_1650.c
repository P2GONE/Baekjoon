#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct {
    int x;
    int y;
} coord;
// coord ����ü �� ���ҿ� ���� x�� y�� ������ 
// compare �Լ� �κ��� ���ǿ� ���� �ٲ�
// A���� B���� �ִٰ� ����. A���� coord �迭�� ù ���� ���̰� B���� coord �迭�� �� ��° ����

int compare(const void* A, const void* B) {
    coord* coordA = (coord*)A;
    coord* coordB = (coord*)B;
    // x ���� �������� ��
    // ���� swap���� �ۼ��� �� ������ qsort�� return ���� �̿��ϸ� �� ���ϰ� �ڵ带 �ۼ��� �� ����
    // return 1 : ù ���� ��Ұ� �� ��° ��Һ��� ŭ�� �ǹ���. ���� qsort�� �� ����� ������ �ٲ��� ����
    // return -1 : ù ��° ��Ұ� �� ��° ��Һ��� ������ �ǹ���. ���� qsort�� �� ����� ������ �ٲ�
    // return 0 : �� ��Ұ� ������ �ǹ���. �� ����� ����� ��ġ�� �������� ����
    if (coordA->x > coordB->x) {
        return 1;
    }
    // ���� A�� x��ǥ�� A+1���� Ŭ �� ������ �ٲ��� ����
    else if (coordA->x == coordB->x) {
        if (coordA->y > coordB->y) {
            return 1;
        }
        // ���� A�� x��ǥ�� A+1�� x��ǥ�� ���� ��
        // A�� y��ǥ�� A+1���� Ŭ �� ������ �ٲ��� ����
        else return -1;
        // ������ ��� ������ �ٲ�
    }
    return -1;
    //�������� ��� ������ �ٲ�
}

int main() {
    int total_num;

    // ��ü ������ �Է¹���
    scanf("%d", &total_num);

    // �Է��� coord ����ü �迭�� ������
    // malloc���� �޸� �Ҵ� 
    // ���� ����� ����ü coord�� coords�� �޾Ƽ� ��
    coord* coords = (coord*)malloc(sizeof(coords) * total_num);
    for (int i = 0; i < total_num; i++) {
        scanf("%d %d", &coords[i].x, &coords[i].y);
    }

    // qsort�� ���� ������ ������
    qsort(coords, total_num, sizeof(coord), compare);

    // ���ĵ� ����� ���
    for (int i = 0; i < total_num; i++) {
        printf("%d %d\n", coords[i].x, coords[i].y);
    }

    // �޸� ����
    free(coords);

    return 0;
}
