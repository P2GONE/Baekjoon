#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main() {
	int checknum;
	int total_num;
	int rest_num;
	int used_num;
	// ������� �迭 ���
	// 1/1
	// 1/2 2/1
	// 3/1 2/2 1/3
	// 1/4 2/3 3/2 4/1
	// 5/1 4/2 3/2 2/3 1/4

	// ������ �� ������ �Է¹���
	scanf("%d", &total_num);
	if (total_num == 1) {
		printf("%d/%d", 1, 1);
		return 0;
	}
	//total_num�� 1�϶��� ó���� �� �����Ƿ� ���� ó����
	
	for (int i = 0; i < 10000000; i++) {
		total_num -= i;
		if (total_num <= 0) {
			used_num = i - 1;
			checknum = (used_num - 1) % 2;
			total_num = total_num + i;
			break;
		}
	}

	if (checknum == 0) { //����� ���� ������ Ȧ���̸�
		printf("%d/%d", total_num, used_num + 2 - total_num );
	}
	if (checknum == 1) { //����� ���� ������ ¦���̸�
		printf("%d/%d", used_num + 2 - total_num, total_num);

	}


}