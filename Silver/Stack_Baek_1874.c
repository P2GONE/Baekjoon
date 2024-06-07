#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define MAX_STACK_SIZE 100000

int stack[MAX_STACK_SIZE];
int top = -1;

/*
스택에 push하는 순서는 반드시 오름차순임.
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는 지 없는 지를 push와 pop 연산을 통해 수행

*/

int IsEmpty() {
    return top < 0;
}

int IsFull() {
    return top >= MAX_STACK_SIZE - 1;
}

void command_push(int value) {
    if (IsFull()) {
        printf("스택이 가득 찼습니다.\n");
    }
    else {
        stack[++top] = value;
    }
}

int command_pop() {
    if (IsEmpty()) {
        return -1; // 스택이 비어있음을 나타내는 -1 반환
    }
    else {
        return stack[top--]; // 맨 위의 값 제거하고 반환
    }
}

void check_Sequence(int arr[], int count) {
    int num = 1;
    int idx = 0;
    char operations[MAX_STACK_SIZE * 2];
    int op_idx = 0;

    for (idx = 0; idx < count; idx++) {
        // 현재 숫자를 스택에 넣어 수열의 현재 숫자에 맞게 함
        while (num <= arr[idx]) {
            // 해당 값 전까지의 수를 push함. 예를 들어 4가 입력되면 1, 2, 3이 push됨
            command_push(num++);
            operations[op_idx++] = '+';
        }
        // 스택 최상단 숫자가 수열의 현재 숫자와 일치하면 pop
        if (!IsEmpty() && stack[top] == arr[idx]) {
            // 오름 차순을 유지하기 위함임. 만약 위에서 4가 입력되고 현재 3이 입력되면, 3까지 pop 시킴
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
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    // 동적 배열 할당
    arr = (int*)malloc(count * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 배열에 부분 수열 저장
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            free(arr);
            return 1;
        }
    }

    check_Sequence(arr, count);

    free(arr);
    return 0;
}
