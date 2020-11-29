#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	int N, M;
	cin >> N >> M;
	string s;
	map<string, int> m;
	vector<string> dic(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> s;
		m[s] = i;
		dic[i] = s;
	}

	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s[0] >= 'A' && s[0] <= 'Z') {
			cout << m.find(s)->second << '\n';
		}
		else {
			int temp = stoi(s);
			cout << dic[temp] << '\n';
		}
	}
}