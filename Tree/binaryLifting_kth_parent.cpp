#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_LOG = 17; // ceil(log2(MAX_N))

vector<int> adj[MAX_N]; // adjacency list representation of the tree
int parent[MAX_N][MAX_LOG]; // 2D array to store the 2^k-th parent of each node
int depth[MAX_N]; // array to store the depth of each node

void dfs(int node, int par, int d) {
    parent[node][0] = par;
    depth[node] = d;
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

void precompute() {
    dfs(1, -1, 0); // assuming the tree is rooted at node 1
    for (int j = 1; j < MAX_LOG; j++) {
        for (int i = 1; i < MAX_N; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int kth_parent(int node, int k) {
    for (int j = MAX_LOG - 1; j >= 0; j--) {
        if ((k >> j) & 1) {
            node = parent[node][j];
            if (node == -1) {
                break;
            }
        }
    }
    return node;
}

int main() {
    // read input and build the tree
    // ...

    precompute(); // precompute the ancestors

    int node, k;
    cin >> node >> k; // read the node and the desired ancestor index

    int result = kth_parent(node, k);
    cout << "The " << k << "-th parent of node " << node << " is node " << result << ".\n";

    return 0;
}
