#include <iostream> 
#include <vector>
#define MAX 19

using namespace std;

vector<vector<int>> map(MAX, vector<int>(MAX));
vector<vector<int>> moving = { {0,1}, {1,0}, {1,1}, {-1,1} };
vector<vector<vector<bool>>> visited(MAX, vector<vector<bool>>(MAX, vector<bool>(4, false))); // 바둑판 칸, 방향

bool isInRange(int x, int y){
    return (x >= 0 && x < MAX && y >= 0 && y < MAX);
}

int dfs(int r, int c, int mov, int cnt) { // 재귀 dfs
    visited[r][c][mov] = true;
    int nr = r + moving[mov][0];
    int nc = c + moving[mov][1];
    if (!isInRange(nr, nc) || map[nr][nc] != map[r][c]) {
        if (cnt == 5) {
            return map[r][c]; // 연속 5개 바둑알 색 반환
        }
        else {
            return 0;
        }
    }
    return dfs(nr, nc, mov, cnt + 1);
}

pair<int, pair<int, int>> checkWinner() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(map[j][i] != 0) {
                for(int mov = 0; mov < 4; mov++) {
                    if(visited[j][i][mov]) { // 방문했으면 넘어감
                        continue;
                    }
                    if(dfs(j, i, mov, 1) != 0) { // 비어있지 않은 칸일 때
                        return {map[j][i], {j + 1, i + 1}}; // 색, 위치 반환
                    }
                }
            }
        }
    }
    return {0, {0, 0}};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            cin >> map[i][j];
        }
    }
    
    // 연산
    pair<int, pair<int, int>> result = checkWinner();

    // 출력
    if(result.first != 0) {
        cout << result.first << '\n' << result.second.first << ' ' << result.second.second;
    }
    else {
        cout << 0;
    }

    return 0;
}