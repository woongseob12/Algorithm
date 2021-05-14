#include <iostream>
#include <queue>
using namespace std;

typedef struct Info {
	int screen;
	int clipboard;
	int cnt;
}Info;

bool visit[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int s;
	cin >> s;
	queue<Info> q;
	q.push({1, 0, 0});
	while (!q.empty()) {
		Info curr = q.front();
		q.pop();
		//cout << curr.screen << " " << curr.clipboard << " " << curr.cnt<<'\n';
		if (curr.screen == s) {
			cout << curr.cnt;
			break;
		}
		// 1. 화면 이모티콘 모두 클립으로 복사
		if (!visit[curr.screen][curr.screen]) {
			visit[curr.screen][curr.screen] = true;
			q.push({ curr.screen, curr.screen, curr.cnt + 1 });
		}
		// 2. 클립보드에 있는 모든 이모티콘 화면에 붙여넣기
		if (curr.screen + curr.clipboard <= s && !visit[curr.screen + curr.clipboard][curr.clipboard]) {
			visit[curr.screen + curr.clipboard][curr.clipboard] = true;
			q.push({ curr.screen + curr.clipboard, curr.clipboard, curr.cnt + 1 });
		}		
		// 3. 화면 이모티콘 하나 삭제
		if (curr.screen - 1 >= 0 && !visit[curr.screen - 1][curr.clipboard]) {
			visit[curr.screen - 1][curr.clipboard] = true;
			q.push({ curr.screen - 1, curr.clipboard, curr.cnt + 1 });
		}
	}
}