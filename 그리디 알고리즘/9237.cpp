#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int  numOfSeedling, ans;
vector<int> seedling;
void input();
void solve();
void calMaxDay();
void output();

int main() {
	input();
	solve();
	output();
}

void input() {
	cin >> numOfSeedling;
	seedling.resize(numOfSeedling);
	for (int i = 0; i < numOfSeedling; i++) {
		cin >> seedling[i];
	}
}

void solve() {
	sort(seedling.begin(), seedling.end(), greater<>());
	calMaxDay();
}

void calMaxDay() {
	for (int i = 0; i < numOfSeedling; i++) {
		ans = max(ans, (i + 2) + seedling[i]);
	}
}

void output() {
	cout << ans;
}