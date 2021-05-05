#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;

bool check(int n, int k) {
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < n) {
			cnt++;
			if (cnt >= k) {
				return false;
			}
		}
		else {
			cnt = 0;
		}
	}
	return true;
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	arr = stones;
	int l = 987654321, r = 0;
	for (int i = 0; i < arr.size(); i++) {
		l = min(l, arr[i]);
		r = max(r, arr[i]);
	}
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid, k)) {
			l = mid + 1;
			answer = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return answer;
}