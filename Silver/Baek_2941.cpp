#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main() {
	char inputarr[100];
	int input_len;
	int new_input_len;
	//�Է��� ����
	scanf("%s", inputarr);
	//input ũ�⸦ input_len�� ������
	input_len = strlen(inputarr);
	//Ư�� ���ڸ� ������ count�� ������
	int counter = 0;
	//�ݺ����� ���� Ư�� ������ ������ Ȯ����
	//���� ũ�ξ�Ƽ�� ���ĺ��� ������ �� counter ���� �÷ȴٸ�, �ش� ���ĺ��� �Ⱦ��� ���� 0���� �ٲ���
	for (int i = 0; i < input_len; i++) {
		if (inputarr[i] == 'c' && inputarr[i + 1] == '=') {
			counter++;
			inputarr[i] = '0';
			inputarr[i + 1] = '0';
		}
		if (inputarr[i] == 'c' && inputarr[i + 1] == '-') {
			counter++;
			inputarr[i] = '0';
			inputarr[i + 1] = '0';
		}
		if (inputarr[i] == 'd' && inputarr[i + 1] == 'z' && inputarr[i+2] == '=') {
			counter += 2;
			inputarr[i] = '0';
			inputarr[i+1] = '0';
			inputarr[i+2] = '0';
		}
		if (inputarr[i] == 'd' && inputarr[i + 1] == '-') {
			counter++;
			inputarr[i] = '0';
			inputarr[i + 1] = '0';
		}
		if (inputarr[i] == 'l' && inputarr[i + 1] == 'j') {
			counter++;
			inputarr[i] = '0';
			inputarr[i + 1] = '0';
		}
		if (inputarr[i] == 'n' && inputarr[i + 1] == 'j') {
			counter++;
			inputarr[i] = '0';
			inputarr[i + 1] = '0';
		}
		if (inputarr[i] == 's' && inputarr[i + 1] == '=') {
			counter++;
			inputarr[i] = '0';
			inputarr[i + 1] = '0';
		}
		if (inputarr[i] == 'z' && inputarr[i + 1] == '=') {
			counter++;
			inputarr[i] = '0';
			inputarr[i + 1] = '0';
		}
	}
	//Ư�����ڸ� �� ���ڿ��� ������ print��
	new_input_len = input_len - counter;
	printf("%d", new_input_len);

	return 0;
}