#include <iostream> // 입출력스트림을 사용할 수 있는 라이브러리 추가
#include <vector> // 벡터를 사용할 수 있는 라이브러리 추가

using namespace std; // std 네임스페이스 내의 모든 기능을 std::를 쓰지 않고 사용할 수 있음

typedef pair<int, int> pii; // int 형 두개 가지는 pair를 pii라는 이름으로 정의

const int MAX_HEIGHT = 257; // MAX_HEIGHT 상수 정의
const int INF = 987'654'321; // 가능한 최댓값이 12,800,000이므로 많이 쓰는 큰 수인 987654321을 사용

// 모든 땅의 높이를 height로 만드는 비용 계산
int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) { // height로 만드는 비용 계산 함수(높이, 행, 열, 가진 블록 수, 각 높이가 저장된 2차원 벡터)
    int cost = 0;       // 총 걸리는 시간
    int added = 0;      // 추가해야 하는 블록의 총 개수
    int removed = 0;    // 제거해야 하는 블록의 총 개수
    
    for (int i = 0; i < n; i++) { // 행
        for (int j = 0; j < m; j++) { // 열
            int gap = abs(height - blocks[i][j]); // 바꿀 높이와 기존 높이 차
            
            if (blocks[i][j] > height) { // 기존 높이가 바꿀 높이보다 높을 때
                // 목표 높이보다 높은 칸인 경우, gap개의 블록 제거
                removed += gap; // 차이만큼 칸 높이 낮춤
            }
            else if (blocks[i][j] < height) { // 기존 높이가 바꿀 높이보다 낮을 때
                // 목표 높이보다 낮은 칸인 경우, gap개의 블록 추가
                added += gap; // 차이만큼 칸 높이 높임
            }
        }
    }
    
    // 전체 비용 계산
    cost = 2 * removed + added; // 제거 2초, 쌓는 거 1초로 총 시간 계산
    
    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost; // 추가할 블록 수가 기존 블록 수와 제거한 블록 수 더한 것보다 크다면 INF 반환, 아니면 cost 반환
}

// 모든 땅의 높이를 같게 만드는 최소 비용과 그 때의 땅의 높이
pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) { // 
    int minCost = INF; // 최소 비용 (기본 값 INF(큰 수))
    int height = 0; // 최소 비용 가질 때 땅 높이
    
    // 모든 높이를 다 만들어보고 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) { // 0~256까지 모든 높이
        int cost = calcCost(i, n, m, b, ground); // 각 높이마다 비용 계산하여 저장
        if (cost <= minCost) { // 해당 높이 비용이 전에 저장한 최소비용보다 작거나 같으면
            minCost = cost; // 최소 비용 업데이트
            height = i; // 해당 높이 저장
        }
    }
    
    return {minCost, height}; // 최소 비용, 높이 pair 로 반환
}

/**
 * 블록 높이의 최댓값이 256밖에 되지 않으므로
 * 모든 칸을 높이 n(0~256)으로 만드는 모든 경우를 시도해보고
 * 그 중에서 비용이 최소가 될 때를 찾는다.
 *
 * 모든 칸을 높이 n으로 만드는
 */

int main() { // main 함수
    int n, m, b; // 행, 열, 블록 수
    
    // 입력
    cin >> n >> m >> b; // 행, 열, 가진 블록 수 입력받음
    vector<vector<int>> ground(n, vector<int>(m)); // 2차원 벡터 ground 선언
    for (int i = 0; i < n; i++) { // 행
        for (int j = 0; j < m; j++) { // 열
            cin >> ground[i][j]; // n행 m열에 각 원소 입력
        }
    }

    // 연산
    pii answer = makeGroundEven(n, m, b, ground); // 땅 높이 같게 만드는 함수에서 받아온 최소 비용과 그 높이를 pii에 저장

    // 출력
    cout << answer.first << " " << answer.second << "\n"; // 최소비용, 그 때 높이

    return 0; // 0 반환, 프로그램 종료
}