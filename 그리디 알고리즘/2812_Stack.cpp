#include <iostream>
#include <string>
using namespace std;

char stack[500001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	string s;
	cin >> N >> K >> s;
	int top = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		while (top > 0 && K > 0 && stack[top - 1] < s[i]) {
			top--;
			K--;
		}
		stack[top] = s[i];
		top++;
	}
	stack[top - K] = '\0';
	cout << stack << endl;
}

