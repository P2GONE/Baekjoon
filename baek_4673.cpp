#include <stdio.h>
#define MAXNUM 10000

int do_self(int n) {
	int sum = n;
	while (n > 0) {
		sum += n % 10;
		// �ڸ����� sum�� ������Ʈ�� 
		// 10���� ���� �������� ��� ����
		n /= 10;
		// n�� 10���� ���� ������ ������Ʈ��, n�� �ڸ����� �ǹ���
	}
	return sum;
	//self num�� ������ return
}


int main() {
	//do_self�� ������ �Ǻ�
	for (int i = 1; i <= MAXNUM; i++) {
		int self_flag = 0;
		for (int j = 1; j <= MAXNUM; j++) {
			//do_self�� ��� ���� input�� ���� �ʴٸ� �ش� ���� �����
			if (do_self(j) == i) {
				self_flag = 1;
				//���� selfnum�̶�� self_flag�� ture�� �ٲ�
			}
		}
		if (!self_flag) {
			//���� selfnum�� �ƴϸ� self_flag�� false��. �̸� �����ؼ� �����
			printf("%d\n", i);
		}

	}

	return 0;
}