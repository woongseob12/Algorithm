#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ans;
char sL, sR;
pair<int, int> posL, posR;
string str;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char keyboard[3][10] = {
	{'q','w','e','r','t','y','u','i','o','p'},
	{'a','s','d','f','g','h','j','k','l',},
	{'z','x','c','v','b','n','m',}
};
bool visit[3][10];
void dfsL(int y, int x, char word);
void dfsR(int y, int x, char word);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> sL >> sR;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (sL == keyboard[i][j]) {
				posL.first = i;
				posL.second = j;
			}
			else if (sR == keyboard[i][j]) {
				posR.first = i;
				posR.second = j;
			}
		}
	}
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++) {
				visit[j][k] = false;
			}
		}

		//cout << "전) 키보드 위치 왼손: (" << posL.first << ',' << posL.second << ") 오른손: (" << posR.first << ',' << posR.second << ")\n";
		int l1 = posL.first, l2 = posL.second, r1 = posR.first, r2 = posR.second;
		if (str[i] == 'a' || (str[i] >= 'c' && str[i] <= 'g') || (str[i] >= 'q' && str[i] <= 't') || str[i] == 'v' || str[i] == 'w' || str[i] == 'x' || str[i] == 'z') {
			dfsL(posL.first, posL.second, str[i]);
			cnt = abs(posL.first - l1) + abs(posL.second - l2);
		}
		else {
			dfsR(posR.first, posR.second, str[i]);
			cnt = abs(posR.first - r1) + abs(posR.second - r2);
		}
		//cout << "후) 키보드 위치 왼손: (" << posL.first << ','<<posL.second<<") 오른손: (" <<posR.first<<',' << posR.second<<")\n";
		ans += cnt;
	}

	ans += len;
	cout << ans << '\n';
}

void dfsL(int y, int x, char word) {
	if (keyboard[y][x] == word) {
		posL.first = y;
		posL.second = x;
		return;
	}
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || ny >= 3 || nx < 0 || nx >= 5) { continue; }
		if (!visit[ny][nx]) {
			visit[ny][nx] = true;
			dfsL(ny, nx, word);
		}
	}
}

void dfsR(int y, int x, char word) {
	if (keyboard[y][x] == word) {
		posR.first = y;
		posR.second = x;
		return;
	}
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || ny >= 3 || nx < 3 || nx >= 10) { continue; }
		if (!visit[ny][nx]) {
			visit[ny][nx] = true;
			dfsR(ny, nx, word);
		}
	}
	return;
}