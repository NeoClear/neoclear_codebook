#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>

#define inf 0x7fffffff
#define SIZE 210

typedef long long int64;
typedef long long ll;

using namespace std;

ll read() {
    int64 ans = 0; bool f = true; char ch = getchar();
    while (!isdigit(ch)) { if (ch == EOF) return -1; if (ch == '-') f = false; ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return f ? ans : -ans;
}

int N, M;
ll graph[SIZE][SIZE];
ll flow[SIZE];
int pre[SIZE];

void init() { memset(graph, 0, sizeof(graph)); }

ll bfs() {
    memset(pre, -1, sizeof(pre)); pre[1] = 0;
    memset(flow, 0, sizeof(flow)); flow[1] = inf;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == M) { break; }
        for (int dest = 1; dest <= M; dest++) {
            if (graph[cur][dest] > 0 && pre[dest] == -1) {
                flow[dest] = min(flow[cur], graph[cur][dest]);
                q.push(dest);
                pre[dest] = cur;
            }
        }
    }
    return pre[M] == -1 ? -1 : flow[M];
}

void edmonds_karp() {
    ll inc = 0, max_flow = 0;
    while ((inc = bfs()) != -1) {
        int it = M;
        while (it != 1) {
            graph[pre[it]][it] -= inc;
            graph[it][pre[it]] += inc;
            it = pre[it];
        }
        max_flow += inc;
    }
    cout << max_flow << endl;
}

int main() {
    while ((N = read()) != -1 && (M = read()) != -1) {
        init();
        for (int i = 0; i < N; i++) {
            int from, to; ll cap;
            from = read(); to = read(); cap = read();
            graph[from][to] += cap;
        }
        edmonds_karp();
    }
    return 0;
}