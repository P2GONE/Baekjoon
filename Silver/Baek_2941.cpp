#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main() {
	char inputarr[100];
	int input_len;
	int new_input_len;
	//입력을 받음
	scanf("%s", inputarr);
	//input 크기를 input_len에 저장함
	input_len = strlen(inputarr);
	//특수 문자를 감지할 count를 선언함
	int counter = 0;
	//반복문을 통해 특수 문자의 갯수를 확인함
	//만약 크로아티아 알파벳을 인지한 후 counter 값을 올렸다면, 해당 알파벳을 안쓰는 수인 0으로 바꿔줌
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
	//특수문자를 뺀 문자열의 갯수를 print함
	new_input_len = input_len - counter;
	printf("%d", new_input_len);

	return 0;
}