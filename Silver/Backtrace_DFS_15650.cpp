#include <iostream>
#include <vector>

using namespace std;

// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열
// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

int N, M;
vector<int> sequence;  // 선택된 숫자를 저장할 벡터
vector<bool> visited;  // 방문 여부 확인

void backtrack(int start) {
    if (sequence.size() == M) {  // M개를 선택하면 출력
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {  // 1부터 N까지 숫자 선택
        if (!visited[i]) {  // 중복 방지
            visited[i] = true;
            sequence.push_back(i);  // 숫자 추가
            backtrack(i + 1);       // 다음 숫자 선택 (start를 i+1로 설정하여 중복 방지)

            sequence.pop_back();    // 백트래킹 (마지막 요소 제거), 이전 상태 복구
            visited[i] = false;     // 방문 체크 해제 
        }
    }
}

int main() {
    cin >> N >> M;

    visited.resize(N + 1, false);  // 방문 여부 체크 배열 초기화
    backtrack(1);  // 백트래킹 시작
    return 0;
}
