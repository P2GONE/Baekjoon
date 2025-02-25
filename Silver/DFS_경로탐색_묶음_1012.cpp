#include <vector>
#include <iostream>
using namespace std;

// 방향 벡터 (상, 하, 좌, 우)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// DFS 탐색 함수
void dfs(vector<vector<int>>& grid, int x, int y) {
    int m = grid[0].size();     // 가로
    int n = grid.size();        // 세로

    grid[x][y] = 0; // 현 위치 0으로 처리 

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
            dfs(grid, nx, ny);
        }
    }
}

int main() {
    int num, M, N, K;                // 테스트 케이스 개수
    int worm = 0;

    // 전체 입력
    cin >> num;

    while (num --) {

        // 가로 : M, 세로 : N, 배추 위치 개수 : K
        cin >> M >> N >> K;

        // 배추밭
        vector<vector<int>> field(M, vector<int>(N, 0));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 1) {
                    dfs(field, i, j);
                    worm++;

                }
            }
        }

        cout << worm << '\n';
        worm = 0;
    }

    return 0;
}