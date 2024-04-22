#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// % : 나머지, / : 몫

void divis(const int div_num) {
    int count_5 = 0, count_3 = 0;
    int remain = div_num; // 남은 수를 초기화

    // 5로 나눌 수 있는만큼 나누고, 남은 수를 3으로 나누어 떨어질 때까지 반복
    while (remain % 5 != 0 && remain >= 0) {
        remain -= 3; // 5로 나눌 수 없으면 3을 빼고
        count_3++;   // 3으로 채움
    }

    // 나머지가 3으로 나누어 떨어지면
    if (remain % 3 == 0) {
        count_3 += remain / 3; // 3으로 나누어 떨어지는 부분을 3으로 채움
        remain = 0;            // 남은 수 초기화
    }

    // 남은 수가 0이 아니면 5와 3으로 표현할 수 없음
    if (remain != 0) {
        printf("-1\n");
        return;
    }

    // 5와 3으로 표현한 봉지의 개수 출력
    printf("5의 개수: %d, 3의 개수: %d\n", div_num / 5 - count_5, count_3);
}

int main() {
    int total_num;
    // 전체 갯수를 입력받음
    // 입력은 3부터 5000까지의 값임
    scanf("%d", &total_num);
    if (total_num < 3 || total_num > 5000) {
        printf("Wrong input!");
        return 0;
    }
    divis(total_num);

    return 0;
}
