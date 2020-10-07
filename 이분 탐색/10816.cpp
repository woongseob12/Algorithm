#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> card;
int findIndex(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		card.push_back(val);
	}
	sort(card.begin(), card.end());

	cin >> M;
	vector<int> search_card(M);
	for (int i = 0; i < M; i++) {
		cin >> search_card[i];
	}
	
	for (int i = 0; i < M; i++) {
		cout << findIndex(search_card[i]) << " ";
	}
}

int findIndex(int n) {
	vector<int>::iterator low = lower_bound(card.begin(), card.end(), n);
	if (*low > n) { return 0; }
	vector<int>::iterator high = upper_bound(card.begin(), card.end(), n);

	return (high - card.begin()) - (low - card.begin());
}
