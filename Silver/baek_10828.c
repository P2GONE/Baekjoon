#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_STACK_SIZE 10000

typedef struct {
    char command[10];
    int value;
} Command;

int stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty() {
    if (top < 0) {
        return 1; // ��� ������ ��Ÿ���� 1 ��ȯ, True
    }
    else {
        return 0; // ������� ������ ��Ÿ���� 0 ��ȯ, False
    }
}

int IsFull() {
    if (top >= MAX_STACK_SIZE - 1) {
        return 1; // ���� ���� ��Ÿ���� 1 ��ȯ, True
    }
    else {
        return 0; // ���� ���� ������ ��Ÿ���� 0 ��ȯ, False
    }
}

void push(int value) {
    if (IsFull() == 1) // ���� �� ����
        printf("������ ���� á���ϴ�.\n");
    else
        stack[++top] = value;
}

int command_top() {
    if (IsEmpty() == 1) // ������ ����ִ� ���
        return -1; // ������ �� ��� -1 ��ȯ
    else
        return stack[top]; // ������ �� ���� �ִ� ���� ��ȯ
}

int command_pop() {
    if (IsEmpty() == 1) // ������ ����ִ� ���
        return -1; // ������ ��������� ��Ÿ���� -1 ��ȯ
    else
        return stack[top--]; // �� ���� �� �����ϰ� ��ȯ
}

void command_size() {
    printf("%d\n", top + 1); // ���ÿ� ����ִ� ������ ���� ���
}

int main() {
    int total_size;
    scanf("%d", &total_size);
    Command* commands = malloc(total_size * sizeof(Command));

    if (commands == NULL) {
        printf("Memory allocation failed.");
        return -1; // indicate failure
    }

    for (int i = 0; i < total_size; i++) {
        //command�� ������
        scanf("%s", commands[i].command);
        //���� command�� push�� �����̸�, push�� �Բ� ����� �ش� ���ڸ� value�� ������
        //���� push�� �������� ������ ����� command�� ������
        if (strcmp(commands[i].command, "push") == 0) {
            scanf("%d", &commands[i].value);
        }
    }

    for (int i = 0; i < total_size; i++) {
        //���ڿ��� pop�� ������ command_pop�� ������
        if (strcmp(commands[i].command, "pop") == 0) {
            //pop�� �����ϰ� ����� print��
            printf("%d\n", command_pop());
        }
        else if (strcmp(commands[i].command, "size") == 0) {
            //size�� ������
            command_size();
        }
        else if (strcmp(commands[i].command, "empty") == 0) {
            //empty�� �����ϰ� ����� print��
            printf("%d\n", IsEmpty());
        }
        else if (strcmp(commands[i].command, "top") == 0) {
            //top�� �����ϰ� ����� print��
            printf("%d\n", command_top());
        }
        else if (strcmp(commands[i].command, "push") == 0) {
            //�ش� value�� push�� ����
            push(commands[i].value);
        }
    }

    free(commands);

    return 0;
}
