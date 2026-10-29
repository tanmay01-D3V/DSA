#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Returns shortest distance from src to every node (-1 if unreachable). O(V + E)
vector<int> bfs(const vector<vector<int>>& g, int src) {
    vector<int> dist(g.size(), -1);
    queue<int> q;
    
    dist[src] = 0;
    q.push(src);
    
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        
        for (int v : g[u]) {
            if (dist[v] == -1) { // Mark at enqueue
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> g = {{1,2},{0,3,4},{0,4},{1},{1,2}};
    
    cout << "BFS Distances: ";
    for (int d : bfs(g, 0)) {
        cout << d << ' ';
    }
    cout << '\n'; // Output: 0 1 1 2 2
    return 0;
}
