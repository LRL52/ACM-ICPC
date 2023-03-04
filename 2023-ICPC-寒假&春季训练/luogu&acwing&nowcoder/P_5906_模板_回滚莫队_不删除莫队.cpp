//ID: LRL52  Date: 2023.1.10
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, qs, tt, a[N], L[N], R[N], Ans[N];
struct Query {
    int id, l, r;
}Q[N];
vector<int> val;
vector<pii> bL, bR;

int get(int x) { return x / tt; }

void init() {
    for(size_t i = 0; i < val.size(); ++i) {
        L[i] = n + 1, R[i] = 0;
    }
}

void add(int i, int &ans, int flag = 0) {
    int x = a[i];
    if(flag) {
        bL.emplace_back(x, L[x]);
        bR.emplace_back(x, R[x]);
    }
    L[x] = min(L[x], i);
    R[x] = max(R[x], i);
    ans = max(ans, R[x] - L[x]);
}

void resume() {
    for(auto it = bL.rbegin(); it != bL.rend(); it++) {
        auto [i, j] = *it;
        L[i] = j;
    }
    for(auto it = bR.rbegin(); it != bR.rend(); it++) {
        auto [i, j] = *it;
        R[i] = j;
    }
}

signed main() {
#ifdef LRL52
    freopen("P5906.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    rep(i, 1, n) cin >> a[i], val.emplace_back(a[i]);
    cin >> qs;
    rep(i, 1, qs) cin >> Q[i].l >> Q[i].r, Q[i].id = i;
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    rep(i, 1, n) a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    tt = sqrt(n);
    auto cmp = [](const Query &t1, const Query &t2) {
        int al = get(t1.l), bl = get(t2.l);
        if(al != bl) return al < bl;
        return t1.r < t2.r;
    };
    sort(Q + 1, Q + qs + 1, cmp);
    for(int now = 1; now <= qs; ) {
        init();
        int rp = now;
        while(rp < qs && get(Q[rp + 1].l) == get(Q[now].l)) ++rp;
        int bound = min(get(Q[now].l) * tt + tt - 1, n);
        while(now <= rp && Q[now].r <= bound) {
            auto [id, l, r] = Q[now];
            int ans = 0;
            bL.clear(); bR.clear();
            rep(i, l, r) add(i, ans, 1);
            Ans[id] = ans;
            resume();
            ++now;
        }
        int y = bound, ans = 0;
        while(now <= rp) {
            auto [id, l, r] = Q[now];
            while(y < r) add(++y, ans);
            int bans = ans, x = bound + 1;
            bL.clear(); bR.clear();
            while(x > l) add(--x, ans, 1);
            Ans[id] = ans;
            resume();
            ans = bans;
            ++now;
        }
    }
    rep(i, 1, qs) printf("%d\n", Ans[i]);
	return 0;
} 
    