#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<bool>> map(101, vector<bool>(101, false));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1}; // 0, 1, 2, 3 방향(시계방향)

void makeDragonCurve(int x, int y, int d, int g){
    map[y][x] = true;
    vector<int> dir = {d}; // 처음 방향

    for(int i = 0; i < g; i++){ // 이전 세대로 현 세대 방향 구함
        vector<int> temp = dir;
        reverse(temp.begin(), temp.end()); // 이전 세대 방향 역순

        for (int &nd : temp) { // 각 방향 90도 회전해서 저장
            nd = (nd + 1) % 4;
            dir.push_back(nd);
        }
    }

    for (int nd : dir) { // 방향 따라 드래곤 커브 표시
        x += dx[nd];
        y += dy[nd];
        map[y][x] = true;
    }
}

int cntSquare(){
    int cnt = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
                cnt++; // 네 꼭짓점이 다 true 일 때
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, y, d, g;
    // 입력
    cin >> n;

    // 연산
    while(n--){
        cin >> x >> y >> d >> g;
        makeDragonCurve(x, y, d, g);
    }
    int result = cntSquare();

    // 출력
    cout << result;
}