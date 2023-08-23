#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 각 자리수 합 계산 함수
int serialSum(string g) {
	int sum = 0;
	for (int i = 0; i < g.length(); i++) {
		if (g[i] >= '0' && g[i] <= '9') {// 숫자일 때
			sum += (int)(g[i]-'0'); // 정수로 변환 후 각 자리수 합산
		}
	}
	return sum;
}

// 비교 함수
bool cmp(string g1, string g2) {
	if (g1.length() != g2.length()) {// 길이가 짧은 순서
		return g1.length() < g2.length();
	}
	if (serialSum(g1) != serialSum(g2)) {// (길이가 같으면) 각 자리수 합이 작은 순서
		return serialSum(g1) < serialSum(g2);
	}
	return g1 < g2; // (길이, 자리수 합이 같으면) 사전 순으로 증가하는 순서

}

int main()
{
	int n;
	vector<string> gitar_serial;
	// 입력
	cin >> n;
	gitar_serial.assign(n, {});
	for (int i = 0; i < n; i++) { // 기타 시리얼 번호
		cin >> gitar_serial[i];
	}
	// 연산
	sort(gitar_serial.begin(), gitar_serial.end(), cmp);
	// 출력
	for (int i = 0; i < gitar_serial.size(); i++) {
		cout << gitar_serial[i] << '\n';
	}
	return 0;
}