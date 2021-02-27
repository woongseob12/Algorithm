#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define ll long long

using namespace std;

int D;
ll dp[8][100001];
vector<int> soongsil[8];

int sol(int pos, int loop);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> D;

	memset(dp, -1, sizeof(dp));
	soongsil[0].push_back(1);	soongsil[1].push_back(0);
	soongsil[0].push_back(2);	soongsil[2].push_back(0);
	soongsil[1].push_back(2);	soongsil[2].push_back(1);
	soongsil[1].push_back(3);	soongsil[3].push_back(1);
	soongsil[2].push_back(3);	soongsil[3].push_back(2);
	soongsil[2].push_back(4);	soongsil[4].push_back(2);
	soongsil[3].push_back(4);	soongsil[4].push_back(3);
	soongsil[3].push_back(5);	soongsil[5].push_back(3);
	soongsil[4].push_back(5);	soongsil[5].push_back(4);
	soongsil[4].push_back(6);	soongsil[6].push_back(4);
	soongsil[5].push_back(7);	soongsil[7].push_back(5);
	soongsil[6].push_back(7);	soongsil[7].push_back(6);

	cout << sol(0,0) << "\n";
}

int sol(int pos, int loop) {
	if (loop == D) {
		if (pos == 0) { return 1; }
		return 0;
	}

	ll &ret = dp[pos][loop];
	if (ret != -1) { return ret; }

	ret = 0;
	for (int i = 0; i < soongsil[pos].size(); i++) {
		ret += sol(soongsil[pos][i], loop + 1);
		ret %= MOD;
	}
	return ret;
}