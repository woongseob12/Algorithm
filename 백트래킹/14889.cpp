#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int startT[10];
bool visit[10];
int score[20][20];
int total, team;
vector<int> diff;

void dfs(int cnt, int index);
void cal(int startT[10], vector<int> linkT);

int main()
{
	cin >> total;
	team = total / 2;
	for (int i = 0; i < total; i++) {
		for (int j = 0; j < total; j++) {
			cin >> score[i][j];
		}
	}
	dfs(0, 0);
	sort(diff.begin(), diff.end());
	cout << diff.front() << endl;
}

void dfs(int cnt, int index)
{
	if (cnt == team) {
		vector<bool> lvisit(total, false);
		vector<int> linkT(team, 0);
		for (int i = 0; i < team; i++) {
			lvisit[startT[i]] = true;
		}
		for (int i = 0; i < team; i++) {
			for (int j = 0; j < total; j++) {
				if (!lvisit[j]) {
					linkT[i] = j;
					lvisit[j] = true;
					break;
				}
			}
		}
		//
		//cout << endl;
		//cout << "StartT: ";
		//for (int i = 0; i < team; i++) {
		//	cout << startT[i] << " ";
		//}
		//cout << "\tLinkT: ";
		//for (int i = 0; i < team; i++) {
		//	cout << linkT[i] << " ";
		//}
		//cout << endl;

		cal(startT, linkT);
		return;
	}

	for (int i = index; i < total; i++) {
		if (!visit[i]) {
			visit[i] = true;
			startT[cnt] = i;
			dfs(cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}

void cal(int startT[10], vector<int> linkT)
{
	int sScore = 0, lScore = 0;
	for (int i = 0; i < team; i++) {
		for (int j = 0; j < team; j++) {
			sScore += score[startT[i]][startT[j]];
		}
	}
	for (int i = 0; i < team; i++) {
		for (int j = 0; j < team; j++) {
			lScore += score[linkT[i]][linkT[j]];
		}
	}
	diff.push_back(abs(sScore - lScore));
}