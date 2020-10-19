#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tClass, B, C;
	long long ans;
	cin >> tClass;
	vector<int> tNum(tClass);
	for (int i = 0; i < tClass; i++) {
		cin >> tNum[i];
	}
	cin >> B >> C;

	ans = tClass;
	for (int i = 0; i < tClass; i++) {
		if (B < tNum[i]) {
			if ((tNum[i] - B) % C == 0) {
				ans += (tNum[i] - B) / C;
			}
			else {
				ans += (tNum[i] - B) / C + 1;
			}
		}
	}
	
	cout << ans << endl;
}