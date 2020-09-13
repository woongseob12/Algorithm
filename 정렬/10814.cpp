#pragma warning (disable :4996)
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	map<int, vector<string>> m;
	for (int i = 0; i < N; i++) {
		int age;
		char temp[101];
		scanf("%d %s", &age, temp);
		string s = temp;
		m[age].push_back(s);
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		vector<string> res(i->second);
		for (int j = 0; j < res.size(); j++) {
			printf("%d %s\n", i->first, res[j]);
		}
	}
}
