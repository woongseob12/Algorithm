#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N;
deque<int> card;
void skill(int n, int idx);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<int> play(N);
	for (int i = 0; i < N; i++) {
		cin >> play[i];
	}

	int idx = 1;
	for (int i = N - 1; i >= 0; i--) {
		skill(play[i], idx);
		idx++;
	}

	while (!card.empty()) {
		cout << card.back() << " ";
		card.pop_back();
	}
}

void skill(int n, int idx) {
	if (n == 1) {
		card.push_back(idx);
	}
	else if (n == 2) {
		int temp = card.back();
		card.pop_back();
		card.push_back(idx);
		card.push_back(temp);
	}
	else {
		card.push_front(idx);
	}
}