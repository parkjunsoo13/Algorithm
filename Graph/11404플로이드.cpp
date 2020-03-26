/*
11404 - graph - �÷��̵� (warshall Algorithm)
https://www.acmicpc.net/problem/11404
*/
#define INF 99999999
#include <iostream>
#include <queue>
using namespace std;
int n, bus;
int src, dest, cost;
int city[100][100];

void init() { // ������ �������� �迭 �ʱ�ȭ 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) city[i][j] = 0;
			else city[i][j] = INF;
		}
	}
}

void warshall() {
	// i ���ľ��ϴ� ���
	for (int i = 0; i < n; i++) {
		// j ����ϴ� ���
		for (int j = 0; j < n; j++) {
			// k ������ ���
			for (int k = 0; k < n; k++) {
				if (city[j][i] + city[i][k] < city[j][k]) {
					city[j][k] = city[j][i] + city[i][k];
				}
			}
		}
	}
}


int main() {
	scanf("%d%d", &n, &bus);
	init();
	for (int i = 0; i < bus; i++) {
		scanf("%d%d%d", &src, &dest, &cost);
		if (city[src - 1][dest - 1] > cost)
			city[src - 1][dest - 1] = cost;
	}
	warshall();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (city[i][j] == INF) city[i][j] = 0;
			printf("%d ", city[i][j]);
		}
		printf("\n");
	}
}