#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <queue>

#define inf 0x7fffffff
#define SIZE 100010

typedef long long ll;

using namespace std;

struct Edge {
    ll to, w, next;
};

ll read() {
    ll ans = 0; bool f = true; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = false; ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return f ? ans : -ans;
}

ll T, R, P, S;
struct Edge edges[SIZE]; ll top = 0;
ll vertex[SIZE];
ll dis[SIZE];
bool used[SIZE];

inline void insert(ll from, ll to, ll w) {
    edges[++top] = (Edge){to, w, vertex[from]};
    vertex[from] = top;
}

inline void init() { memset(vertex, 0, sizeof(vertex)); memset(used, 0, sizeof(used)); for (int i = 0; i < SIZE; i++) dis[i] = inf; }

void spfa(ll src) {
    dis[src] = 0;
    queue<ll> q; q.push(src);
    used[src] = true;
    while (!q.empty()) {
        ll cur = q.front(); q.pop();
        ll it = vertex[cur];
        used[cur] = false;
        while (it) {
            ll dest = edges[it].to;
            if (dis[cur] + edges[it].w < dis[dest]) {
                dis[dest] = dis[cur] + edges[it].w;
                if (!used[dest]) { used[dest] = true; q.push(dest); }
            }

            it = edges[it].next;
        }
    }
    return;
}

int main() {
    init();
    T = read(); R = read(); P = read(); S = read();
    for (int i = 0; i < R; i++) {
        ll from, to, w; from = read(); to = read(); w = read();
        insert(from, to, w); insert(to, from, w);
    }
    for (int i = 0; i < P; i++) {
        ll from, to, w; from = read(); to = read(); w = read();
        insert(from, to, w);
    }
    spfa(S);
    for (int i = 1; i <= T; i++) { if (dis[i] == inf) printf("NO PATH\n"); else printf("%lld\n", dis[i]); }

    return 0;
}