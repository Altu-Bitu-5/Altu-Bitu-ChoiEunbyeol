#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int key, vector<int>& nums){
    int left = 0, right = n - 1, mid; // 인덱스 설정

    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] == key){ // 탐색 성공
            return 1;
        }
        else if(nums[mid] < key){ // key보다 작을 때
            left = mid + 1;
        }
        else { // key보다 클 때
            right = mid - 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 입력
    int n, m, key;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){ // 가지고 있는 숫자 카드
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end()); // 배열 오름차순 정렬

    cin >> m;
    while(m--){
        cin >> key;
        // 연산, 출력
        cout << binarySearch(n, key, nums) << " ";
    }
    
    return 0;
}