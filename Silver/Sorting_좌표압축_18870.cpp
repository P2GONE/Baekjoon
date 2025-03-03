#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[1000001]; // 입력값 저장 배열

int main() {
    int total = 0;
    cin >> total;

    vector<int> arr; 
    for (int i = 0; i < total; i++) {
        cin >> a[i];   // 원본 데이터 저장
        arr.push_back(a[i]); // 벡터에도 동일한 값 저장
    }

    // 정렬 및 중복 제거
    sort(arr.begin(), arr.end());
    // Introsort를 씀 => QuickSort, HeapSort, InsertionSort 조합한 하이브리드 정렬
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    // 좌표 압축 수행
    for (int i = 0; i < total; i++) {
        int idx = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin();
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
