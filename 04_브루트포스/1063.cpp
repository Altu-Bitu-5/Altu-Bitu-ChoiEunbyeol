#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> finalLocation(string k, string s, int n){ // 마지막 위치를 구하는 함수
    string move, new_k, new_s;
    new_k = k; // 이동 건너뛸 경우를 위한 킹 위치 복사
    new_s = s; // 돌 위치 복사

    while(n--){ // n번만큼 실행
        cin >> move;

        // 킹 움직임
        if(move == "R"){ // 오른쪽
            new_k[0] ++;
        }
        else if(move == "L"){ // 왼쪽
            new_k[0] --;
        }
        else if(move == "B"){ // 아래쪽
            new_k[1] --;
        }
        else if(move == "T"){ // 위쪽
            new_k[1] ++;
        }
        else if(move == "RT"){ // 오른쪽 위
            new_k[0] ++;
            new_k[1] ++;
        }
        else if(move == "LT"){ // 왼쪽 위
            new_k[0] --;
            new_k[1] ++;
        }
        else if(move == "RB"){ // 오른쪽 아래
            new_k[0] ++;
            new_k[1] --;
        }
        else if(move == "LB"){ // 왼쪽 아래
            new_k[0] --;
            new_k[1] --;
        }

        if(new_k[0] < 'A' || new_k[0] > 'H' || new_k[1] < '1' || new_k[1] > '8'){ // 킹이 체스판 나갈 경우
            new_k = k; // 움직임 스킵 (적용시킨 움직임 되돌리기)
            continue;
        }

        if(new_k[0] == s[0] && new_k[1] == s[1]){ // 돌 위치로 킹이 이동할 경우
            // 돌이 같은 방향으로 한 칸 이동 (기존 돌 위치 - 기존 킹 위치 차이만큼 이동)
            new_s[0] += s[0] - k[0];
            new_s[1] += s[1] - k[1];
        }

        if(new_s[0] < 'A' || new_s[0] > 'H' || new_s[1] < '1' || new_s[1] > '8'){ // 돌이 체스판 나갈 경우
            new_k = k; // 움직임 스킵 (적용시킨 움직임 되돌리기)
            new_s = s;
            continue;
        }

        // 움직임 반영
        k = new_k;
        s = new_s;
    }

    vector <string> v(2);
    v[0] = k;
    v[1] = s;

    // 리턴
    return v;
}

int main(){
    // 입력
    string king_loc, stone_loc;
    int n;
    cin >> king_loc >> stone_loc >> n;

    // 연산
    vector <string> v = finalLocation(king_loc, stone_loc, n);

    // 출력
    cout << v[0] << "\n";
    cout << v[1];

    return 0;
}
