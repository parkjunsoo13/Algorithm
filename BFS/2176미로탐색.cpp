/*
2178 - BFS - ¹Ì·ÎÅ½»ö
https://www.acmicpc.net/problem/2178
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[100][100];
int visit[100][100] = { 0, };
int d[100][100] = { 0, };
int move_x[4] = { 1, 0, -1, 0 };
int move_y[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> a;
int bfs(int x, int y) {

	visit[x][y] = true;
	a.push({ x, y });
	while (!a.empty()) {
		int temp_x = a.front().first;
		int temp_y = a.front().second;
		a.pop();
		for (int i = 0; i < 4; i++) {
			int x = temp_x + move_x[i];
			int y = temp_y + move_y[i];
			if (0 <= x && x < N && 0 <= y && y < M && map[x][y] == 1 && !visit[x][y]) {
				a.push({ x, y });
				visit[x][y] = true;
				d[x][y] = d[temp_x][temp_y] + 1;

			}
		}
	}
	return d[N - 1][M - 1];
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d", bfs(0, 0) + 1);
}