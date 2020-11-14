#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	// 세로의 길이를 1로 만듦 : N -1
	// N개의 가로 막대를 길이를 1로 만듦 : N * (M - 1) 
	cout << N -1 + N * (M - 1) << endl;
}