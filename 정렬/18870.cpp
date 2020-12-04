#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void init();

int main()
{
	init();
	int N;
	cin >> N;
	vector<int> ary(N);
	vector<int> s(N);
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
		s[i] = ary[i];
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	for (int i = 0; i < N; i++) {
		cout << lower_bound(s.begin(), s.end(), ary[i]) - s.begin() << " ";
	}
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}