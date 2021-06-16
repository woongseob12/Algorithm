#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct _Info {
	int x;
	int h;
	bool end;
}Info;

bool cmp(const Info& a, const Info& b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else {
		if (a.end != b.end) {	// 하나는 시작점, 하나는 끝점
			if (a.end) {	// a가 끝점
				return false;
			}
			else {
				return true;
			}
		}
		else {
			if (!a.end) {	// 둘다 시작점이라면
				return a.h > b.h;
			}
			else {
				return a.h < b.h;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Info> arr;
	for (int i = 0; i < n; i++) {
		int l, h, r;
		cin >> l >> h >> r;
		arr.push_back({ l, h, false });
		arr.push_back({ r, h, true });
	}

	sort(arr.begin(), arr.end(), cmp);

	map<int, int, greater<>> test;
	test.insert({ 0,0 });
	for (int i = 0; i < arr.size(); i++) {
		int max = test.begin()->first;
		if (!arr[i].end) {	
			test[arr[i].h]++;
		}
		else {
			test[arr[i].h]--;
			if (test[arr[i].h] == 0) {
				test.erase(arr[i].h);
			}
		}
		if (max != test.begin()->first) {
			cout << arr[i].x << " " << test.begin()->first << " ";
		}
	}
}