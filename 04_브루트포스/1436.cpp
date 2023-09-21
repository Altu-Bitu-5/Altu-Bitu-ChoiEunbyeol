#include <iostream>
#include <string>

using namespace std;

int titleNum(int n){
    int count = 0;
    int title = 665;
    while(1){ // n번째 666 들어간 숫자 찾을 때까지 반복
        title ++;
        if(to_string(title).find("666") != string::npos){
            count ++;
        }
        if(count == n){
            return title;
        }
    }
}

int main(){
    int n;
    int title;
    
    // 입력
    cin >> n;

    // 연산
    title = titleNum(n);

    // 출력
    cout << title;
}