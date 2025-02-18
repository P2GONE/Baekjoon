#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_BUF 99999

int find_Palindrome(const char * str) {
	int tmp_len = strlen(str);
	char* tmp = (char*)malloc(tmp_len + 1);
	for (int i = 0; i < strlen(str); i++) {
		tmp[i] = str[tmp_len - i - 1];
	}
	tmp[tmp_len] = '\0';
	// strcmp를 위해 \0 널문자 삽입
	int check_Palindrome = (strcmp(tmp, str) == 0);
	free(tmp);

	return check_Palindrome;
}

int main() {
	char buf [MAX_BUF];
	while (1) {
		scanf("%s", buf);
		if (strcmp(buf, "0") == 0) break;
		if (find_Palindrome(buf)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}