#include <iostream>
#include <vector>

using namespace std;

long long getMinV(vector <long long> v){ // 지구 속도 최솟값 구하는 함수
    long long result = v.back();
    long long mul;
    for(int i = v.size()-2; i >= 0; i--){ // 거꾸로 n개 속도 2개씩 비교 -> n-1번 비교
        if(v[i] >= result){
            result = v[i];
        }
        
        else {
        // 그 전 비교로 구한 최소 속도보다 크거나 같은 v[i]의 배수 구해야
        if(result % v[i] == 0){
            mul = result / v[i];
            result = v[i] * mul;
            continue;
        }
        
        mul = result / v[i] + 1;
        result = v[i] * mul;
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, temp;
    vector <long long> v;

    // 입력
    cin >> n;
    while(n--){
        cin >> temp;
        v.push_back(temp);
    }

    // 연산
    long long min_v = getMinV(v);

    // 출력
    cout << min_v;
    
    return 0;
}