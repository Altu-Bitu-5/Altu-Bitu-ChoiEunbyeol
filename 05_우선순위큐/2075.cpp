#include <iostream>
#include <queue>

using namespace std;

int getN(int n){
    int a;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n*n; i++){ // n*n개 숫자 입력 받으면서 n개만 우선순위 큐에서 유지 -> 가장 위에 값이 구하는 값
        cin >> a;
        pq.push(a);
        if(pq.size() > n){
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, result;
    // 입력
    cin >> n;

    // 연산
    result = getN(n);

    // 출력
    cout << result;
}