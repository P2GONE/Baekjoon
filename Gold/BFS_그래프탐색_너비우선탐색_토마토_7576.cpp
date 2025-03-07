#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방향 벡터 (상, 하, 좌, 우)
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

// BFS 함수 (최소 날짜 계산)
int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int totalTomatoes) {
    int N = grid.size();   // 세로 크기
    int M = grid[0].size(); // 가로 크기
    int days = -1; // 최소 일수 (첫날은 0일)
    int ripened = 0; // 익은 토마토 개수

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            //auto [x, y] = q.front();
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            ripened++;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // 범위를 벗어나거나, 익은 토마토(1) 또는 빈 칸(-1)이라면 스킵
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || grid[nx][ny] != 0)
                    continue;

                // 익지 않은 토마토(0) → 익히고 큐에 추가
                grid[nx][ny] = 1;
                q.push({ nx, ny });
            }
        }
        days++;
    }

    // 모든 토마토가 익었는지 확인
    return (ripened == totalTomatoes) ? days : -1;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> grid(N, vector<int>(M));

    queue<pair<int, int>> q;
    int totalTomatoes = 0; // 익거나 익지 않은 토마토 총 개수
    bool allRipe = true; // 처음부터 모든 토마토가 익어있는지 확인

    // 입력 받기 및 초기 익은 토마토 위치 큐에 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1) {
                q.push({ i, j }); // 익은 토마토 위치 저장
                totalTomatoes++;
            }
            else if (grid[i][j] == 0) {
                totalTomatoes++;
                allRipe = false; // 익지 않은 토마토가 존재
            }
        }
    }

    // 모든 토마토가 이미 익어있는 경우
    if (allRipe) {
        cout << "0\n";
        return 0;
    }

    // BFS 실행 및 최소 일수 계산
    cout << bfs(grid, q, totalTomatoes) << "\n";

    return 0;
}
