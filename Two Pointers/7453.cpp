#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

int n;
vector<ll> arr[4000];
vector<ll> AB, CD;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int val;
			cin >> val;
			arr[j].push_back(val);
		}
	}

	// A와 B, C와 D로 나눠서 합 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(arr[0][i] + arr[1][j]);
			CD.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	// lower_bound와 upper_bound를 통해 더한 값들의 중복의 길이를 구함
	ll ans = 0;
	for (int i = 0; i < n * n; i++) {
		ll low = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		ll high = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		// lower_bound에 해당 값이 없으면 lower_bound는 key값보다 큰 가장 작은 정수 값을 반환
		// 조건처리 할 필요 없음
		ans += high - low;
	}
	cout << ans << '\n';
}
