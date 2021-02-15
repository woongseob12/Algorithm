#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

int N, M;
ll ans;
int arr[100][100];
int cal(int sy, int sx, int ey, int ex);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (j == 0) {
				arr[i][j] = s[j] - '0';
			}
			else {
				int val = s[j] - '0';
				arr[i][j] = arr[i][j - 1] + val;
			}
		}
	}
	// 세로 삼등분
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			ll s1 = cal(0, 0, i, M - 1);
			ll s2 = cal(i + 1, 0, j, M - 1);
			ll s3 = cal(j + 1, 0, N - 1, M - 1);
			ans = max(ans, s1 * s2 * s3);
		}
	}
	// 가로 삼등분
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			ll s1 = cal(0, 0, N - 1, i);
			ll s2 = cal(0, i + 1, N - 1, j);
			ll s3 = cal(0, j + 1, N - 1, M - 1);
			ans = max(ans, s1 * s2 * s3);
		}
	}
	// 2 + 1
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			ll s1 = cal(0, 0, i, j);
			ll s2 = cal(i + 1, 0, N - 1, j);
			ll s3 = cal(0, j + 1, N - 1, M - 1);
			ans = max(ans, s1 * s2 * s3);
		}
	}
	// 1 + 2
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			ll s1 = cal(0, 0, N - 1, j);
			ll s2 = cal(0, j + 1, i, M - 1);
			ll s3 = cal(i + 1, j + 1, N - 1, M - 1);
			ans = max(ans, s1 * s2 * s3);
		}
	}
	// 1 + 2(세로) 맞
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			ll s1 = cal(0, 0, i, M - 1);
			ll s2 = cal(i + 1, 0, N  - 1, j);
			ll s3 = cal(i + 1, j + 1, N - 1, M - 1);
			ans = max(ans, s1 * s2 * s3);
		}
	}
	// 2 + 1(세로)
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			ll s1 = cal(0, 0, i, j);
			ll s2 = cal(0, j + 1, i, M - 1);
			ll s3 = cal(i + 1, 0, N - 1, M - 1);
			ans = max(ans, s1 * s2 * s3);
		}
	}
	cout << ans;
}

int cal(int sy, int sx, int ey, int ex) {
	int sum = 0;
	for (int i = sy; i <= ey; i++) {
		if (sx == 0) {
			sum += arr[i][ex];
		}
		else {
			sum += (arr[i][ex] - arr[i][sx - 1]);
		}
	}
	return sum;
}