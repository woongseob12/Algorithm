#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

int n;
vector<ll> arr[4000];
vector<ll> AB, CD;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			int val;
			cin >> val;
			arr[j].push_back(val);
		}
	}

	// A�� B, C�� D�� ������ �� ���ϱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(arr[0][i] + arr[1][j]);
			CD.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	// lower_bound�� upper_bound�� ���� ���� ������ �ߺ��� ���̸� ����
	ll ans = 0;
	for (int i = 0; i < n * n; i++) {
		ll low = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		ll high = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		// lower_bound�� �ش� ���� ������ lower_bound�� key������ ū ���� ���� ���� ���� ��ȯ
		// ����ó�� �� �ʿ� ����
		ans += high - low;
	}
	cout << ans << '\n';
}
