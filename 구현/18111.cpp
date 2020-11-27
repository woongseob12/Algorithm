#define MAX_HEIGHT 256
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> m;
set<int> s;
bool cmp(pair<int, int> a, pair<int, int> b);
void init();

int main()
{
	init();
	int N, M, B, time = 0;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int val;
			cin >> val;
			// 최대 높이 제한
			if (val > MAX_HEIGHT) {
				B += (val - MAX_HEIGHT);
				time += 2 * (val - MAX_HEIGHT);
				val = MAX_HEIGHT;
			}
			m[val]++;
			s.insert(val);
		}
	}
	
	vector<pair<int, int>> sol;
	set<int>::iterator iter = s.begin();
	int startH = *iter;
	iter = s.end();
	iter--;
	int endH = *iter + 1;
	while (startH != endH) {
		int block = 0, temp = 0;
		// 가장 낮은 높이부터 순회
		for (auto mIter = m.begin(); mIter != m.end(); mIter++) {
			int currH = (*mIter).first, currN = (*mIter).second;
			if (currH < startH) {	// 쌓는 작업
				block += (startH - currH) * currN;
				temp += (startH - currH) * currN;
			}
			else if (currH > startH) {	// 제거 작업
				block -= (currH - startH) * currN;
				temp += 2 * (currH - startH) * currN;
			}
		}

		if (block <= B) { // 만들 수 있는 경우
			sol.push_back(make_pair(time + temp, startH));
		}
		startH++;
	}
	sort(sol.begin(), sol.end(), cmp);

	cout << sol[0].first << " " << sol[0].second << endl;
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}