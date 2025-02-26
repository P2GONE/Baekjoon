#include <iostream>
#include <vector>

using namespace std;

// 모든 값이 동일한지 검사하는 함수
bool is_full(const vector<vector<int>>& grid, int size, int& color) {
    color = grid[0][0]; // 첫 번째 값으로 기준 설정
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] != color) {
                // 한 칸의 색이 하나라도 다르면 false => 쪼갬
                return false;
            }
        }
    }
    return true;
}

// 재귀적으로 1과 0 개수를 세는 함수
void count_papers(const vector<vector<int>>& grid, int size, int& count0, int& count1) {
    int color;
    if (is_full(grid, size, color)) {   // 모두 색이 같다면 분할 없이 개수 증가 
        if (color == 1) count1++;       // 만약 다 같은색이고 그 color가 1이면 count1값 증가
        else count0++;                  // 만약 다 같은색이고 그 color가 0이면 count0값 증가 
        return;
    }

    // 만약 하나의 통일된 색이 나오면 is_full 계산 진행
    // 만약 그렇지 않다면 1/2로 쪼갠 후 4개의 구역을 나눠 재귀적으로 확인

    int half = size / 2;
    vector<vector<int>> topLeft(half, vector<int>(half));
    vector<vector<int>> topRight(half, vector<int>(half));
    vector<vector<int>> bottomLeft(half, vector<int>(half));
    vector<vector<int>> bottomRight(half, vector<int>(half));

    // 4등분된 영역을 새 배열로 나누기
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            topLeft[i][j] = grid[i][j];
            topRight[i][j] = grid[i][j + half];
            bottomLeft[i][j] = grid[i + half][j];
            bottomRight[i][j] = grid[i + half][j + half];
        }
    }

    count_papers(topLeft, half, count0, count1);
    count_papers(topRight, half, count0, count1);
    count_papers(bottomLeft, half, count0, count1);
    count_papers(bottomRight, half, count0, count1);
}

int main() {
    int num;
    cin >> num;

    vector<vector<int>> field(num, vector<int>(num));

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> field[i][j];
        }
    }

    int count0 = 0, count1 = 0;
    count_papers(field, num, count0, count1);

    cout << count0 << '\n' << count1 << endl;
    return 0;
}
