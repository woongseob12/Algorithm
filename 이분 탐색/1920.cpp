#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> ary, searchAry;
int findNum(int n, int low, int high);

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		ary.push_back(val);
	}
	sort(ary.begin(), ary.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		int val;
		cin >> val;
		searchAry.push_back(val);
	}

	for (int i = 0; i < M; i++) {
		cout << findNum(searchAry[i], 0, ary.size() - 1) << '\n';
	}

}

int findNum(int n, int low, int high) {
	int mid = (low + high) / 2;
	while (low <= high) {
		mid = (low + high) / 2;
		if (ary[mid] == n) {
			return 1;
		}
		else if (ary[mid] < n) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return 0;
}