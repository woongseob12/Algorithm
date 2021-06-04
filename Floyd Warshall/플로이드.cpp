#include <iostream>
using namespace std;

const int num = 4;
const int INF = 987654321;

int a[num][num] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
}; 

void floyd() {
	// 결과 그래프 초기화
	int d[num][num];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k: 경유하는 노드
	for (int k = 0; k < num; k++) {
		//i: 출발 노드
		for (int i = 0; i < num; i++) {
			//j: 도착 노드 
			for (int j = 0; j < num; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// 결과 그래프 출력
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%3d ", d[i][j]);
		}
		printf("\n");
	}
}

int main() 
{
	floyd();
}