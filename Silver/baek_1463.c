#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_NUM 100000

// % : 나머지, / : 몫
void divid(const int num) {
    int remain = num, count = 0;
    while (remain > 1) {
        // X가 3으로 나누어 떨어지면, 3으로 나눈다.
        if (remain % 3 == 0 && remain > 3) {
            remain /= 3;
        }
        // 3으로 나눈 나머지가 1인 경우, 1을 빼고 3으로 나눈다.
        else if (remain % 3 == 1 && remain > 3) {
            remain = remain - 1;
            remain /= 3;
            count++;
        }
        // 3으로 나눈 나머지가 2인 경우, 1을 뺀 뒤 진행
        else if (remain % 3 == 2 && remain > 3) {
            remain--;
            count++;
        }
        // X가 2로 나누어 떨어지면, 2로 나눈다.
        else if (remain % 2 == 0) {
            remain /= 2;
        }
        // 2로 나눈 나머지가 1인 경우, 1을 뺀 뒤 진행
        else {
            remain--;
            count++;
        }
    }
    printf("%d", count+1);
}





int main() {
    int total_num;
    // 전체 갯수를 입력받음
    // 입력은 3부터 5000까지의 값임
    scanf("%d", &total_num);
    if (total_num < 1 || total_num > MAX_NUM) {
        printf("Wrong input!");
        return 0;
    }
    divid(total_num);
}