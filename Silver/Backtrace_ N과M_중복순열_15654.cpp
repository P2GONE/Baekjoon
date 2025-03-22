#include <iostream>
#include <vector>
#include <algorithm>  // sort 함수 사용

using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;	// 저장된 배열
vector<bool> visited;
/*
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/

void backtrace(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}
	

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			sequence.push_back(numbers[i]);
			backtrace(depth + 1);

			sequence.pop_back();    // 백트래킹 (마지막 요소 제거), 이전 상태 복구
			visited[i] = false;     // 방문 체크 해제 
		}
	}

}

int main() {
	cin >> N;
	cin >> M;

	visited.resize(N, false);
	numbers.resize(N);

	for (int i = 0; i < N ; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());
	backtrace(0);
}