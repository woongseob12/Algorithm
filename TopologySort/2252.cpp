#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

int N, M;
int in[MAX];
int out[MAX];
vector<int> h[MAX];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		h[a].push_back(b);
		in[b]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		int x = q.front();
		q.pop();
		out[i] = x;
		for (int j = 0; j < h[x].size(); j++) {
			int next = h[x][j];
			in[next]--;
			if (in[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << out[i] << " ";
	}
}