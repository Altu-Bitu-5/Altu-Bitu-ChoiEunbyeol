#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a;
    priority_queue <int> pq;

    // 입력
    cin >> n;

    while(n--){
        cin >> a;

        // 연산
        if(a == 0){ // 아이에게 준 선물
            // 출력
            if(pq.empty()){
                cout << "-1\n";
            }
            else {
                cout << pq.top() <<"\n";
                pq.pop();
            }
        }
        else {//거점에서 선물 충전
            int value;
            for(int i = 0; i < a; i++){
                cin >> value;
                pq.push(value);
            }
        }
    }
}