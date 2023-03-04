//ID: LRL52  Date: 2023.1.7
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 10000 + 55, M = 1e6 + 55, inf = 0x3f3f3f3f;
int n, m, tt, ans, a[N], Ans[N], Cnt[M];
struct Query {
    int id, l, r, t; // id->询问编号, t->修改编号
}Q[N];
struct Modify {
    int p, val;
}U[N];

int get(int x) {
    return x / tt;
}

void add(int x) {
    if(!Cnt[x]) ++ans;
    ++Cnt[x];
}

void del(int x) {
    --Cnt[x];
    if(!Cnt[x]) --ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    int qcnt = 0, tcnt = 0;
    rep(i, 1, m) {
        string op; int x, y;
        cin >> op >> x >> y;
        if(op == "Q") {
            ++qcnt;
            Q[qcnt] = { qcnt, x, y, tcnt };
        } else {
            ++tcnt;
            U[tcnt] = { x, y };
        }
    }
    tt = cbrt((double) n * max(tcnt, 1)) + 1;
    auto cmp = [](const Query&t1, const Query&t2)->bool {
        int al = get(t1.l), ar = get(t1.r);
        int bl = get(t2.l), br = get(t2.r);
        if(al != bl) return al < bl;
        if(ar != br) return ar < br;
        return t1.t < t2.t;
    }; 
    sort(Q + 1, Q + qcnt + 1, cmp);
    int l = 1, r = 0, t = 0;
    for(int i = 1; i <= qcnt; ++i) {
        while(r < Q[i].r) add(a[++r]);
        while(r > Q[i].r) del(a[r--]);
        while(l < Q[i].l) del(a[l++]);
        while(l > Q[i].l) add(a[--l]);
        while(t < Q[i].t) {
            ++t;
            int pos = U[t].p;
            if(pos >= l && pos <= r) {
                del(a[pos]);
                add(U[t].val);
            }
            swap(a[pos], U[t].val);
        }
        while(t > Q[i].t) {
            int pos = U[t].p;
            if(pos >= l && pos <= r) {
                del(a[pos]);
                add(U[t].val);
            }
            swap(a[pos], U[t].val);
            --t;
        }
        Ans[Q[i].id] = ans;
    }
    for(int i = 1; i <= qcnt; ++i) printf("%d\n", Ans[i]);
	return 0;
}