#include <iostream>
#include <algorithm>
using namespace std;

int N;
int L[21], J[21], dp[101];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> J[i];
	}
	for (int idx = 0; idx < N; idx++) {
		for (int hp = 100; hp >= 0; hp--) {
			if (hp - L[idx] <= 0) { continue; }
			dp[hp] = max(dp[hp], dp[hp - L[idx]] + J[idx]);
		}
	}
	
	cout << dp[100];
}
