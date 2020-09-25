#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int tc;
	cin >> tc;

	for (int TC = 0; TC < tc; TC++) {
		int n;
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			string name ,kind;
			cin >> name >> kind;
			m[kind]++;
		}
		int sum = 1;
		for (auto i = m.begin(); i != m.end(); i++) {
			sum *= (i->second + 1);
		}
		sum -= 1;
		cout << sum << endl;
	}
}