#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isDanger(int w, int bmr){
    bool danger = false;
    if(w <= 0 || bmr <= 0) danger = true;
    return danger;
}

string isYOYO(int eat, int bmr, int amr){
    string yoyo;
    if((eat - (bmr + amr))>0){ // 다이어트 후 bmr 가지고 다이어트 전 eat, amr로 돌아갔을 때
        yoyo = " YOYO";
    } else yoyo = " NO";
    return yoyo;
}

int main(){
    int w, d, t; // 체중, 다이어트 기간, 역치
    int eat_before, eat_during; // 전 일일 에너지 섭취량, 중 일일 에너지 섭취량
    int bmr_before, bmr_during; // 전 일일 기초 대사량, 중 일일 기초 대사량
    int amr_before = 0, amr_during; // 전 일일 활동 대사량(0), 중 일일 활동 대사량

    // 입력
    cin >> w >> eat_before >> t;
    cin >> d >> eat_during >> amr_during;

    bmr_before = eat_before;
    bmr_during = eat_before;
    int w1 = w;
    int w2 = w;

    // 연산
    for(int i = 0; i < d; i++){
        w1 += eat_during - (bmr_before + amr_during); // bmr 변화 고려 X 체중
        int w2_change = eat_during - (bmr_during + amr_during);
        w2 += w2_change; // bmr 변화 고려 O 체중
        
        if(abs(w2_change) > t){
            bmr_during += floor(w2_change/2.0);
        }
    }

    // 출력
    if(isDanger(w1, bmr_before)){ // bmr 변화 고려 X
        cout << "Danger Diet\n";
    }
    else cout << w1 << " " << bmr_before << "\n";

    if(isDanger(w2, bmr_during)){ // bmr 변화 고려 O
        cout << "Danger Diet\n";
    }
    else cout << w2 << " " << bmr_during << isYOYO(eat_before, bmr_during, amr_before) << "\n";
}