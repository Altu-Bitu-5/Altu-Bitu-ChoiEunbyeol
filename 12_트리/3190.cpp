#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <string.h>

using namespace std;

vector<vector <int>> board;
map <int, char> dir;
deque<pair<int, int>> snake;
set<pair<int, int>> body;

int time = 0;
int dr[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상 (시계 방향)
int dc[4] = {1, 0, -1, 0};

int getDirIdx(int cidx, char turn){
    if(turn == 'D'){ // 오른쪽 회전
        return (cidx + 1) % 4;
    }
    else {// 왼쪽 회전
        return (cidx + 3) % 4;
    }
}

bool isCollision(int r, int c, int n){ // 벽, 자기 자신에게 부딫히는가?
    if (r < 0 || c < 0 || r >= n || c >= n) return true;
    if (body.find({r, c}) != body.end()) return true;
    return false;
}

void getTime(int n) {
    snake.push_back({0, 0}); // 처음 뱀 위치
    int nr, nc, idx = 0;

    while(true){
        time++;

        nr = snake.front().first + dr[idx]; // 이동 위치
        nc = snake.front().second + dc[idx];

        if (isCollision(nr, nc, n)){ // 충돌 시 종료
            return;
        }
        
        if(dir.find(time) != dir.end()){ // 방향 변경 필요 시
            idx = getDirIdx(idx, dir[time]);
        }
        

        snake.push_front({nr, nc}); // 머리 다음칸에 위치, 길이 한칸 늘림
        body.insert({nr, nc}); // 몸통 위치 추가

        if(board[nr][nc] == 1){ // 사과 있으면
            board[nr][nc] = 0; // 냠
        }
        else { // 없으면
             body.erase(snake.back()); // 꼬리 위치에서 몸통 위치 제거
            snake.pop_back(); // 늘린 길이 줄여서 길이 유지
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, l, x;
    char c;

    // 입력
    cin >> n >> k;
    board.resize(n, vector<int>(n));

    int rl, cl;
    for(int i = 0; i < k; i++){ // 사과 위치 입력
        cin >> rl >> cl;
        board[rl - 1][cl - 1] = 1;
    }

    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> x >> c;
        dir[x] = c;
    }

    // 연산
    getTime(n);

    // 출력
    cout << time;
}