#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

// DFS 구현
void dfs(int x) {
    visited[x] = true;
    cout << x << ' ';
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) {
            dfs(y);
        }
    }
}

// BFS 구현
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    int vertices, edges, start;
    cin >> vertices >> edges >> start;

    // 간선 입력
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 각 정점의 인접 리스트를 정렬하여 번호가 작은 순서대로 방문하도록 설정
    for (int i = 1; i <= vertices; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS 수행
    fill(visited, visited + 1001, false);
    dfs(start);
    cout << '\n';

    // BFS 수행
    fill(visited, visited + 1001, false);
    bfs(start);
    cout << '\n';

    return 0;
}
