#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){  
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> reducedFraction(int a1, int a2, int b1, int b2){
    vector <int> v(2);
    int l_denomi = (a2 * b2) / gcd(a2, b2); // 분모의 최소공배수
    int numer = (l_denomi / a2 * a1) + (l_denomi / b2 * b1); // 통분한 분자
    int common_factor = gcd(numer, l_denomi);

    v[0] = numer / common_factor;
    v[1] = l_denomi / common_factor;

    return v;
}

int main(){
    int a_numer, a_denomi, b_numer, b_denomi;
    vector <int> v(2);
    
    // 입력
    cin >> a_numer >> a_denomi;
    cin >> b_numer >> b_denomi;

    // 연산
    v = reducedFraction(a_numer, a_denomi, b_numer, b_denomi);

    // 출력
    cout << v[0] << " " << v[1] << endl;

    return 0;
}