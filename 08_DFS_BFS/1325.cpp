#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> con;

int bfs(int n, int v){
    vector<bool> visited (n+1, false);
    queue<int> q;
    int cnt = 1;

    q.push(v);
    visited[v] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(const auto& next_node : con[node]) {
            if(!visited[next_node]) {
                q.push(next_node);
                visited[next_node] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;

    // 입력
    cin >> n >> m;
    con.resize(n+1);
    int n1, n2;
    while(m--){
        cin >> n1 >> n2;
        con[n2].push_back(n1);
    }

    // 연산
    vector<int> result(n+1, 0);
    int maxNum = 0;
    for(int i = 1; i < n + 1; i++){
        result[i] = bfs(n, i);
        maxNum = max(maxNum, result[i]);
    }

    // 출력
    for(int i = 1; i < n + 1; i++){
        if (result[i] == maxNum) {
            cout << i << " ";
        }
    }

    return 0;
}