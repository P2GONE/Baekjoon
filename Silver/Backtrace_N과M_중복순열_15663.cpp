#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;
vector<bool> visited;
set<vector<int>> printed; // 벡터로 직접 중복 체크

void backtrack(int depth) {
    if (depth == M) {
        /*
        printed는 지금까지 출력한 수열들을 저장한 집합
        insert(sequence)는 sequence라는 벡터의 .sencond 즉 성공 여부 확인
        이미 들어간 상태면 .second == false
        처음 들어간 상태면 .second == true
        */
        if (printed.insert(sequence).second) { // 삽입 성공 시에만 출력
            for (int num : sequence)
                cout << num << " ";
            cout << "\n";
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            sequence.push_back(numbers[i]);
            backtrack(depth + 1);
            sequence.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());  // 사전 순 출력을 위한 정렬
    visited.resize(N);
    backtrack(0);
}
