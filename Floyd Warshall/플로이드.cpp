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
	// ��� �׷��� �ʱ�ȭ
	int d[num][num];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k: �����ϴ� ���
	for (int k = 0; k < num; k++) {
		//i: ��� ���
		for (int i = 0; i < num; i++) {
			//j: ���� ��� 
			for (int j = 0; j < num; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// ��� �׷��� ���
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