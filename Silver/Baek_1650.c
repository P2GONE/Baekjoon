#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

typedef struct {
    int x;
    int y;
} coord;
// coord 구조체 두 원소에 각각 x와 y를 저장함 
// compare 함수 부분임 조건에 따라 바꿈
// A값과 B값이 있다고 하자. A값은 coord 배열의 첫 번쨰 값이고 B값은 coord 배열의 두 번째 값임

int compare(const void* A, const void* B) {
    coord* coordA = (coord*)A;
    coord* coordB = (coord*)B;
    // x 값을 기준으로 비교
    // 직접 swap문을 작성할 수 있으나 qsort의 return 값을 이용하면 더 편하게 코드를 작성할 수 있음
    // return 1 : 첫 번쨰 요소과 두 번째 요소보다 큼을 의미함. 따라서 qsort는 두 요소의 순서를 바꾸지 않음
    // return -1 : 첫 번째 요소가 두 번째 요소보다 작음을 의미함. 따라서 qsort는 두 요소의 순서를 바꿈
    // return 0 : 두 요소가 같음을 의미함. 두 요소의 상대적 위치를 변경하지 않음
    if (coordA->x > coordB->x) {
        return 1;
    }
    // 만약 A의 x좌표가 A+1보다 클 떄 순서를 바꾸지 않음
    else if (coordA->x == coordB->x) {
        if (coordA->y > coordB->y) {
            return 1;
        }
        // 만약 A의 x좌표와 A+1의 x좌표가 같을 떄
        // A의 y좌표가 A+1보다 클 때 순서를 바꾸지 않음
        else return -1;
        // 나머지 경우 순서를 바꿈
    }
    return -1;
    //나머지의 경우 순서를 바꿈
}

int main() {
    int total_num;

    // 전체 갯수를 입력받음
    scanf("%d", &total_num);

    // 입력을 coord 구조체 배열에 저장함
    // malloc으로 메모리 할당 
    // 위에 선언된 구조체 coord를 coords로 받아서 씀
    coord* coords = (coord*)malloc(sizeof(coords) * total_num);
    for (int i = 0; i < total_num; i++) {
        scanf("%d %d", &coords[i].x, &coords[i].y);
    }

    // qsort를 통해 정렬을 진행함
    qsort(coords, total_num, sizeof(coord), compare);

    // 정렬된 결과를 출력
    for (int i = 0; i < total_num; i++) {
        printf("%d %d\n", coords[i].x, coords[i].y);
    }

    // 메모리 해제
    free(coords);

    return 0;
}
