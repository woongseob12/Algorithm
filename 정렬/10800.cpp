#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, sum;
typedef struct _Info {
	int idx;
	int color;
	int size;
}Info;

bool cmp(Info a, Info b) {
	return a.size < b.size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> arr(N + 1);
	vector <Info> ball(N);
	for (int i = 0; i < N; i++) {
		ball[i].idx = i;
		cin >> ball[i].color >> ball[i].size;
	}
	sort(ball.begin(), ball.end(), cmp);

	vector<int> color(N + 1);
	int j = 0;
	for (int i = 0; i < N; i++) {
		while (ball[i].size > ball[j].size) {
			sum += ball[j].size;
			color[ball[j].color] += ball[j].size;
			j++;
		}
		arr[ball[i].idx] = sum - color[ball[i].color];
	}
	
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
}
