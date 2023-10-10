#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string findPalindrome(string name){ // 알파벳 구성 파악 -> 한 요소만 홀수 가능!
    int nameArr[26] = {0};
    string result = "";
    for(int i = 0; i < name.length(); i++){ // 알파벳 구성 배열에 저장
        nameArr[name[i]-'A']++;
    }

    int odd = 0, odd_index;
    char char_odd;
    for(int i = 0; i < 26; i++){ // 홀수인 알파벳 갯수 카운팅, 저장
        if(nameArr[i] % 2 == 1){
            odd++;
            odd_index = i;
            char_odd = i + 'A';
        }
    }

    // 만들 수 없는 경우 (홀수인 알파벳이 2개 이상 -> 불가능)
    if((odd > 1)){
        result = "I'm Sorry Hansoo";
        return result;
    }

    // 팰린드롬 문자열 만들기, 사전순으로 가장 앞 구하므로 A부터 앞쪽에 배치
    int j = 0;
    if(odd == 0){ // 길이 짝수 -> 앞 절반 + 리버스 절반
        for(int i = 0; i < 26; i++){
            while(nameArr[i] != 0){
                result += (char)(i + 'A');
                nameArr[i] -= 2;
                j++;
            }
        }
        string resultA = result;
        reverse(result.begin(), result.end());
        return resultA + result;
    }
    else if(odd == 1){ // 길이 홀수 -> 앞 절반 + 홀수 알파벳 + 리버스 절반
        nameArr[odd_index]--; // 가운데 넣을 알파벳 뺌
        for(int i = 0; i < 26; i++){
            while(nameArr[i] != 0){
                result += (char)(i + 'A');
                nameArr[i] -= 2;
                j++;
            }
        }
        string resultA = result;
        reverse(result.begin(), result.end());
        return resultA + char_odd + result;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string name;
    // 입력
    cin >> name;

    // 연산
    string palind = findPalindrome(name);

    // 출력
    cout << palind;

    return 0;
}