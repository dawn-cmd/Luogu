//
// Created by LightString on 1/20/2023.
//
#include "bits/stdc++.h"
using namespace std;
class segmentTree {
private:
    struct node {
        int l;
        int r;
        int lSeq;
        int rSeq;
        int contribution;
    };
    vector<node> tree;
    vector<int> relate;
    inline node merge(const node &a, const node &b) {
        node tmp{a.l, b.r, a.lSeq, b.rSeq, 0};
        bool canConnect = (relate[a.r] * relate[b.l] < 0);
        if (a.r - a.l + 1 == a.lSeq && canConnect)
            tmp.lSeq += b.lSeq;
        if (b.r - b.l + 1 == b.rSeq && canConnect)
            tmp.rSeq += a.rSeq;
        tmp.contribution = a.contribution + b.contribution + (canConnect ? ((a.rSeq + b.lSeq) >> 1) - (a.rSeq >> 1) - (b.lSeq >> 1) : 0);
        return tmp;
    }
    void buildHelper(const int &id, const int &l, const int &r) {
        if (l == r)
        {
            tree[id] = (node){l, r, 1, 1, 1};
            return;
        }
        int mid = (l + r) >> 1;
        buildHelper(id << 1, l, mid);
        buildHelper(id << 1 | 1, mid + 1, r);
        tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
    }
    void updateHelper(const int &id, const int &pos) {
        if (tree[id].l == tree[id].r && tree[id].l == pos)
        {
            tree[id].contribution = relate[pos] != 0;
            return;
        }
        if (pos <= tree[id << 1].r)
            updateHelper(id << 1, pos);
        else
            updateHelper(id << 1 | 1, pos);
        tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
    }
    node queryHelper(const int &id, const int &l, const int &r) {
        if (l == tree[id].l && r == tree[id].r)
            return tree[id];
        if (r <= tree[id << 1].r)
            return queryHelper(id << 1, l, r);
        if (l >= tree[id << 1 | 1].l)
            return queryHelper(id << 1 | 1, l, r);
        return merge(queryHelper(id << 1, l, tree[id << 1].r), queryHelper(id << 1 | 1, tree[id << 1 | 1].l, r));
    }
public:
    segmentTree(const int &n) {
        tree = vector<node>(n << 4);
        relate = vector<int>(n);
        for (auto &num: relate)
            num = 1;
        buildHelper(1, 0, n - 1);
    }
    void update(int id, int data) {
        if (relate[id] == data)
            return;
        relate[id] = data;
        updateHelper(1, id);
    }
    int query(int l, int r) {
        return queryHelper(1, l, r).contribution;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // input data
    int n;
    int m;
    cin >> n >> m;
    vector<int> nums(n << 1);
    unordered_map<int, int> h;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        nums[i + n] = nums[i];
        h[nums[i]] = i;
        cnt[nums[i]]++;
    }
    segmentTree t(n << 1);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < (n << 1); ++j)
            t.update(j, i == nums[j] ? 0 : (i > nums[j] ? 1 : -1));
        if (h.find(i) == h.end())
            cout << -1 << ' ';
        else
            cout << t.query(h[i], h[i] + n) << ' ';
    }
}