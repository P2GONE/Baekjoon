#include <iostream>
#include <vector>
#include <queue>
#define MAX_NODES 101

using namespace std;

// 노선의 수 n, 간선의 수 m
int n = 0, m = 0, count_num = 0;

vector<int> graph[MAX_NODES];	// 인접 리스트
bool visited[MAX_NODES];		// 방문한 곳 

// DFS로 찾기 
void DFS(int x) {
	visited[x] = true;
	//cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			count_num ++;
			DFS(y);
		}
	}
}

int main() {
	int total, check;

	// 전체 입력
	cin >> total >> check;

	// 간선 입력
	for (int i = 0; i < check; i++) {
		int q = 0, p = 0;
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	DFS(1);
	cout << count_num << endl;

	return 0;

}