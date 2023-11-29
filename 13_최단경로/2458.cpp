#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 7e8;

void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k < n + 1; k++) { // 중간
        for (int i = 1; i < n + 1; i++) { // 출발
            for (int j = 1; j < n + 1; j++) { // 도착
                // i-j-k 비용
                int cost = graph[i][k] + graph[k][j];
                // 더 짧은 경로 선택
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int findMaxKnow(int n, vector<vector<int>> &graph){
    floydWarshall(n, graph);

    int cnt = 0;
    for(int i = 1; i < n + 1; i++){ // 각 학생마다
        bool know = true;
        for(int j = 1; j < n + 1; j++){ // 다른 모든 학생과 비교 가능한지
            if(i != j && graph[i][j] == INF && graph[j][i] == INF){ // 비교 없음
                know = false;
                break; // 다른 학생 탐색
            }
        }
        if (know) cnt++; // 다른 모든 학생과 비교 가능-> 순서 알 수 있음
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    // 임력
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    
    while(m--){
        cin >> a >> b;
        graph[a][b] = 1; // a < b
    }

    // 연산
    int cnt = findMaxKnow(n, graph);

    // 출력
    cout << cnt;
}