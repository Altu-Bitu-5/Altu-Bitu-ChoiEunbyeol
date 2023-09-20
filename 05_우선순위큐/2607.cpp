#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> countAlpabet(string w){ // 문자열 구성 알파벳 수
    vector <int> v(26, 0);
    for(int i = 0; i < w.length(); i++){
        v[w[i]-'A']++;
    }
    return v;
}

bool isSimilar(vector<int> s, vector<int> c, int s_len, int c_len){
    int dif = 0;
    if(s_len == c_len){ // 길이가 같을 때
        for(int i = 0; i < s.size(); i++){ // 알파벳 구성 같거나, 하나를 바꾸면 같아져야함
            if(s[i] != c[i]){
                dif ++;
            }
        }
        if(dif <= 2){
            return true;
        }
        else{
            return false;
        }
        
    }
    else if((s_len - 1) == c_len){ // 기준 단어가 하나 짧을 때
        for(int i = 0; i < s.size(); i++){ // 알파벳 구성 중 하나만 달라야
            if(s[i] != c[i]){
                dif++;
            }
        }
        if(dif == 1){
            return true;
        }
        else {
            return false;
        }
    }
    else if(s_len == (c_len - 1)){ // 비교 단어가 하나 짧을 때
        for(int i = 0; i < s.size(); i++){ // 알파벳 구성 중 하나만 달라야
            if(s[i] != c[i]){
                dif++;
            }
        }
        if(dif == 1){
            return true;
        }
        else {
            return false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0, result = 0;
    string s_word, c_word;
    vector <int> s(26, 0), c(26, 0);
    
    // 입력
    cin >> n;
    cin >> s_word;
    n--;

    // 연산
    s = countAlpabet(s_word);
    int s_len = s_word.length();
    
    while(n--){
        cin >> c_word;
        c = countAlpabet(c_word);
        int c_len = c_word.length();

        if(isSimilar(s, c, s_len, c_len)){
            result++;
        }
    }

    // 출력
    cout << result;
}