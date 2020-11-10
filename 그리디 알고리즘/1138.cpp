#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> line(N, 0);
	vector<int> bigger(N);
	for (int i = 0; i < N; i++) {
		cin >> bigger[i];
	}
	for (int i = 0; i < N; i++) {
		int cnt = bigger[i], start = 0;
		for (int j = 0; j < N; j++) {
			if (cnt == start) {
				if (line[j] == 0) {
					line[j] = i + 1;
					break;
				}
			}
			else {
				if (line[j] == 0) {
					start++;
				}
			}
	
		}
	}
	for (int i = 0; i < N; i++) {
		cout << line[i] << " ";
	}
}