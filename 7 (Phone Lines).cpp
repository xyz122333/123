#include <iostream>
#include <climits>
using namespace std;
#define MAX 100
int graph[MAX][MAX], n;

int findMinKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX, minIndex;
    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void primMST() {
    int parent[n], key[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << "Minimum Spanning Tree: " << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] + 1 << " - " << i + 1 << " \t " << graph[parent[i]][i] << endl;
    }
}

int main()
{
    cout << "Enter number of offices: ";
    cin >> n;
    cout << "Enter cost of phone lines between each pair of offices:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }
    primMST();
    return 0;
}
