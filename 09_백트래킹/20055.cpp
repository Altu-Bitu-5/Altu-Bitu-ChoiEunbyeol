#include <iostream>
#include <deque>

using namespace std;

int findStep(int n, int k, deque<int> convey, deque<bool> robot){
    int step = 0, empty;

    while(true){
        step++;

        // 1. 벨트 한 칸 회전
        convey.push_front(convey.back()); // 벨트 내구도 회전
        convey.pop_back();
        
        robot.pop_back(); // 로봇 회전
        robot.push_front(false);
        robot[n-1] = false; // 로봇 내림

        // 2. 로봇 한 칸 이동 (먼저 올라간 로봇부터)
        for(int i = n - 2; i >= 0; i--){
            if(robot[i] && !robot[i + 1] && convey[i + 1] > 0){ // 로봇 있는 위치, 그 다음 위치는 로봇 없음,내구도 1 이상 일 때
                robot[i] = false;
                robot[i + 1] = true;
                convey[i + 1]--;
            }
            if(i + 1 == n - 1){ // 로봇 내림 위치
                robot[i + 1] = false; // 로봇 내림
            }
        }

        // 3. 로봇 올림
        if(!robot[0] && convey[0] > 0){ // 로봇 없고, 내구도 1이상 일 때
            robot[0] = true;
            convey[0]--;
        }

        // 4. 내구도 0 칸 수 확인
        empty = 0;
        for(int i = 0; i < 2 * n; i++){
            if(convey[i] == 0){
                empty++;
            }
        }

        if(empty >= k){ // 종료 (내구도 0 칸 수가 k개 이상)
            return step;
        }
    }
}

int main(){
    int n, k; // 컨베이어 벨트 한 줄 크기, 내구도 0 칸 갯수 한계
    
    // 입력
    cin >> n >> k;

    deque<int> convey; // 내구도
    deque<bool> robot; // 로봇 위치

    int durability;
    for(int i = 0; i < 2 * n; i++){
        cin >> durability;
        convey.push_back(durability);
    }
    robot.resize(n, false);

    // 연산
    int result = findStep(n, k, convey, robot);

    // 출력
    cout << result;

    return 0;
}