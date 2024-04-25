#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// div_num = 5 *a + 3*b 형식으로 표기함
// 만약 5*a + 3*b 형식으로 표기되지 않는다면 -1을 출력후 return
// 입력값이 모두 나누어 떨어진다면 나누어 떨어진 몫을 print함
// div_num을 3으로 계속 뺀 뒤 나누어 떨어지는지 여부를 확인함
// 최대한 a가 많이 갖도록해야함 <- 이 문제의 핵심 
// % : 나머지, / : 몫
void divis(const int div_num) {
    int count_5 = 0, count = 0;
    int remain = div_num; 

    // 3을 계속 빼면서 최대한 5로 나누어떨어질 수 있을 때 까지 반복함
    while (1) {
        //5로 우선적으로 나뉠 수 있는지 확인함
        if (remain % 5 == 0) {
            count_5 = remain / 5;
            break;
            //5로 최대한 나뉘어짐 -> 끝
        }
        remain = remain - 3;
        count++;
        if (remain <= 0) {
            break;
        }
    }
    // 이렇게 하면 나누어 떨어졌을 떄 값을 초기화할 필요가 없음
    // 그렇다면 여러 케이스가 발생할 수 있는 경우 (a,b) 순서쌍이 여럿 존재할 경우를 무시해도 됨
    if (remain < 0) {
        printf("-1");
    }
    else {
        printf("%d", count + count_5);
    }
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
