#include <iostream>
#include <string>
#include <map>
using namespace std;

void init();

int main()
{
	init();
	int N, M;
	cin >> N >> M;

	map<string, string> m;
	string site, pw;
	for (int i = 0; i < N; i++) {
		cin >> site >> pw;
		m[site] = pw;
	}

	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << m.find(site)->second << '\n';
	}
}

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}