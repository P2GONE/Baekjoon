#include <iostream>
#include <vector>

using namespace std;

#define MAXNUM 1000

vector<bool> visited(MAXNUM, false);    // 방문 배열
vector<vector<int>> graph;              // 전역 그래프
int count_num = 0;                      // 연결된 노드 개수 카운트

// DFS 탐색
void DFS(int x) {
    visited[x] = true;
    count_num++;                        // 방문 시작시 count_num 올림

    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) {              // 방문하지 않은 노드 방문
            DFS(y);
        }
    }
}

int main() {
    int N, M;             // 정점의 개수 N과 간선의 개수 M
    cin >> N >> M;        

    graph.resize(N + 1);  // 벡터 크기 설정 

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;          // 간선의 양 끝점 u와 v
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    int components = 0;         // 연결 요소 개수

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            count_num = 0;  // 새로운 연결 요소 시작
            DFS(i);
            components++;
        }
    }

    cout << components << endl;

    return 0;
}
