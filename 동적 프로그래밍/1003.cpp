#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> fibo(40);

int main()
{
	int TC;
	cin >> TC;
	fibo[0] = make_pair(1, 0);
	fibo[1] = make_pair(0, 1);
	for (int testCase = 0; testCase < TC; testCase++) {
		int N;
		cin >> N;
		for (int i = 2; i <= N; i++) {
			fibo[i].first = fibo[i - 1].first + fibo[i - 2].first;
			fibo[i].second = fibo[i - 1].second + fibo[i - 2].second;
		}
		cout << fibo[N].first << " " << fibo[N].second << endl;
	}
}