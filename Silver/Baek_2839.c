#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void print_remain(const int remain, const int remain_3, const int remain_5, const int count) {
    printf("%d", remain_3 + remain_5 + count - 1);
}

// % : 나머지, / : 몫
void divis(const int div_num) {
    int count_5 = 0, count = 0;
    int tmp_count_5 = 0, tmp_count_3 = 0;
    int remain = div_num; 

    // 예외 처리: 입력이 6 또는 9인 경우
    if (div_num == 6) {
        printf("2");
        return;
    }
    if (div_num == 9) {
        printf("3");
        return;
    }

    // 5로 나눌 수 있는만큼 나누고, 남은 수를 3으로 나누어 떨어질 때까지 반복
    while (remain > 0) {
        //5로 나눔
        if (remain % 5 == 0) {
            tmp_count_5 = remain / 5;
        }
        //3으로 나눔
        if (remain % 3 == 0) {
            tmp_count_3 = remain / 3;
        }
        count++;
        if (remain == 3 || remain == 5 || remain == 0) {
            print_remain(remain, tmp_count_3, tmp_count_5, count);
            return;
        }
        remain = remain - 5;
    }
    if (tmp_count_3 > 0 || tmp_count_5 > 0) {
        print_remain(remain, tmp_count_3, tmp_count_5, count - 1);
        return;
    }
    printf("-1");
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
