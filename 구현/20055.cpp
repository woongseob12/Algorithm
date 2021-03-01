#include <iostream>
#include <vector>
using namespace std;

int N, K, cnt, sIdx, ans;
vector<int> A;
vector<bool> robot;
void func1();
void func2();
void func3();
void func4();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	A.resize(2 * N + 1);
	robot.resize(N + 1);
	for (int i = 1; i <= 2 * N; i++) {
		cin >> A[i];
	}

	while (cnt < K) {
		ans++;
		func1();
		func2();
		func3();
		func4();
	}
	cout << ans << endl;
}

void func1() {
	A[0] = A[2 * N];
	for (int i = 2 * N; i >= 1; i--) {
		A[i] = A[i - 1];
	}

	for (int i = N; i >= 1; i--) {
		robot[i] = robot[i - 1];
	}
	if (robot[N]) robot[N] = false;
}

void func2() {
	for (int i = N - 1; i >= 1; i--) {
		if (robot[i]) {
			if (!robot[i + 1] && A[i + 1] > 0) {
				if (i + 1 != N) { robot[i + 1] = true; }
				A[i + 1]--;
				robot[i] = false;
			}
		}
	}
}

void func3() {
	if (!robot[1] && A[1] > 0) {
		robot[1] = true;
		A[1]--;
	}
}

void func4() {
	cnt = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (A[i] == 0) { cnt++; }
	}
}