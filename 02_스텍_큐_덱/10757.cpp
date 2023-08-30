#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 연산
string addBigNumber(string a, string b){
    if(a.length() < b.length()){// a 에 더 큰 수 저장
        swap(a, b);
    }

    int sum = 0, carry = 0;
    string add;

    for(int i = 0; i < a.length(); i++){
        sum = (a[a.length() - i - 1] - '0' + carry); // 작은 자리수부터 더하기
        if(i < b.length()){// b 도 더해줌
            sum += b[b.length() - i - 1] - '0';
        }
        carry = sum / 10;
        add += to_string(sum % 10); // 문자열로 두 수의 합 각 자리수 저장 
    }
    
    if(carry != 0){ // 가장 큰 자리수
        add += to_string(carry);
    }

    reverse(add.begin(), add.end()); // 거꾸로 저장된 것 뒤집기

    return add;
}

int main(){
    string a, b;
    
    // 입력
    cin >> a >> b;

    // 출력
    cout << addBigNumber(a, b);
    return 0;
}