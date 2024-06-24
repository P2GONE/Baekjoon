#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

// DFS ����
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

// BFS ����
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

    // ���� �Է�
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // �� ������ ���� ����Ʈ�� �����Ͽ� ��ȣ�� ���� ������� �湮�ϵ��� ����
    for (int i = 1; i <= vertices; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS ����
    fill(visited, visited + 1001, false);
    dfs(start);
    cout << '\n';

    // BFS ����
    fill(visited, visited + 1001, false);
    bfs(start);
    cout << '\n';

    return 0;
}
