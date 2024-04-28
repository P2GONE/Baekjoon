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
        return 1; // 비어 있음을 나타내는 1 반환, True
    }
    else {
        return 0; // 비어있지 않음을 나타내는 0 반환, False
    }
}

int IsFull() {
    if (top >= MAX_STACK_SIZE - 1) {
        return 1; // 가득 참을 나타내는 1 반환, True
    }
    else {
        return 0; // 가득 차지 않음을 나타내는 0 반환, False
    }
}

void push(int value) {
    if (IsFull() == 1) // 가득 찬 상태
        printf("스택이 가득 찼습니다.\n");
    else
        stack[++top] = value;
}

int command_top() {
    if (IsEmpty() == 1) // 스택이 비어있는 경우
        return -1; // 스택이 빈 경우 -1 반환
    else
        return stack[top]; // 스택의 맨 위에 있는 정수 반환
}

int command_pop() {
    if (IsEmpty() == 1) // 스택이 비어있는 경우
        return -1; // 스택이 비어있음을 나타내는 -1 반환
    else
        return stack[top--]; // 맨 위의 값 제거하고 반환
}

void command_size() {
    printf("%d\n", top + 1); // 스택에 들어있는 정수의 개수 출력
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
        //command를 저장함
        scanf("%s", commands[i].command);
        //만약 command에 push가 포함이면, push와 함께 저장된 해당 숫자를 value에 저장함
        //만약 push를 포함하지 않으면 명령을 command에 저장함
        if (strcmp(commands[i].command, "push") == 0) {
            scanf("%d", &commands[i].value);
        }
    }

    for (int i = 0; i < total_size; i++) {
        //문자열에 pop이 있으면 command_pop을 실행함
        if (strcmp(commands[i].command, "pop") == 0) {
            //pop을 실행하고 결과를 print함
            printf("%d\n", command_pop());
        }
        else if (strcmp(commands[i].command, "size") == 0) {
            //size를 실행함
            command_size();
        }
        else if (strcmp(commands[i].command, "empty") == 0) {
            //empty를 실행하고 결과를 print함
            printf("%d\n", IsEmpty());
        }
        else if (strcmp(commands[i].command, "top") == 0) {
            //top을 실행하고 결과를 print함
            printf("%d\n", command_top());
        }
        else if (strcmp(commands[i].command, "push") == 0) {
            //해당 value를 push에 넣음
            push(commands[i].value);
        }
    }

    free(commands);

    return 0;
}
