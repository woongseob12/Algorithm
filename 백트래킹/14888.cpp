#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long num[11];
int op[4];
int n;
const long long maxNum = 1000000000;
const long long minNum = -1000000000;
vector<long long> ans;
void dfs(int cnt, long long res);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(1, num[0]);
	sort(ans.begin(), ans.end());
	cout << ans.back() << endl << ans.front() << endl;
}

void dfs(int cnt, long long res)
{
	if (cnt == n) {
		ans.push_back(res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) { continue; }
		long long temp;
		switch (i)
		{
		case 0:
			temp = res;
			res += num[cnt];
			if (res > maxNum) {
				res = maxNum;
			}
			op[i]--;
			dfs(cnt + 1, res);
			res = temp;
			op[i]++;
			break;
		case 1:
			temp = res;
			res -= num[cnt];
			if (res < minNum) {
				res = minNum;
			}
			op[i]--;
			dfs(cnt + 1, res);
			res = temp;
			op[i]++;
			break;
		case 2:
			temp = res;
			res *= num[cnt];
			if (res > maxNum) {
				res = maxNum;
			}
			op[i]--;
			dfs(cnt + 1, res);
			res = temp;
			op[i]++;
			break;
		case 3:
			if (num[cnt] != 0) {
				temp = res;
				res /= num[cnt];
				if (res < minNum) {
					res = minNum;
				}
				op[i]--;
				dfs(cnt + 1, res);
				res = temp;
				op[i]++;
			}
			else { return; }
			break;
		}
	}
}