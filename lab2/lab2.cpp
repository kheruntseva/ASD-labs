#include <iostream>

using namespace std;

const int MAX = 10; // Максимальное количество вершин

class Graph {
public:
    int adjList[MAX][MAX]; // Матрица смежности
    bool visited[MAX]; // Массив для хранения информации о посещенных вершинах

    Graph() {
        // заполняем матрицу нулями чтобы потом самим написать ребра
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                adjList[i][j] = 0;
            }
        }
        // массив посещенных вершин, пока ни одной не посещено
        for (int i = 0; i < MAX; i++) {
            visited[i] = false;
        }
    }

    void addEdge(int u, int v) {
        adjList[u][v] = 1;
        adjList[v][u] = 1;
    }

    // Поиск в ширину (BFS)
    void BFS(int start) {
        bool visited[MAX] = { false };// Локальный массив посещенных
        int queue[MAX], front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = true;

        cout << "Порядок обхода BFS: ";
        while (front < rear) {
            int vertex = queue[front++];// Извлекаем вершину из очереди
            cout << vertex + 1 << " "; 

            // Проверяем соседей вершины
            for (int i = 0; i < MAX; i++) {
                if (adjList[vertex][i] && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    // Поиск в глубину (DFS)
    void DFS(int vertex) {
        visited[vertex] = true;
        cout << vertex + 1 << " ";

        // Рекурсивно посещаем всех соседей
        for (int i = 0; i < MAX; i++) {
            if (adjList[vertex][i] && !visited[i]) {
                DFS(i);
            }
        }
    }

    // Функция для сброса массива посещенных вершин перед повторным запуском алгоритма
    void resetVisited() {
        for (int i = 0; i < MAX; i++) {
            visited[i] = false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 7);
    g.addEdge(1, 6);
    g.addEdge(4, 5);
    g.addEdge(6, 7);
    g.addEdge(7, 2);
    g.addEdge(3, 5);
    g.addEdge(3, 8);
    g.addEdge(5, 8);
    g.addEdge(8, 9);
   

    // Поиск в ширину (BFS)
    g.BFS(0);

    // Сброс посещенных вершин перед DFS
    g.resetVisited();

    // Поиск в глубину (DFS) начиная с вершины 1 (индекс 0)
    cout << "Порядок обхода DFS: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
