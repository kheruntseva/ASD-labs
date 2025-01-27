#include <iostream>
using namespace std;

const int INF = 1000000;
const int V = 9; 


int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int vertexToIndex(char vertex) {
    return vertex - 'A'; 
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; 
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Вершина \t Расстояние от начальной вершины\n";
    for (int i = 0; i < V; i++) {
        cout << char('A' + i) << " \t\t " << dist[i] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    int graph[V][V] = {
        {0, 7, 10, 0, 0, 0, 0, 0, 0},  // A
        {7, 0, 0, 0, 0, 9, 27, 0, 0},  // B
        {10, 0, 0, 0, 31, 8, 0, 0, 0}, // C
        {0, 0, 0, 0, 32, 0, 0, 17, 21},// D
        {0, 0, 31, 32, 0, 0, 0, 0, 0}, // E
        {0, 9, 8, 0, 0, 0, 0, 11, 0},  // F
        {0, 27, 0, 0, 0, 0, 0, 0, 15}, // G
        {0, 0, 0, 17, 0, 11, 0, 0, 15},// H
        {0, 0, 0, 17, 0, 0, 15, 15, 0} // I
    };

    char startVertex;
    cout << "Введите стартовую вершину (букву от A до I): ";
    cin >> startVertex;

    int start = vertexToIndex(startVertex);

    dijkstra(graph, start);

    return 0;
}
