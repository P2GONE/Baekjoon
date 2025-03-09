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
        int x = q.front();      // 현재 위치 저장
        q.pop();                // 큐에서 제거

        // 목표 도착 시 출력 후 종료
        if (x == end) {
            cout << dist[x] << endl;
            return;
        }

        // 3가지 이동 방식 (-1, +1, *2)
        // 큐를 사용하면서 이동 가능한 위치를 탐색
        // 각 움직이는 큐와 해당 큐와 이동 횟수를 함께 저장, 겹친다면 하지 않음
        int next_positions[] = { x - 1, x + 1, x * 2 };
        for (int nx : next_positions) {                             // 이동 가능한 위치 탐색
            if (nx >= 0 && nx <= MAXNUM && dist[nx] == -1) {        // 방문하지 않았다면
                dist[nx] = dist[x] + 1;                             // 이동 횟수 저장
                q.push(nx);                                         // 다음 탐색할 위치 큐에 추가 
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
