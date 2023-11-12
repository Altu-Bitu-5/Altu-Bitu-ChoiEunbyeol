#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int m, vector<int>& length){
    int left = 1, right = length[m-1], mid; // 최소, 최대 길이
    int cnt, result = 0; // 해당 길이가 가능한 과자 수, 결과

    while(left <= right){
        mid = (left + right) / 2; // 확인할 과자 길이
        cnt = 0; // 과자 수 초기화

        for(int snack : length){ // 전체 과자를 해당 길이로 나눠서 수 확인
            cnt += snack / mid;
        }

        if(cnt < n){ // 조카 수보다 작을 때
            right = mid - 1; // 범위를 작은 쪽으로 줄임 (더 작은 길이 확인)
        }
        else { // 클 때
            result = mid;
            left = mid + 1; // 더 긴 길이 확인
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 입력
    int n, m; // 조카, 과자 수
    cin >> n >> m;

    vector<int> length(m);
    for(int i = 0; i < m; i++){ // 막대과자 길이 입력
        cin >> length[i];
    }

    sort(length.begin(), length.end()); // 오름차순 정렬

    // 연산
    int result = binarySearch(n, m, length);

    // 출력
    cout << result;

    return 0;
}