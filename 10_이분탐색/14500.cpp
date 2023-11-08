#include <iostream>
#include <vector>
#include <tuple>
#define MAX 500

using namespace std;

typedef vector<vector<int>> v_vec;
v_vec nums(MAX, vector<int>(MAX));
int result = 0, n, m;

vector<vector<tuple<int, int>>> tet = { // 모든 경우의 수..ㅎㅎ
    {make_tuple(0,0),make_tuple(0,1),make_tuple(0,2),make_tuple(0,3)},
    {make_tuple(0,0),make_tuple(1,0),make_tuple(2,0),make_tuple(3,0)},
    {make_tuple(0,0),make_tuple(1,0),make_tuple(0,1),make_tuple(1,1)},
    {make_tuple(0,0),make_tuple(1,0),make_tuple(2,0),make_tuple(2,1)},
    {make_tuple(0,1),make_tuple(1,1),make_tuple(2,1),make_tuple(2,0)},
    {make_tuple(0,0),make_tuple(0,1),make_tuple(1,1),make_tuple(2,1)},
    {make_tuple(0,0),make_tuple(0,1),make_tuple(1,0),make_tuple(2,0)},
    {make_tuple(0,0),make_tuple(1,0),make_tuple(1,1),make_tuple(1,2)},
    {make_tuple(0,2),make_tuple(1,1),make_tuple(1,2),make_tuple(1,0)},
    {make_tuple(0,0),make_tuple(0,1),make_tuple(0,2),make_tuple(1,2)},
    {make_tuple(0,0),make_tuple(1,0),make_tuple(0,1),make_tuple(0,2)},
    {make_tuple(0,0),make_tuple(1,0),make_tuple(1,1),make_tuple(2,1)},
    {make_tuple(0,1),make_tuple(1,1),make_tuple(1,0),make_tuple(2,0)},
    {make_tuple(1,0),make_tuple(1,1),make_tuple(0,1),make_tuple(0,2)},
    {make_tuple(0,0),make_tuple(0,1),make_tuple(1,1),make_tuple(1,2)},
    {make_tuple(0,1),make_tuple(1,0),make_tuple(1,1),make_tuple(1,2)},
    {make_tuple(0,0),make_tuple(0,1),make_tuple(0,2),make_tuple(1,1)},
    {make_tuple(0,0),make_tuple(1,0),make_tuple(1,1),make_tuple(2,0)},
    {make_tuple(0,1),make_tuple(1,1),make_tuple(1,0),make_tuple(2,1)}
};

bool isInBoard(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bruteForce(int i, int j){
    for (const auto& tetromino : tet) { // 모든 테트로미노에 대해
        int sum = 0;
        bool canPlace = true;

        for (const auto& block : tetromino) { // 각 블록 합
            int x = i + get<0>(block);
            int y = j + get<1>(block);

            if (!isInBoard(x, y, n, m)) { // 올바른 범위인지 확인
                canPlace = false;
                break;
            }
            sum += nums[x][y];
        }

        if (canPlace) { // 배치가능하면 최댓값 갱신
            result = max(result, sum);
        }
    }
}

void findMaxSum(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bruteForce(i, j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 입력
    cin >> n >> m;
    nums.resize(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> nums[i][j];
        }
    }

    // 연산
    findMaxSum(n, m);

    // 출력
    cout << result;

    return 0;
}