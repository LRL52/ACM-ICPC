//ID: LRL52  Date: 2022.11.19
//带修主席树(实际上是树状数组套权值线段树)，维护动态区间第k小
//一开始naive了，以为不用写Node了，可以像普通线段树那样奔放写代码，然后发现空间会炸的，这样是O(n^2)的空间
//带修主席树空间是O(nlog^2 n)的，每次修改log棵线段树，每棵线段树修改log个结点
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = (1e5 + 55) * 2;
int n, qs, un, a[N], val[N], rt[N];
struct QS {
    char op;
    int x, y, z;
}Q[N];

const int N1 = 25;
struct TREE {
    struct Node {
        int l, r, cnt;
    }tr[N * 20 * 20];
    int q1[N1], q2[N1], p1, p2, cntN = 0;
    #define ls tr[now].l
    #define rs tr[now].r
    #define lson l, mid
    #define rson mid + 1, r
    inline int lowbit(int x) { return x & -x; }
    void update(int &now, int x, int k, int l, int r) {
        if(!now) now = ++cntN;
        if(l == r) return void(tr[now].cnt += k);
        int mid = (l + r) >> 1;
        if(x <= mid) update(ls, x, k, lson);
        else update(rs, x, k, rson);
        tr[now].cnt = tr[ls].cnt + tr[rs].cnt;
    }
    void Update(int j, int x, int k) { //修改序列第j个数，权值线段树中第x个位置元素的数量+k
        for(int i = j; i <= n; i += lowbit(i)) update(rt[i], x, k, 1, un);
    }
    int query(int k, int l, int r) {
        if(l == r) return l;
        int mid = (l + r) >> 1, res = 0;
        for(int i = 1; i <= p2; ++i) res += tr[tr[q2[i]].l].cnt;
        for(int i = 1; i <= p1; ++i) res -= tr[tr[q1[i]].l].cnt;
        if(k <= res) {
            for(int i = 1; i <= p1; ++i) q1[i] = tr[q1[i]].l;
            for(int i = 1; i <= p2; ++i) q2[i] = tr[q2[i]].l;
            return query(k, lson);
        } else {
            for(int i = 1; i <= p1; ++i) q1[i] = tr[q1[i]].r;
            for(int i = 1; i <= p2; ++i) q2[i] = tr[q2[i]].r;
            return query(k - res, rson); 
        }
    }        
    int Query(int x, int y, int k) { //查询区间[x, y]中的第k小
        p1 = p2 = 0;
        for(int i = x - 1; i; i -= lowbit(i)) q1[++p1] = rt[i];
        for(int i = y; i; i -= lowbit(i)) q2[++p2] = rt[i];
        return query(k, 1, un);
    }
}T;

signed main() {
    //freopen("P2617_11.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> qs; int x, y;
    rep(i, 1, n) cin >> a[i], val[++un] = a[i];
    rep(i, 1, qs) {
        cin >> Q[i].op >> Q[i].x >> Q[i].y;
        if(Q[i].op == 'Q') cin >> Q[i].z;
        else val[++un] = Q[i].y;
    }
    sort(val + 1, val + un + 1);
    un = unique(val + 1, val + un + 1) - val - 1;
    //对树的操作需要使用离散化后的值
    rep(i, 1, n) {
        a[i] = lower_bound(val + 1, val + un + 1, a[i]) - val;
        T.Update(i, a[i], 1);
    }
    rep(i, 1, qs) {
        if(Q[i].op == 'Q') {
            int idx = T.Query(Q[i].x, Q[i].y, Q[i].z);
            printf("%d\n", val[idx]);
        } else {
            int idx = lower_bound(val + 1, val + un + 1, Q[i].y) - val;
            T.Update(Q[i].x, a[Q[i].x], -1);
            a[Q[i].x] = idx;
            T.Update(Q[i].x, a[Q[i].x], 1);
        }
    }
	return 0;
} 