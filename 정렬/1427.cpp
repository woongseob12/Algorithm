#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b);

int main()
{
	string num;
	cin >> num;
	vector<int> res;
	for (int i = 0; i < num.size(); i++) {
		res.push_back(num.at(i) - '0');
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < num.size(); i++) {
		cout << res[i];
	}
	cout << endl;
}

bool cmp(int a, int b)
{
	return a > b;
}