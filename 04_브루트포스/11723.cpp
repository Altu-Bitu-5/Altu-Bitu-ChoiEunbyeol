#include <iostream>
#include <string>

using namespace std;

void operateSet(int m){
    int s = 0, x;
    string set_operator;
    
    while(m--){
        cin >> set_operator;

        if(set_operator == "add"){
            cin >> x;
            s |= (1 << x);
        }
        else if(set_operator == "remove"){
            cin >> x;
            s &= ~(1 << x);
        }
        else if(set_operator == "check"){ // 출력
            cin >> x;
            if(s & (1 << x)){
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if(set_operator == "toggle"){
            cin >> x;
            s ^= (1 << x);
        }
        else if(set_operator == "all"){
            s = 2097150; // 20bit 다 1로 만듦
        }
        else if(set_operator == "empty"){
            s = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    // 입력
    cin >> m;

    // 연산
    operateSet(m);
    
    return 0;
}