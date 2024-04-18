#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAXNUM 20000
#define MAXLEN 50

// ���ڿ� �� �Լ�
int compare(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    // ���� ���ڿ��� ���̸� ��
    int lengthCompare = strlen(str1) - strlen(str2);
    if (lengthCompare != 0) // ���̰� �ٸ��� ���̿� ���� ��
        return lengthCompare;
    else // ���̰� ������ ���ĺ� ������ ��
        return strcmp(str1, str2);
}

int main() {
    int total_num = 0;
    char** arr;

    // ������ �� ������ �Է¹���
    scanf("%d", &total_num);

    // �������� �迭 �Ҵ�
    arr = (char**)malloc(total_num * sizeof(char*));
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return -1; // indicate failure
    }

    // �Էµ��� �迭�� ������
    for (int i = 0; i < total_num; i++) {
        arr[i] = (char*)malloc((MAXLEN + 1) * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation failed.");
            return -1; // indicate failure
        }
        // ���ڿ� �Է¹���
        scanf("%s", arr[i]);
    }

    // ���ڿ��� ����
    qsort(arr, total_num, sizeof(char*), compare);

    // �ߺ� ���� �� ���
    printf("%s\n", arr[0]);
    for (int i = 1; i < total_num; i++) {
        if (strcmp(arr[i], arr[i - 1]) != 0) {
            printf("%s\n", arr[i]);
        }
    }

    // ���� �Ҵ� ����
    for (int i = 0; i < total_num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
