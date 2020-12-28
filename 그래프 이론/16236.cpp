#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[20][20];
bool visit[20][20];
pair<int, int> sharkPos;
int sharkSize = 2, needToEat, res;
typedef struct fish {
	int dist;
	int x;
	int y;
}fish;

struct cmp {
	bool operator()(fish a, fish b) {
		if (a.dist == b.dist) {
			if (a.y == b.y) {
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.dist > b.dist;
	}
};
priority_queue<fish, vector<fish>, cmp> pq;
void bfs(int y, int x);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sharkPos.first = i, sharkPos.second = j;
				map[i][j] = 0;
			}
		}
	}

	while (1) {
		bfs(sharkPos.first, sharkPos.second);
		if (pq.empty()) {
			cout << res << '\n';
			break;
		}
		sharkPos.first = pq.top().y;
		sharkPos.second = pq.top().x;
		res += pq.top().dist;
		//cout << "상어 위치 : (" << sharkPos.first << ',' << sharkPos.second << ")\n";
		
		while (!pq.empty()) {
			pq.pop();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		map[sharkPos.first][sharkPos.second] = 0;
		needToEat++;
		if (needToEat == sharkSize) {
			sharkSize++;
			needToEat = 0;
		}
	}
}

void bfs(int y, int x) {
	queue<pair<pair<int, int>, int>> q;
	q.push({{ y, x }, 0});
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (map[y][x] != 0 && map[y][x] < sharkSize) {
			fish temp;
			temp.dist = cnt;
			temp.x = x;
			temp.y = y;
			pq.push(temp);
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (map[ny][nx] <= sharkSize && !visit[ny][nx]) {
				visit[ny][nx] = true;
				q.push({ { ny,nx },cnt + 1 });
			}
		}
	}
}

