#include <iostream>
using namespace std;

const int N = 6;
const int INF = INT_MAX;

int dist[N][N] = {
	{0, 28, 21, 59, 12, 27},
	{7, 0, 24, INF, 21, 9},
	{9, 32, 0, 13, 11, INF},
	{8, INF, 5, 0, 16, INF},
	{14, 13, 15, 10, 0, 22},
	{15, 18, INF, INF, 6, 0}
};

int path[N][N] = {
	{0, 2, 3, 4, 5, 6},
	{1, 0, 3, 4, 5, 6},
	{1, 2, 0, 4, 5, 6},
	{1, 2, 3, 0, 5, 6},
	{1, 2, 3, 4, 0, 6},
	{1, 2, 3, 4, 5, 0}
};

void algoritm() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (dist[i][k] == INF) continue;
			for (int j = 0; j < N; j++) {
				if (dist[k][j] == INF) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}

void print() {
	setlocale(LC_ALL, "Rus");

	cout << "матрица D:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF) cout << "INF\t";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\nМатрица S:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << path[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	
	algoritm();


	print();
}
