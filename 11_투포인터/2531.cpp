#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMaxCnt(int n, int k, int c, vector<int>& belt){
    unordered_map<int, int> type_cnt; // key: 종류, value: 먹은 수
    int max_cnt;
    for(int i = 0; i < k; i++){ // 처음 k크기 슬라이딩 윈도우(0~k-1)
        type_cnt[belt[i]]++;
    }
    max_cnt = type_cnt.size();

    for(int i = k; i < k + n; i++){ // 슬라이딩 윈도우 이동
        int idx = i % n; // 회전 위한 인덱스 설정, 다음 초밥
        int d_idx = (i - k) % n; // 삭제할 앞 초밥

        type_cnt[belt[idx]]++; // 다음 초밥 추가
        
        // 맨 앞 초밥 삭제
        if(type_cnt[belt[d_idx]] == 1){ // 1->0 종류 자체 삭제
            type_cnt.erase(belt[d_idx]);
        }
        else {
            type_cnt[belt[d_idx]]--;
        }

        // 쿠폰 초밥 추가
        if (type_cnt.find(c) == type_cnt.end()) { // 기존 종류에 없을 때 +1
            max_cnt = max(max_cnt, (int)type_cnt.size() + 1); // max_cnt 업데이트
        } else { // 있을 때
            max_cnt = max(max_cnt, (int)type_cnt.size());
        }

    }

    return max_cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 입력
    int n, d, k, c; // 접시 수, 초밥 가짓수, 연속 먹는 접시 수, 쿠폰 번호(종류)
    cin >> n >> d >> k >> c;

    vector<int> belt(n);
    for(int i = 0; i < n; i++){
        cin >> belt[i];
    }

    // 연산
    int result = findMaxCnt(n, k, c, belt);

    // 출력
    cout << result;

    return 0;
}