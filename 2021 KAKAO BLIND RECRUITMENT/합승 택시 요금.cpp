/*11:10∫– Ω√¿€*/
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 999999;
int N;
int D[201];
int dist[201][201];
vector<pair<int, int>> graph[201];
void dijk(int start);

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	N = n;
	for (int i = 0; i < fares.size(); i++) {
		graph[fares[i][0]].push_back({ fares[i][1], fares[i][2] });
		graph[fares[i][1]].push_back({ fares[i][0], fares[i][2] });
	}

	for (int i = 1; i <= N; i++) {
		dijk(i);
	}

	int answer = INF;
	for (int i = 1; i <= N; i++) {
		int cost = dist[s][i] + dist[i][a] + dist[i][b];
		if (cost != 0 && cost < answer) {
			answer = cost;
		}
	}
	return answer;
}

void dijk(int start) {
	for (int i = 1; i <= N; i++) {
		D[i] = INF;
	}
	D[start] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ D[start],start });
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i].first;
			if (D[next] > D[node] + graph[node][i].second) {
				D[next] = D[node] + graph[node][i].second;
				pq.push({ D[next], next });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		dist[start][i] = D[i];
	}
}