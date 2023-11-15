#include <iostream>
using namespace std;

int N, M, r, c, d;
int room[50][50];
int dr[] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dc[] = {0, 1, 0, -1};
int cnt = 0;

void dfs(int x, int y, int dir) {
    if (room[x][y] == 0) { // 1. 현재 칸 청소 X 시
        room[x][y] = 2; // 현재 위치 청소
        cnt++;
    }

    for (int i = 0; i < 4; i++) { // 주변 4칸 검사
        int nd = (dir + 3 - i) % 4; // 반시계 90도 회전
        int nr = x + dr[nd];
        int nc = y + dc[nd];

        if (room[nr][nc] == 0) { // 3. 보는 방향 기준 앞쪽 칸이 청소 X
            dfs(nr, nc, nd); // 전진, 새 위치에서 다시 탐색
            return;
        }
    }

    // 2. 주변 4칸 다 청소됨
    int bd = (dir + 2) % 4; // 후진 방향
    int br = x + dr[bd];
    int bc = y + dc[bd];
    if (room[br][bc] != 1) { // 뒤가 벽이 아니면 후진, 새 위치에서 다시 탐색
        dfs(br, bc, dir); // 후진
    }
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> room[i][j];
        }
    }
    dfs(r, c, d);

    cout << cnt << endl;
    return 0;
}
