#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int w, h;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 }; // 8 방향 탐색
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

bool isInRange(int x, int y){
    return (x >= 0 && x < h && y >= 0 && y < w);
}

void dfs(int x, int y) { // 재귀 dfs
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) { // 8 방향 탐색
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInRange(nx, ny) && map[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int getIslandNum(){
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int result;
    while (true) {
        // 입력
        cin >> w >> h; // 넓이, 높이
        if (w == 0 && h == 0) {
            break;
        }

        map = vector<vector<int>>(h, vector<int>(w));
        visited = vector<vector<bool>>(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) { // 맵 상태
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        // 연산
        result = getIslandNum();
        
        // 출력
        cout << result << '\n';
    }
    return 0;
}
