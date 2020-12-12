#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		multiset<int> dpq;
		multiset<int>::iterator it;
		dpq.clear();
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++) {
			char c;
			cin >> c;
			int val;
			cin >> val;
			if (c == 'I') {
				dpq.insert(val);
			}
			else {
				if (dpq.size() != 0) {
					if (val == -1) {
						it = dpq.begin();
						dpq.erase(it);
					}
					else {
						it = dpq.end();
						it--;
						dpq.erase(it);
					}
				}
			}
		}
		if (dpq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			it = dpq.end();
			it--;
			cout << *it << " ";
			it = dpq.begin();
			cout << *it << '\n';
		}
	}
}