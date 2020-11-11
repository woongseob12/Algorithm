#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> weight;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		weight.push_back(temp);
	}
	sort(weight.begin(), weight.end());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (weight[i] > sum + 1) {
			break;
		}
		sum += weight[i];
	}
	cout << sum + 1 << endl;
}


