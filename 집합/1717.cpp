#include <iostream>
#include <vector>
using namespace std;

vector<int> root;
void hap(int a, int b);
int find(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		root.push_back(i);
	}

	while (m--) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) {
			hap(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}

void hap(int a, int b)
{
	int root_a = find(a), root_b = find(b);
	if (root_a < root_b) {
		root[root_a] = root_b;
	}
	else {
		root[root_b] = root_a;
	}
}

int find(int n)
{
	if (root[n] == n) {
		return n;
	}
	else {
		return root[n] = find(root[n]);
	}
}