#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_STACK_SIZE 100000

int stack[MAX_STACK_SIZE];
int top = -1;

/*
���ÿ� push�ϴ� ������ �ݵ�� ����������.
������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ� �� ���� ���� push�� pop ������ ���� ����

*/

int IsEmpty() {
    return top < 0;
}

int IsFull() {
    return top >= MAX_STACK_SIZE - 1;
}

void command_push(int value) {
    if (IsFull()) {
        printf("������ ���� á���ϴ�.\n");
    }
    else {
        stack[++top] = value;
    }
}

int command_pop() {
    if (IsEmpty()) {
        return -1; // ������ ��������� ��Ÿ���� -1 ��ȯ
    }
    else {
        return stack[top--]; // �� ���� �� �����ϰ� ��ȯ
    }
}

void check_Sequence(int arr[], int count) {
    int num = 1;
    int idx = 0;
    char operations[MAX_STACK_SIZE * 2];
    int op_idx = 0;

    for (idx = 0; idx < count; idx++) {
        // ���� ���ڸ� ���ÿ� �־� ������ ���� ���ڿ� �°� ��
        while (num <= arr[idx]) {
            // �ش� �� �������� ���� push��. ���� ��� 4�� �ԷµǸ� 1, 2, 3�� push��
            command_push(num++);
            operations[op_idx++] = '+';
        }
        // ���� �ֻ�� ���ڰ� ������ ���� ���ڿ� ��ġ�ϸ� pop
        if (!IsEmpty() && stack[top] == arr[idx]) {
            // ���� ������ �����ϱ� ������. ���� ������ 4�� �Էµǰ� ���� 3�� �ԷµǸ�, 3���� pop ��Ŵ
            command_pop();
            operations[op_idx++] = '-';
        }
        else {
            printf("NO\n");
            return;
        }
    }

    for (int i = 0; i < op_idx; i++) {
        printf("%c\n", operations[i]);
    }
}

int main() {
    int count;
    int* arr;

    if (scanf("%d", &count) != 1) {
        printf("�߸��� �Է��Դϴ�.\n");
        return 1;
    }

    // ���� �迭 �Ҵ�
    arr = (int*)malloc(count * sizeof(int));
    if (arr == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    // �迭�� �κ� ���� ����
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("�߸��� �Է��Դϴ�.\n");
            free(arr);
            return 1;
        }
    }

    check_Sequence(arr, count);

    free(arr);
    return 0;
}
