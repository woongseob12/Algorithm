#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int N = s1.size();
	vector<char> apple, lover;
	for (int i = 0; i < N; i++) {
		apple.push_back(s1[i]);
		lover.push_back(s2[i]);
	}

	sort(apple.begin(), apple.end());
	sort(lover.begin(), lover.end(), greater<>());

	vector<int> A, B;
	int idx1 = 0, idx2 = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			A.push_back(apple[idx1++]);
		}
		else {
			B.push_back(lover[idx2++]);
		}
	}

	vector<char> ans(N);
	int as = 0, ae = A.size() - 1;
	int bs = 0, be = B.size() - 1;
	int rs = 0, re = N - 1;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			if (bs >= B.size() || A[as] < B[bs]) {
				ans[rs++] = A[as++];
			}
			else {
				ans[re--] = A[ae--];
			}
		}
		else {
			if (as >= A.size() || A[as] < B[bs]) {
				ans[rs++] = B[bs++];
			}
			else {
				ans[re--] = B[be--];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i];
	}
}