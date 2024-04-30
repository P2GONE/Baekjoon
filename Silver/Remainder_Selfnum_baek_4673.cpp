#include <stdio.h>
#define MAXNUM 10000

int do_self(int n) {
	int sum = n;
	while (n > 0) {
		sum += n % 10;
		// 자릿수를 sum에 업데이트함 
		// 10으로 나눈 나머지를 계속 더함
		n /= 10;
		// n을 10으로 나눈 몫으로 업데이트함, n은 자릿수를 의미함
	}
	return sum;
	//self num을 만든후 return
}


int main() {
	//do_self와 같은지 판별
	for (int i = 1; i <= MAXNUM; i++) {
		int self_flag = 0;
		for (int j = 1; j <= MAXNUM; j++) {
			//do_self의 결과 값이 input과 같지 않다면 해당 값을 출력함
			if (do_self(j) == i) {
				self_flag = 1;
				//만약 selfnum이라면 self_flag를 ture로 바꿈
			}
		}
		if (!self_flag) {
			//만약 selfnum이 아니면 self_flag가 false임. 이를 감지해서 출력함
			printf("%d\n", i);
		}

	}

	return 0;
}
