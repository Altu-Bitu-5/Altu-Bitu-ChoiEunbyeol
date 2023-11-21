#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMaxLen(int n, int k, vector<int>& seq){
    unordered_map<int, int> cnt;
    int max_len = 0;
    int left = 0; // 길이 시작 인덱스

    for(int right = 0; right < n; right++){ // 오른쪽으로 수열 길이 늘림
        cnt[seq[right]]++;

        while(cnt[seq[right]] > k){ // 중복 한도 넘으면 조건 만족할 때까지 왼쪽 길이 줄임
            cnt[seq[left]]--;
            left++;
        }
        max_len = max(max_len, right - left + 1); // 최대 길이 업데이트
    }
    return max_len;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 입력
    int n, k; // 수열 길이, 중복 가능 최대 개수
    cin >> n >> k;

    vector<int> seq(n);
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }

    // 연산
    int result = findMaxLen(n, k, seq);

    // 출력
    cout << result;
}