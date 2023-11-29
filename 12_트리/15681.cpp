#include <iostream>
#include <vector>

using namespace std;

int n, r, q, u, v;
vector<vector<int>> graph;
vector<int> subTreeNodeNum;

int dfs(int node, int parent) {
    subTreeNodeNum[node] = 1;
	for (int child : graph[node]) { // 연결된 자식 노드 dfs 탐색
		if (child != parent) { // 거꾸로 올라가는 것 방지
			subTreeNodeNum[node] += dfs(child, node); // 자식 노드, 현 노드 로 dfs
		}
	}
    return subTreeNodeNum[node]; // 현 노드의 자손 노드 수 리턴
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // 입력
    
    cin >> n >> r >> q;
    
    graph.resize(n + 1, vector<int>());
    
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
		graph[v].push_back(u);
    }

    vector<int> qurey(q);
    for(int i = 0; i < q; i++){
        cin >> qurey[i];
    }

    // 연산
    subTreeNodeNum.resize(n + 1, 1); // 자기 자신 1 초기화
    dfs(r, -1);

    // 출력
    for(int i = 0; i < q; i++){
        cout << subTreeNodeNum[qurey[i]] << "\n";
    }
}