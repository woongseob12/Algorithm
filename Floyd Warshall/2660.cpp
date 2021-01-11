#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int N;
int member[51][51];
int score[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			member[i][j] = INF;
		}
	}

	int a, b;
	cin >> a >> b;
	while (a != -1 || b != -1) {
		member[a ][b] = 1;
		member[b][a] = 1;
		cin >> a >> b;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {

				member[j][k] = min(member[j][k], member[j][i] + member[i][k]);
				
			}
		}
	}

	int minNum = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) { continue; }
			score[i] = max(score[i], member[i][j]);
		}
		minNum = min(minNum, score[i]);
	}

	vector<int> candidate;
	for (int i = 1; i <= N; i++) {
		if (score[i] == minNum) {
			candidate.push_back(i);
		}
	}

	int numOfCandidate = candidate.size();
	cout << minNum << " " << numOfCandidate << '\n';
	for (int i = 0; i < numOfCandidate; i++) {
		cout << candidate[i] << ' ';
	}
}
