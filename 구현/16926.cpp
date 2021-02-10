#include <iostream>
#include <algorithm>
#define MAX 300
using namespace std;

int N, M, R;
int ary[MAX + 1][MAX + 1];
void changeAry(int idx);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> ary[i][j];
		}
	}

	while (R--) {
		int loop = min(N, M) / 2;
		for (int i = 1; i <= loop; i++) {
			changeAry(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << ary[i][j] << " ";
		}
		cout << '\n';
	}
}

void changeAry(int idx) {
	int y = N - idx + 1;
	int x = M - idx + 1;
	int temp = ary[idx][idx];
	for (int j = idx; j < x; j++) {
		ary[idx][j] = ary[idx][j + 1];
	}
	for (int i = idx; i < y; i++) {
		ary[i][x] = ary[i + 1][x];
	}
	for (int j = x; j > idx; j--) {
		ary[y][j] = ary[y][j - 1];
	}
	for (int i = y; i > idx; i--) {
		ary[i][idx] = ary[i - 1][idx];
	}
	ary[idx + 1][idx] = temp;
}
