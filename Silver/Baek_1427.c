#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

// 비교 함수
// compare의 오름차순 정렬
// return 음수면 변경, 양수면 변경하지 않음
/*
int comparator(const void* p, const void* q)
{
   int l = ((struct Student*)p)->marks;
   int r = ((struct Student*)q)->marks;
   return (l - r);
   // 앞 부분이 뒷 부분보다 크면 return이 양수, 변경하지 않음. 
   // 오름차순 정렬
}
*/
// compare의 내림차순 정렬
/*
int comparator(const void* p, const void* q)
{
   int l = ((struct Student*)p)->marks;
   int r = ((struct Student*)q)->marks;
   return (r - 1);
   // 앞-뒤>0면 바꿈
   // 내림차순 정렬 
}
*/

int compare(const void* A, const void* B) {
    const int* a = (const int*)A;
    const int* b = (const int*)B;

    return *b - *a; // 내림차순 정렬
}
int main(int argc, char* argv[]) {
    long input_num;
    int count = 0;
    int* num_arr = NULL;

    // 정수 입력 받기
    scanf("%ld", &input_num);
    if (input_num < 0 || input_num > 1000000000) { // 범위 체크
        printf("Wrong input!");
        return 0;
    }

    // 입력된 수의 자릿수 계산
    long temp = input_num;
    if (temp == 0) {
        count = 1; // 0일 경우에도 자릿수는 1
    }
    else {
        while (temp != 0) {
            temp /= 10;
            count++;
        }
    }

    // 동적 메모리 할당
    num_arr = (int*)malloc(count * sizeof(int));
    if (num_arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // 입력된 수의 각 자릿수를 배열에 저장
    for (int i = 0; i < count; i++) {
        num_arr[i] = input_num % 10;
        input_num /= 10;
    }

    // 배열을 내림차순으로 정렬
    qsort(num_arr, count, sizeof(int), compare);

    // 정렬된 배열 출력
    for (int i = 0; i < count; i++) {
        printf("%d", num_arr[i]);
    }
    printf("\n");

    // 동적 할당된 메모리 해제
    free(num_arr);

    return 0;
}
