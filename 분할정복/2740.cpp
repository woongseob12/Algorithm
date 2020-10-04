#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> NM;
vector<vector<int>> MK;
void input();
void sol(int index);

int main()
{
	input();
	sol(0);
}

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int val;
			cin >> val;
			temp.push_back(val);
		}
		NM.push_back(temp);
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		vector<int> temp;
		for (int j = 0; j < k; j++) {
			int val;
			cin >> val;
			temp.push_back(val);
		}
		MK.push_back(temp);
	}
}

void sol(int index)
{
	if (index == n) {
		return;
	}
	for (int i = 0; i < k; i++) {
		int val = 0;
		for (int j = 0; j < m; j++) {
			val += NM[index][j] * MK[j][i];
		} 
		cout << val << " ";
	}
	cout << endl;
	sol(index + 1);
}