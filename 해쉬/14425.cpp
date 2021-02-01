#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	map<string,int> S;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		S[str]++;
	}
	
	int ans = 0;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (S[str] == 1) {
			ans++;
		}
	}
	cout << ans;
}