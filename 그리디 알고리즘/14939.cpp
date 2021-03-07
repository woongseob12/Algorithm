#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define SIZE 10
#define INF 987654321
using namespace std;

bool arr[SIZE][SIZE];
bool test[SIZE][SIZE];
int dy[] = { 1, 0 , -1, 0 };
int dx[] = { 0, 1, 0 , -1 };
void power(int y, int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < SIZE; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < SIZE; j++) {
			arr[i][j] = s[j]=='O'? true:false;
		}
	}

	int ans = INF;
	// ù���� �������� �� �ִ� ����� ��
	for (int i = 0; i < (1 << SIZE); i++){
		memcpy(test, arr, sizeof(arr));
		int cnt = 0;

		// ù��(���ʿ��� ����������)
		for (int j = 0; j < SIZE; j++) {
			if (i & (1 << j)) {
				power(0, j);
				cnt++;
			}
		}
		// ������ ������ ���
		for (int j = 1; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				if (test[j - 1][k]) {
					power(j, k);
					cnt++;
				}
			}
		}

		// ��ȿ�� �Ҳ������� Ȯ��
		bool valid = false;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (test[i][j]) {
					valid = true;
					break;
				}
			}
		}
		if (!valid) {
			ans = min(ans, cnt);
		}
	}

	// ���� ���������� ���� �ִ��� Ȯ��
	if (ans == INF) {
		ans = -1;
	}
	cout << ans << "\n";
}

void power(int y, int x) {
	test[y][x] = !test[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= SIZE || nx >= SIZE) continue;
		test[ny][nx] = !test[ny][nx];
	}
}

