#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
vector<int> num, sequence;
string result;

void findSequence(int cnt){
    // 종료 조건: 숫자 다 뽑았을 때 (m 개)
    if(cnt == m){ // 수열 문자열로 쭉 저장 (2차원 정수 벡터로 저장하니 시간초과)
        for (const auto &seq : sequence) {
            result += to_string(seq) + ' ';
        }
        result.back() = '\n';
        return;
    }

    int prev = 0; // 직전에 뽑은 수 저장 변수
    for(int i = 0; i < n; i++){
        if(num[i] !=  prev){ // 중복 방지
            sequence[cnt] = num[i];
            findSequence(cnt + 1);
            prev = num[i]; // 직전에 뽑았던 수 저장
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    // 입력
    cin >> n >> m;
    num.resize(n);
    sequence.resize(m);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    // 연산
    sort(num.begin(), num.end()); // 사용 가능한 수 정렬 (사전 순 탐색 위해)
    findSequence(0);

    // 출력
    cout << result;

    return 0;
}