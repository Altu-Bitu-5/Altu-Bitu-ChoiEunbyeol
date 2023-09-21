#include <iostream> // 입출력스트림을 사용할 수 있는 라이브러리 추가
#include <vector> // 벡터를 사용할 수 있는 라이브러리 추가

using namespace std; // std 네임스페이스 내의 모든 기능을 std::를 쓰지 않고 사용할 수 있음
const int NUM_CHARS = 26; // NUM_CHARS 상수 선언 및 할당

/*
* 원본 단어와의 차이의 개수를 센다.
*/

/*
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

void countFreq(string word, vector<int> &freq) { // 각 알파벳의 개수 세는 함수
    for (int i = 0; i < word.length(); i++) {// 받아온 문자열의 인덱스 전체를 돌면서
        freq[word[i] - 'A']++; // word[i] - 'A': A~Z를 0~25 인덱스에 연결, freq 벡터에 해당 알파벳 자리의 정수를 하나 증가시킴
    }
}

int countDiff(string word, vector<int> original_freq) { // 원본 단어와 알파벳 구성 차이를 세는 함수
    vector<int> freq(NUM_CHARS, 0); // 크기가 26이고 모든 원소를 0으로 초기화한 정수형 데이터를 저장하는 freq 벡터 선언
    int diff = 0; // 원본 단어와의 차이를 저장하는 diff 선언 및 할당

    countFreq(word, freq); // 비교 단어의 알파벳의 개수를 freq에 반영 (main에서 받아온 비교 단어, 비교단어 알파벳 구성 담을 벡터 전달)
    
    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) { // 벡터 전체를 돌면서(모든 알파벳 갯수 비교)
        diff += abs(original_freq[i] - freq[i]); // A~Z까지 각 알파벳마다 (원본단어 알파벳 수 - 비교단어 알파벳 수) 절댓값을 해서 diff에 저장
    }
    return diff; // 원본 단어와 비교단어의 다른 알파벳 개수를 return
}

int main() {
    int N, ans=0; // 단어의 갯수, 비슷한 단어의 갯수=0 변수 선언 및 할당
    string original; // 원본 단어를 담을 문자열 선언
    // 입력
    cin >> N; // 첫 번째 줄에서 받을 단어의 수를 입력받아 N에 넣음
    cin >> original; // 원본 단어를 입력받아 original에 넣음
    vector<int> original_freq(NUM_CHARS, 0); // 크기가 26이고 모든 원소를 0으로 초기화한 정수형 데이터를 저장하는 original_freq 벡터 선언 (알파벳 구성 담을 벡터)

    // 연산
    countFreq(original, original_freq); // 원본 단어의 알파벳 각 개수를 original_freq에 반영

    for (int i = 1; i < N; i++) { // N-1 만큼 비교할 단어 입력받고, 비슷한지 판단
        string word; // 비교 단어 담을 문자열 word 선언
        cin >> word; // 비교 단어 입력받아 word에 집어 넣음

        int diff = countDiff(word, original_freq); // 비교 단어와 원본 단어의 알파벳 구성 차이 수를 diff에 저장
        // 비슷한 단어 세기
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) { // 위에 작성된 비슷한 단어의 조건 만족시,
            ans++; // 비슷한 단어 개수를 담는 ans 1 증가시킴
        }
    }
    // 출력
    cout << ans; // 비슷한 단어 갯수를 출력함
    return 0; // 0 반환, 프로그램 종료
}