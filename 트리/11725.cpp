#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
	int parent;
	vector<int> connect;
}node;

int N;
node tree[100001];
bool visit[100001];
void dfs(int idx, int pIdx);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].connect.push_back(b);
		tree[b].connect.push_back(a);
	}
	dfs(1, 1);
	for (int i = 2; i <= N; i++) {
		cout << tree[i].parent <<'\n';
	}
}

void dfs(int idx, int pIdx) {
	tree[idx].parent = pIdx;
	for (int i = 0; i < (int)tree[idx].connect.size(); i++) {
		if (!visit[tree[idx].connect[i]]) {
			visit[tree[idx].connect[i]] = true;
			dfs(tree[idx].connect[i], idx);
		}
	}
} 