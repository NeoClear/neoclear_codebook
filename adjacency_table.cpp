#include <bits/stdc++.h>

#define SIZE 100010
typedef long long ll;

using namespace std;

struct Edge {
    ll to, w, next;
} edges[SIZE];

ll top = 0;
ll vertex[SIZE];

inline void insert(ll from, ll to, ll w) { edges[++top] = (Edge){to, w, vertex[from]}; vertex[from] = top; }

inline void init() { memset(vertex, 0, sizeof(vertex)); }

int main() {
    init();
    return 0;
}