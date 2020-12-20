#define MAX 101
#define INF 10000
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int user[MAX][MAX];
void sol();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			user[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		user[a][b] = 1;
		user[b][a] = 1;
	}

	sol();
}

void sol() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				user[i][j] = min(user[i][j], user[i][k] + user[k][j]);
			}
		}
	}

	int sum = INF, idx;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) { continue; }
			temp += user[i][j];
		}
		if (sum > temp) {
			sum = temp;
			idx = i;
		}
	}
	cout << idx<< '\n';
}