#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e5;

vector<int> dijkstra(int start, int n, vector<vector<pi>> &graph) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pi, vector<pi>, greater<>> pq; // first: 시작점으로부터의 거리, second: 정점
    pq.push({0, start});
    
    while (!pq.empty()) {
        int weight = pq.top().first; // 현재 정점까지의 경로값
        int node = pq.top().second; // 현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) { // 기존 경로가 더 짧을 경우
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; // 연결 정점
            int next_weight = weight + graph[node][i].second; // 시작-현정점-다음 정점 경로값

            if (next_weight < dist[next_node]) { // 최단 경로 값 갱신
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int findMaxDist(int x, int n, vector<vector<pi>> &graph){
    vector<int> dist = dijkstra(x, n, graph); // 파티 장소까지 거리
    int result = 0;

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        vector<int> dist_b = dijkstra(i, n, graph); // 집 돌아오는 거리
        result = max(result, dist[i] + dist_b[x]);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x, a, b, t;
    // 입력
    cin >> n >> m >> x;

    vector<vector<pi>> graph(n + 1, vector<pi>(0));
    while(m--){
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
    }

    // 연산
    int result = findMaxDist(x, n, graph);
    
    // 출력
    cout << result;
}