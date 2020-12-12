#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#define MAX 500001
using namespace std;

bool broken[10];
bool valid[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int channel, trouble;
	cin >> channel >> trouble;
	
	for (int i = 0; i < trouble; i++) {
		int num;
		cin >> num;
		broken[num] = true;
	}
	// +, - 만 이용
	int ans = abs(channel - 100);
	// 작은 것, +, - 이용
	int small = channel;
	while (small >= 0) {
		bool found = true;
		string temp = to_string(small);
		for (int i = 0; i < (int)temp.size(); i++) {
			if (broken[temp[i] - '0']) { 
				found = false;
				break;
			}
		}
		if (found) {
			break;
		}
		else {
			small--;
		}
	}
	if (small != -1) {
		ans = min(ans, (int)to_string(small).size() + channel - small);
	}
	// 큰 것
	int big = channel;
	while (big <= 1000000) {
		bool found = true;
		string temp = to_string(big);
		for (int i = 0; i < (int)temp.size(); i++) {
			if (broken[temp[i] - '0']) {
				found = false;
				break;
			}
		}
		if (found) {
			break;
		}
		else {
			big++;
		}
	}
	ans = min(ans, (int)to_string(big).size() + big - channel);
	cout << ans << endl;
}