#include <vector>
#include <iostream>

class fwt {
private:
    vector<int> sums_;
    // return the lowbit of an integer
    static inline int lowbit(int x) { return x & (-x); }

public:
    // the index of fwt start at 1. Thus, we initialize as n + 1
    fwt(int n): sums_(n + 1, 0) {}
    // id in update increases until exceeds the size of fwt
    void update(int id, int delta) {
        while (id < sums_.size()) {
            sums_[id] += delta;
            id += lowbit(id);
        }
    }
    // id in query decreases until less or equal to 0
    int query(int id) const {
        int ans = 0;
        while (id > 0) {
            ans += sums_[id];
            id -= lowbit(id);
        }
        return ans;
    }
};