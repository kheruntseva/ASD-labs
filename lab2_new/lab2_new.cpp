#include <iostream>
using namespace std;

const int MAX = 10;

struct Edge {
    int u, v;
};

class Graph {
public:
    int adjMatrix[MAX][MAX];  
    bool visited[MAX];        
    Edge edges[MAX];           
    int edgeCount = 0;        
    int adjList[MAX][MAX];    
    

    Graph() {
       
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                adjMatrix[i][j] = 0;
                adjList[i][j] = -1;
            }
        }

        for (int i = 0; i < MAX; i++) {
            visited[i] = false;
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 

        edges[edgeCount].u = u;
        edges[edgeCount].v = v;
        edgeCount++;

        for (int i = 0; i < MAX; i++) {
            if (adjList[u][i] == -1) {
                adjList[u][i] = v;
                break;
            }
        }
        for (int i = 0; i < MAX; i++) {
            if (adjList[v][i] == -1) {
                adjList[v][i] = u;
                break;
            }
        }
    }

    // Функция для вывода матрицы смежности
    void printAdjMatrix() {
        cout << "Матрица смежности:" << endl;
        for (int i = 0; i < MAX; i++) 
        {
            for (int j = 0; j < MAX; j++) 
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Поиск в ширину (BFS)
    void BFS(int start) {
        bool visited[MAX] = { false }; 
        int queue[MAX], front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = true;

        cout << "Порядок обхода BFS: ";
        while (front < rear) {
            int vertex = queue[front++];
            cout << vertex + 1 << " ";  

            for (int i = 0; i < MAX; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
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

        for (int i = 0; i < MAX; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFS(i);
            }
        }
    }

    // Сброс посещённых вершин
    void resetVisited() {
        for (int i = 0; i < MAX; i++) {
            visited[i] = false;
        }
    }

    void printEdges() {
        cout << "Список рёбер:" << endl;
        for (int i = 0; i < edgeCount; i++) {
            cout << edges[i].u + 1 << " - " << edges[i].v + 1 << endl;
        }
    }

    void printAdjList() {
        cout << "Список смежности:" << endl;
        for (int i = 0; i < MAX; i++) 
        {
            cout << i + 1 << ": ";
            for (int j = 0; j < MAX && adjList[i][j] != -1; j++) 
            {
                cout << adjList[i][j] + 1 << " ";
            }
            cout << endl;
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

    g.printEdges();

    g.printAdjList();

    g.BFS(6);

    g.resetVisited();

    g.printAdjMatrix();

    cout << "Порядок обхода DFS: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
