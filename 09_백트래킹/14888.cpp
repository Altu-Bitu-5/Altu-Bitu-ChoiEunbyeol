#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> num(11, 0);
vector<int> oper(4, 0); // 0:add 1:sub 2:mul 3:div

int max_num = INT_MIN;
int min_num = INT_MAX;

void updateAnswer(int result) {
    max_num = max(max_num, result);
    min_num = min(min_num, result);
}

void findMinMax(int cnt, int result) { // 조합 문제
    // 종료 조건: 연산자 다 뽑았을 때 (cnt가 n 일 때)
    if(cnt > n - 1){
        updateAnswer(result);
        return;
    }

    for(int i = 0; i < 4; i++){
        if(oper[i] != 0){
            oper[i]--; // 연산자 사용

            switch(i){
                case 0:
                    findMinMax(cnt + 1, result + num[cnt]);
                    break;
                case 1:
                    findMinMax(cnt + 1, result - num[cnt]);
                    break;
                case 2:
                    findMinMax(cnt + 1, result * num[cnt]);
                    break;
                case 3:
                    findMinMax(cnt + 1, result / num[cnt]);
                    break;
            }

            oper[i]++; // 연산자 사용 취소
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    // 입력
    cin >> n;
    num.resize(n);
    for(int i = 0; i < n; i++){ // 숫자
        cin >> num[i];
    }
    
    for(int i = 0; i < 4; i++){ // 연산자
        cin >> oper[i];
    }

    // 연산
    findMinMax(1, num[0]); // 반복 횟수와 연산 시작 수 전달

    // 출력
    cout << max_num << endl;
    cout << min_num;

    return 0;
}