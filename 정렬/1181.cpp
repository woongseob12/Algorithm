#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b);
int main()
{
	int N;
	cin >> N;
	vector<string> res;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		res.push_back(temp);
	}
	sort(res.begin(), res.end(), cmp);
	res.erase(unique(res.begin(), res.end()), res.end());
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}

bool cmp(string a, string b)
{
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}