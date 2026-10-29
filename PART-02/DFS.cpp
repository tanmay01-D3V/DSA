#include <iostream>
#include <vector>

using namespace std;

// Recursive helper function for graph traversal
void dfs_helper(int u, const vector<vector<int>>& g, vector<bool>& visited, vector<int>& order) {
    visited[u] = true;
    order.push_back(u); 
    
    // Traverse right-to-left to match specific execution paths
    for (int i = g[u].size() - 1; i >= 0; --i) {
        int v = g[u][i];
        if (!visited[v]) {
            dfs_helper(v, g, visited, order);
        }
    }
}

// Runs DFS and returns an ordered list of discovered nodes. O(V + E)
vector<int> dfs(const vector<vector<int>>& g, int src) {
    vector<bool> visited(g.size(), false);
    vector<int> order;
    dfs_helper(src, g, visited, order);
    return order;
}

int main() {
    vector<vector<int>> g = {{1,2},{0,3,4},{0,4},{1},{1,2}};
    
    cout << "DFS Discovery Order: ";
    for (int node : dfs(g, 0)) {
        cout << node << ' ';
    }
    cout << '\n'; // Output: 0 2 4 1 3
    return 0;
}
