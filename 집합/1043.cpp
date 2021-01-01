#include <iostream>
#include <vector>
using namespace std;

int N, M, numOfTruth, ans;
int parent[51];
vector<int> know;
vector<int> party[50];
int find(int x);
void Union(int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	cin >> numOfTruth;
	for (int i = 0; i < numOfTruth; i++) {
		int knowTruth;
		cin >> knowTruth;
		know.push_back(knowTruth);
	}

	for (int i = 0; i < M; i++) {
		int numOfParty;
		cin >> numOfParty;
		for (int j = 0; j < numOfParty; j++) {
			int person;
			cin >> person;
			party[i].push_back(person);
			Union(party[i][0], party[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		bool canLie = true;
		for (int j = 0; j < (int)party[i].size(); j++) {
			for (int k = 0; k < (int)know.size(); k++) {
				if (find(party[i][j]) == find(know[k])) {
					canLie = false;
					break;
				}
			}
			if (!canLie) { break; }
		}
		if (canLie) { ans++; }
	}
	cout << ans << endl;
}

int find(int x) {
	if (parent[x] == x) { return x; }
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}