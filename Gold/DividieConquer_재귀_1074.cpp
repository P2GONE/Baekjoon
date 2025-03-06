#include <iostream>
using namespace std;

int count_level = 0;  // 방문 순서 저장 변수

// Z-모양 탐색을 수행하는 재귀 함수
void countZ(int size, int row, int col, int r, int c) {

    if (size == 1) {
        // 더 이상 나눌 수 없는 1x1 크기라면 탐색 완료
        if (row == r && col == c) {
            cout << count_level << endl;  // 방문 순서 출력
        }
        count_level++;
        return;
    }

    int half = size / 2;  // 현재 영역의 절반 크기

    // 4개의 사분면 중 어느 영역에 속하는지 확인
    if (r < row + half && c < col + half) {
        // 좌상단 (1번째 사분면)
        countZ(half, row, col, r, c);
    }
    else if (r < row + half && c >= col + half) {
        // 우상단 (2번째 사분면)
        count_level += half * half;
        countZ(half, row, col + half, r, c);
    }
    else if (r >= row + half && c < col + half) {
        // 좌하단 (3번째 사분면)
        count_level += 2 * half * half;
        countZ(half, row + half, col, r, c);
    }
    else {
        // 우하단 (4번째 사분면)
        count_level += 3 * half * half;
        countZ(half, row + half, col + half, r, c);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;  // 크기 N과 좌표 r, c 입력

    int size = 1 << N;  // 2^N 크기의 행렬
    countZ(size, 0, 0, r, c);  // Z-탐색 시작
}
