#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXNUM = 100000;  // 좌표 범위 설정

void bfs(int start, int end) {
    vector<int> dist(MAXNUM + 1, -1); // 방문 체크 및 거리 저장
    queue<int> q;

    q.push(start);
    dist[start] = 0; // 시작점 거리 = 0

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        // 목표 도착 시 출력 후 종료
        if (x == end) {
            cout << dist[x] << endl;
            return;
        }

        // 3가지 이동 방식 (-1, +1, *2)
        int next_positions[] = { x - 1, x + 1, x * 2 };
        for (int nx : next_positions) {
            if (nx >= 0 && nx <= MAXNUM && dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    bfs(N, M);  // BFS 수행하여 최소 이동 횟수 찾기

    return 0;
}
