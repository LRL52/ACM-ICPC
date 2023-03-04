#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N= 3e5 + 55;
int n, m, root, cntN;
struct Node {
    int l, r, vir, sum, L, R, K, tagv, rec, ge;
}tr[N * 31];

#define ls tr[now].l
#define rs tr[now].r
Node add(int l, int r, const Node& now, const Node&t1, const Node&t2) {
    Node ret; int mid = (l + r) >> 1;
    ret.l = now.l, ret.r = now.r;
    ret.sum = t1.sum + t2.sum;
    ret.vir = t1.vir + t2.vir;
    if(t1.L == mid - l + 1) ret.L = t1.L + t2.L;
    else ret.L = t1.L;
    if(t2.R == r - mid) ret.R = t2.R + t1.R;
    else ret.R = t2.R;
    ret.K = max(t1.K, max(t2.K, t1.R + t2.L));
    ret.K = max(ret.K, max(ret.L, ret.R));
    ret.tagv = ret.rec = ret.ge = 0;
    return ret;
}

void clear(int cur) {
    tr[cur].K = tr[cur].L = tr[cur].R = tr[cur].rec = tr[cur].tagv = tr[cur].vir = tr[cur].sum = tr[cur].ge = 0;
}

void pushdown(int l, int r, int now) {
    //printf("%d %d %d\n", l, r, now);
    if(!tr[now].l) tr[now].l = ++cntN;
    if(!tr[now].r) tr[now].r = ++cntN;
    int mid = (l + r) >> 1;
    if(tr[now].rec) {
        clear(ls);
        clear(rs);
        tr[ls].rec = tr[rs].rec = 1; //!!!!!!!!!!!!!!!!!!!!!!
        tr[now].rec = tr[now].tagv = tr[now].ge = 0;
        return;
    }
    if(tr[now].tagv) {
        tr[ls].L = tr[ls].R = tr[ls].vir = tr[ls].K = mid - l + 1;
        tr[ls].tagv = 1;
        tr[rs].L = tr[rs].R = tr[rs].vir = tr[rs].K = r - mid;
        tr[rs].tagv = 1;
        tr[now].tagv = 0;
    }
    if(tr[now].ge) {
        tr[ls].sum = mid - l + 1;
        tr[ls].ge = 1;
        tr[rs].sum = r - mid;
        tr[rs].ge = 1;
        tr[now].ge = 0;
    }
}

//vir
void update1(int x, int y, int l, int r, int &now) {
    if(!now) now = ++cntN;
    if(x <= l && r <= y) {
        tr[now].vir = tr[now].L = tr[now].R = tr[now].K = r - l + 1;
        tr[now].tagv = 1;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(l, r, now);
    if(x <= mid) update1(x, y, l, mid, tr[now].l);
    if(y  > mid) update1(x, y, mid + 1, r, tr[now].r);
    tr[now] = add(l, r, tr[now], tr[ls], tr[rs]);
}

void update2(int x, int y, int l, int r, int &now) {
    if(!now) now = ++cntN;
    if(x <= l && r <= y) {
        tr[now].sum = r - l + 1;
        tr[now].ge = 1;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(l, r, now);
    if(x <= mid) update2(x, y, l, mid, tr[now].l);
    if(y  > mid) update2(x, y, mid + 1, r, tr[now].r);
    tr[now] = add(l, r, tr[now], tr[ls], tr[rs]);
}

void update3(int x, int y, int l, int r, int &now) {
    if(!now) now = ++cntN;
    if(x <= l && r <= y) {
        clear(now);
        tr[now].rec = 1;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(l, r, now);
    if(x <= mid) update3(x, y, l, mid, tr[now].l);
    if(y  > mid) update3(x, y, mid + 1, r, tr[now].r);
    tr[now] = add(l, r, tr[now], tr[ls], tr[rs]);
}

Node query(int x, int y, int l, int r, int &now) {
    if(!now) now = ++cntN;
    if(x <= l && r <= y) return tr[now];
    int mid = (l + r) >> 1;
    pushdown(l, r, now);
    if(x <= mid && y > mid) {
        Node ln = query(x, y, l, mid, ls);
        Node rn = query(x, y, mid + 1, r, rs);
        return add(l, r, tr[now], ln, rn);
    } else 
    if(x <= mid) return query(x, y, l, mid, ls);
    else return query(x, y, mid + 1, r, rs);
}

int main(){
    freopen("K.in","r",stdin);
    //rd(n), rd(m); 
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    int ans = 0, op, y, x, k, _l, _r;
    rep(i, 1, m) {
        //rd(op), rd(_l), rd(_r);
        cin >> op >> _l >> _r;
        if(op == 2) cin >> k;
        x = max(_l - ans, 1);
        y = min(_r + ans, n);
        if(op == 1) {
            update1(x, y, 1, n, root);
        } else
        if(op == 2) {
            Node res = query(x, y, 1, n, root);
            if(res.K >= k) update2(x, y, 1, n, root);
        } else 
        if(op == 3) {
            update3(x, y, 1, n, root);
        } else {
            Node res = query(x, y, 1, n, root);
            printf("%d\n", res.sum);
            ans = res.sum;
        }
    }
    return 0;
}
