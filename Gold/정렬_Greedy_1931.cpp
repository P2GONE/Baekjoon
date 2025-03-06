#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) { // 같을 때도 고려해줘야함
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

void GreedyCalc(vector<vector<int>>& field, int Num) {
    sort(field.begin(), field.end(), compare); // 종료 시간이 짧은 순으로 정렬

    int count = 1;
    int time = field[0][1];

    for (int i = 1; i < Num; i++) { // 두 번째 회의부터 확인
        if (time <= field[i][0]) {
            count++;
            time = field[i][1]; // 종료 시간 업데이트
        }
    }
    cout << count << endl;
}

int main() {
    int Num, a, b;
    cin >> Num; // Num : 전체 인원

    if (Num > 100000 || Num < 1) {
        cout << "Wrong Input!";
        return 1;
    }

    vector<vector<int>> field(Num, vector<int>(2));

    for (int i = 0; i < Num; i++) {
        cin >> a >> b;
        field[i][0] = a;
        field[i][1] = b;
    }

    GreedyCalc(field, Num);

    return 0;
}
