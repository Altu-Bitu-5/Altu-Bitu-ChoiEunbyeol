#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n, m, num;
    string str_s, str_test;
    map <string, bool> set_str;

    // 입력
    cin >> n >> m;

    for(int i = 0; i < n; i++){// 집합 S 문자열 입력
        cin >> str_s;
        set_str[str_s] = true;// key: 문자열 value: true
    }

    for(int i = 0; i < m; i++){// 검사할 문자열 입력
        cin >> str_test;
        // 연산
        if(set_str[str_test]){// 검사할 문자열을 key값으로 넣어 value 값 불러옴
            num ++;
        }
    }

    // 출력
    cout << num << endl;
}