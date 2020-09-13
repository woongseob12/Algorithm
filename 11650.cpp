#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b);

int main()
{
	int N;
	scanf("%d", &N);
	vector<vector<int>> res;
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		res.push_back({ x,y });
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", res[i][0], res[i][1]);
	}
}

bool cmp(vector<int> a, vector<int>b)
{
	if (a[0] == b[0]) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}