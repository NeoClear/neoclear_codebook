#include <iostream>
#define size 1000010

using namespace std;

struct segment_node {
    int left;
    int right;
    int weight;
    int lazy;
};

struct segment_node tree[size * 4 + 1];

// build segment tree
// param: k -> index of segment node in the array
void build(int left, int right, int k) {
    tree[k].left = left;
    tree[k].right = right;
    tree[k].lazy = 0;
    if (left == right) {
        cin >> tree[k].weight;
        return;
    }
    int mid = (left + right) / 2;
    build(left, mid, k * 2);
    build(mid + 1, right, k * 2 + 1);
    tree[k].weight = tree[k * 2].weight + tree[k * 2 + 1].weight;
}

// change the value of a single point
// param: k -> index of segment node in the array
void update(int i, int j, int addition, int k) {
    if (tree[k].left >= i && tree[k].right <= j) {
        tree[k].weight += addition * (tree[k].right - tree[k].left + 1);
        tree[k].lazy += addition;
        return;
    }
    if (tree[k].lazy)
        down(k);
    int mid = (tree[k].left + tree[k].right) / 2;
    if (i <= mid)
        update(i, mid, addition, k * 2);
    if (j > mid)
        update(mid + 1, j, addition, k * 2 + 1);
    tree[k].weight = tree[k * 2].weight + tree[k * 2 + 1].weight;
}

// get the sum of the range
// param: i, j represents interval [i, j]
int sum(int i, int j, int k) {
    if (tree[k].left >= i && tree[k].right <= j)
        return tree[k].weight;
    if (tree[k].lazy)
        down(k);
    int ans = 0;
    int mid = (tree[k].left + tree[k].right) / 2;
    if (i <= mid)
        ans += sum(i, j, k * 2);
    if (j > mid)
        ans += sum(i, j, k * 2 + 1);
    return ans;
}

void down(int k) {
    tree[k * 2].lazy += tree[k].lazy;
    tree[k * 2 + 1].lazy += tree[k].lazy;
    tree[k * 2].weight += tree[k].lazy * (tree[k * 2].right - tree[k * 2].left + 1);
    tree[k * 2 + 1].weight += tree[k].lazy * (tree[k * 2 + 1].right - tree[k * 2 + 1].left + 1);
    tree[k].lazy = 0;
}

int main() {
    return 0;
}