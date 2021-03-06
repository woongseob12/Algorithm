#include <iostream>
#include <string>
#include <vector>
#define MAX 2001
using namespace std;

int N, M;
bool palin[MAX][MAX];
vector<int> str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	str.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> str[i];
	}

	for (int i = 1; i <= N; i++) {
		palin[i][i] = true;
	}

	for (int i = 1; i < N; i++) {
		if (str[i] == str[i + 1]) {
			palin[i][i + 1] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j + i + 1 > N) { continue; }
			if (str[j] == str[j + i + 1] && palin[j + 1][j + i]) {
				palin[j][j + i + 1] = true;
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << palin[s][e] << '\n';
	}
}
