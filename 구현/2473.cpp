#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define INF 987654321
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<int> plus, minus;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		if (val > 0) {
			plus.push_back(val);
		}
		else {
			minus.push_back(val);
		}
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end(), greater<>());
	ll ans = 0;
	int a, b, c, sum = INF;
	bool isPlus = false, answer = false;
	if (plus.empty()) {
		for (int i = 2; i >= 0; i--) {
			cout << minus[i] << " ";
		}
	}
	else if (minus.empty()) {
		for (int i = 0; i < 3; i++) {
			cout << plus[i] << " ";
		}
	}
	else {
		for (int i = 0; i < (int)minus.size(); i++) {
			for (int j = i + 1; j < (int)minus.size(); j++) {
				int temp = minus[i] + minus[j];
				for (int k = 0; k < (int)plus.size(); k++) {
					int diff = abs(temp + plus[k]);
					if (diff < sum) {
						sum = diff;
						a = i; b = j; c = k;
						isPlus = true;
					}
					if (sum == 0) {
						answer = true;
						break;
					}
				}
				if (answer) break;
			}
			if (answer) break;
		}

		for (int i = 0; i < (int)plus.size(); i++) {
			for (int j = i + 1; j < (int)plus.size(); j++) {
				int temp = plus[i] + plus[j];
				for (int k = 0; k < (int)minus.size(); k++) {
					int diff = abs(temp + minus[k]);
					if (diff < sum) {
						sum = diff;
						isPlus = false;
						a = i; b = j; c = k;
					}
					if (answer) break;
					if (sum == 0) {
						answer = true;
						break;
					}
				}
				if (answer) break;
			}
			if (answer) break;
		}
		vector<int> sol;
		int valid = 0;
		if (isPlus) {
			sol.push_back(minus[b]);
			sol.push_back(minus[a]);
			sol.push_back(plus[c]);
			for (int i = 0; i < 3; i++) {
				valid += sol[i];
			}
		}
		else {
			sol.push_back(minus[c]);
			sol.push_back(plus[a]);
			sol.push_back(plus[b]);
			for (int i = 0; i < 3; i++) {
				valid += sol[i];
			}
		}
		int onlyP = INF, onlyM = INF;
		if (plus.size() >= 3) {
			onlyP = plus[0] + plus[1] + plus[2];
		}
		if (minus.size() >= 3) {
			onlyM = minus[0] + minus[1] + minus[2];
		}
		int type = 0;
		if (abs(onlyP) < abs(onlyM)) {
			if (abs(onlyP) < abs(valid)) {
				type = 1;
			}
		}
		else {
			if (abs(onlyM) < abs(valid)) {
				type = 2;
			}
		}
		switch (type) {
		case 0:
			for (int i = 0; i < 3; i++) {
				cout << sol[i] << " ";
			}
			break;
		case 1:
			for (int i = 0; i < 3; i++) {
				cout << plus[i] << " ";
			}
			break;
		case 2:
			for (int i = 2; i >= 0; i--) {
				cout << minus[i] << " ";
			}
			break;
		}
	}
}
