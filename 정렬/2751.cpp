#pragma warning (disable: 4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> res;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		res.push_back(temp);
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < n; i++) {
		printf("%d\n", res[i]);
	}
}