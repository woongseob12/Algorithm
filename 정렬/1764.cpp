#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	map<string, int> dic;
	vector<string> ans;
	int N, M;
	string s;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> s;
		dic[s]++;
	}
	for (auto it = dic.begin(); it != dic.end(); it++) {
		if (it->second == 2) {
			ans.push_back(it->first);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}