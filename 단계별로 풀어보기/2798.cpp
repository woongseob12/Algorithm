#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> card;
	vector<int> res;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		card.push_back(temp);
	}
	int len = card.size();
	for (int i = 0; i < len - 2; i++) {
		for (int j = i + 1; j < len - 1; j++) {
			for (int k = j + 1; k < len; k++) {
				int sum = card[i] + card[j] + card[k];
				if (sum <= M) {
					res.push_back(sum);
				}
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res.back() << endl;
}