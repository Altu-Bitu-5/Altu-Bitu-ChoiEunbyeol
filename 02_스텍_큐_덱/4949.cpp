#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 연산
bool isBalanced(const string& input){
    stack <char> s;

    for (char c : input) {
        if (c == '(' || c == '[') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        } else if (c == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }

    return s.empty(); //입력 처리 후 스택이 비어있어야 균형

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;

    //입력
    while(getline(cin, input) && input != "."){
        
        // 출력
        if(isBalanced(input)){
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}