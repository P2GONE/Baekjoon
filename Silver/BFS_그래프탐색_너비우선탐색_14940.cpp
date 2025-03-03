#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방향 벡터 (상, 하, 좌, 우)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS(vector<vector<int>>& grid, vector<vector<int>>& dist, int startX, int startY) {
    int n = grid.size();    // 행 크기
    int m = grid[0].size(); // 열 크기

    queue<pair<int, int>> q;
    q.push({ startX, startY });
    dist[startX][startY] = 0; // 시작 지점 거리 0 설정

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크 & 갈 수 있는 땅인지 확인 & 방문하지 않았는지 확인
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && dist[nx][ny] == -1) {
                q.push({ nx, ny });
                dist[nx][ny] = dist[x][y] + 1; // 거리 업데이트
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));         // 입력 맵
    vector<vector<int>> dist(n, vector<int>(m, -1));     // 거리 배열

    int startX = -1, startY = -1;                       // 시작점 

    // 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 2) { // 목표 지점 찾기
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 0) { // 갈 수 없는 곳은 거리도 0으로 설정
                dist[i][j] = 0;
            }
        }
    }

    // BFS 실행
    BFS(grid, dist, startX, startY);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
