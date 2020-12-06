#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visit[100001];
void init();
void bfs(int n);

int main()
{
	init();
	cin >> N >> K;
	bfs(N);
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void bfs(int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visit[N] = true;

	while (!q.empty()) {
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (pos == K) {
			cout << cnt << endl;
			break;
		}
		
		visit[pos] = true;

		if ((pos - 1 >= 0 && pos - 1 <= 100000) && !visit[pos - 1]) {
			q.push(make_pair(pos - 1, cnt + 1));
		}
		if ((pos + 1 >= 0 && pos + 1 <= 100000) && !visit[pos +1]) {
			q.push(make_pair(pos +1, cnt + 1));
		}
		if ((pos * 2 >= 0 && pos * 2 <= 100000) && !visit[pos * 2]) {
			q.push(make_pair(pos * 2, cnt + 1));
		}
	}
	return;
}