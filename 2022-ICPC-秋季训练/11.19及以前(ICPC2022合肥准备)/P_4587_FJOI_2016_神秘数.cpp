//ID: LRL52  Date: 2022.11.14
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e6 + 55;
int n, qs, cntN, val[N], a[N], rt[N];
struct Node {
    int l, r;
    LL sum;
}tr[N * 25];

void buildtree(int old, int &now, int x, int l, int r) {
    tr[++cntN] = tr[old], now = cntN;
    if(l == r) {
        tr[now].sum += val[x];
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) buildtree(tr[old].l, tr[now].l, x, l, mid);
    else buildtree(tr[old].r, tr[now].r, x, mid + 1, r);
    tr[now].sum = tr[tr[now].l].sum + tr[tr[now].r].sum;
}

LL query(int old, int now, int x, int y, int l, int r) { //tr[now] - tr[old]是区间内的数
    if(x <= l && r <= y) return tr[now].sum - tr[old].sum;
    int mid = (l + r) >> 1;
    if(x <= mid && y > mid) return query(tr[old].l, tr[now].l, x, y, l, mid) + query(tr[old].r, tr[now].r, x, y, mid + 1, r);
    else if(x <= mid) return query(tr[old].l, tr[now].l, x, y, l, mid);
    else return query(tr[old].r, tr[now].r, x, y, mid + 1, r);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n; int _l, _r, l, r, un = 0;
    rep(i, 1, n) cin >> a[i], val[++un] = a[i];
    sort(val + 1, val + n + 1);
    un = unique(val + 1, val + un + 1) - val - 1;
    rep(i, 1, n) {
        a[i] = lower_bound(val + 1, val + un + 1, a[i]) - val;
        buildtree(rt[i - 1], rt[i], a[i], 1, un);
    }
    cin >> qs;
    LL ans = 0;
    rep(i, 1, qs) {
        cin >> _l >> _r;
        // l = min((_l + ans) % n + 1, (_r + ans) % n + 1);
        // r = max((_l + ans) % n + 1, (_r + ans) % n + 1);
        l = _l, r = _r;
        ans = 1;
        while(1) {
            int idx = upper_bound(val + 1, val + un + 1, ans) - val - 1;
            if(idx < 1) break;
            LL res = query(rt[l - 1], rt[r], 1, idx, 1, un);
            if(res < ans) break;
            ans = res + 1;
        }
        printf("%lld\n", ans);
    }
	return 0;
} 
    