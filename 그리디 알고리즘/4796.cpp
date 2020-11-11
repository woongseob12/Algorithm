#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int L, P, V, i = 1;
	while (1) {
		int ans;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		ans = V / P * L;
		ans += min(V % P, L);
		cout << "Case " << i << ": " << ans << endl;
		i++;
	}
}