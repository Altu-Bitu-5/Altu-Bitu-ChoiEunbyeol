#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, remove;
    queue <int> q;
    
    // 입력
    cin >> n >> k;

    // 연산, 출력
    
    for(int i = 0; i < n; i++){// n까지 q에 넣음
        q.push((i+1));
    }

    cout << "<";
    while(!q.empty()){
        for(int i = 0; i< k-1; i++){// k번째 전까지 있는 원소들을 뒤로 보냄
            q.push(q.front());
            q.pop();
        }

        cout << q.front(); // k번째 원소 출력 후, pop  
        q.pop();

        if(!q.empty()){// 마지막 원소 pop 이후에는 출력되지 않음
            cout << ", ";
        }
    }

    cout << ">";
     
    return 0;
}