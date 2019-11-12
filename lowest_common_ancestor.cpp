#include <vector>
#include <iostream>
#define size 100010
#define max_bit 31

vector<int, vector<int>> graph;
int f[size][max_bit + 1];
int depth[max_bit];

void calc_depth(int node, int d) {
    depth[node] = d;
    for (const auto& dest : graph[node]) {
        f[dest][0] = node;
        calc_depth(dest, d + 1);
    }
}

void init_f(int n) {
    for (int b = 1; b < max_bit; b++)
        for (int i = 1; i <= n; i++)
            if (~f[i][b - 1])
                f[i][b] = f[f[i][b - 1]][b - 1];
}

int find_lca(int u, int v) {
    // u must be deeper than v
    if (depth[v] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int b = max_bit - 1; b >= 0; b--)
        if ((1 << b) & diff)
            u = f[u][b];
    for (int b = max_bit - 1; b >= 0; b--)
        if (f[u][b] != f[v][b]) {
            u = f[u][b];
            v = f[v][b];
        }
    return f[u][0];
}

int main() {
    memset(f, 0xff, sizeof(f));
    return 0;
}