#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// �� �Լ�
// compare�� �������� ����
// return ������ ����, ����� �������� ����
/*
int comparator(const void* p, const void* q)
{
   int l = ((struct Student*)p)->marks;
   int r = ((struct Student*)q)->marks;
   return (l - r);
   // �� �κ��� �� �κк��� ũ�� return�� ���, �������� ����. 
   // �������� ����
}
*/
// compare�� �������� ����
/*
int comparator(const void* p, const void* q)
{
   int l = ((struct Student*)p)->marks;
   int r = ((struct Student*)q)->marks;
   return (r - 1);
   // ��-��>0�� �ٲ�
   // �������� ���� 
}
*/

int compare(const void* A, const void* B) {
    const int* a = (const int*)A;
    const int* b = (const int*)B;

    return *b - *a; // �������� ����
}
int main(int argc, char* argv[]) {
    long input_num;
    int count = 0;
    int* num_arr = NULL;

    // ���� �Է� �ޱ�
    scanf("%ld", &input_num);
    if (input_num < 0 || input_num > 1000000000) { // ���� üũ
        printf("Wrong input!");
        return 0;
    }

    // �Էµ� ���� �ڸ��� ���
    long temp = input_num;
    if (temp == 0) {
        count = 1; // 0�� ��쿡�� �ڸ����� 1
    }
    else {
        while (temp != 0) {
            temp /= 10;
            count++;
        }
    }

    // ���� �޸� �Ҵ�
    num_arr = (int*)malloc(count * sizeof(int));
    if (num_arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // �Էµ� ���� �� �ڸ����� �迭�� ����
    for (int i = 0; i < count; i++) {
        num_arr[i] = input_num % 10;
        input_num /= 10;
    }

    // �迭�� ������������ ����
    qsort(num_arr, count, sizeof(int), compare);

    // ���ĵ� �迭 ���
    for (int i = 0; i < count; i++) {
        printf("%d", num_arr[i]);
    }
    printf("\n");

    // ���� �Ҵ�� �޸� ����
    free(num_arr);

    return 0;
}
