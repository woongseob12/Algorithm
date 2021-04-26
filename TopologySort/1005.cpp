#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> seq[1001];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> in(N + 1), time(N + 1), res(N + 1);
		//√ ±‚»≠
		for (int i = 1; i <= N; i++) {
			seq[i].clear();
		}

		for (int i = 1; i <= N; i++) {
			cin >> time[i];
		}
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			seq[a].push_back(b);
			in[b]++;
		}
		int end;
		cin >> end;

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (in[i] == 0) {
				res[i] = time[i];
				q.push(i);
			}
		}
		
		for (int i = 1; i <= N; i++) {
			int x = q.front();
			q.pop();
			if (x == end) {
				cout << res[x] << "\n";
				break;
			}
			for (int j = 0; j < seq[x].size(); j++) {
				int next = seq[x][j];
				res[next] = max(res[next], res[x] + time[next]);
				in[next]--;
				if (in[next] == 0) {
					q.push(next);
				}
			}
		}
	}
}