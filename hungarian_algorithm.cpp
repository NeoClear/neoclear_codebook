#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>

#define SIZE 100010
typedef long long ll;

using namespace std;

ll read() {
    ll ans = 0; bool f = true; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = false; ch = getchar(); }
    while (isdigit(ch)) { ans = ans * 10 + ch - '0'; ch = getchar(); }
    return f ? ans : -ans;
}

struct Edge {
    ll to, w, next;
} edges[SIZE];

ll top = 0;
ll K, M, N;
ll vertex[SIZE];
int book[SIZE];
ll match[SIZE];

inline void init() { memset(edges, 0, sizeof(edges)); memset(vertex, 0, sizeof(vertex)); memset(match, 0, sizeof(match)); top = 0; }

inline void insert(ll from, ll to, ll w) { edges[++top] = (Edge){to, w, vertex[from]}; vertex[from] = top; }

ll extend(ll cur) {
    for (ll it = vertex[cur]; it; it = edges[it].next) {
        ll dest = edges[it].to;
        if (!book[dest]) {
            book[dest] = 1;
            if (match[dest] == 0 || extend(match[dest])) {
                match[dest] = cur;
                match[cur] = dest;
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    ll ans = 0;
    for (ll i = 1; i <= M + N; i++) {
        memset(book, 0, sizeof(book));
        if (!match[i]) { ans += extend(i); }
    }
    printf("%lld\n", ans);
}

int main() {
    while ((K = read()) && (M = read()) && (N = read())) {
        init();
        for (ll i = 0; i < K; i++) {
            ll g = read(), b = read();
            insert(g, b + M, 0); insert(b + M, g, 0);
        }
        solve();
    }
    return 0;
}