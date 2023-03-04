//ID: LRL52  Date: 2023.1.8 ~ 1.10
//回滚莫队模板
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e5 + 55, inf = 0x3f3f3f3f;
int n, tt, qs, Cnt[N], a[N];
LL Ans[N];
struct Query {
    int id, l, r;
}Q[N];
vector<int> val;

int get(int x) {
    return x / tt;
}

void add(int x, LL &ans) {
    ++Cnt[x];
    ans = max(ans, (LL)Cnt[x] * val[x]);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> qs; int x, y;
    rep(i, 1, n) cin >> a[i], val.emplace_back(a[i]);
    rep(i, 1, qs) {
        cin >> x >> y;
        Q[i] = { i, x, y };
    }
    tt = sqrt(n) + 1;
    auto cmp = [](const Query &t1, const Query &t2)->bool {
        int al = get(t1.l), bl = get(t2.l);
        if(al != bl) return al < bl;
        return t1.r < t2.r;
    };
    sort(Q + 1, Q + qs + 1, cmp);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    rep(i, 1, n) a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    for(int now = 1; now <= qs; ) {
        int rp = now; // rp是块内的最后一个询问编号
        while(rp < qs && get(Q[rp + 1].l) == get(Q[now].l)) ++rp;
        int bound = min(get(Q[now].l) * tt + tt - 1, n); // 当前块的右端点
        //处理r在块内询问
        while(now <= rp && Q[now].r <= bound) {
            LL res = 0;
            auto [id, l, r] = Q[now];
            rep(i, l, r) add(a[i], res);
            Ans[id] = res;
            rep(i, l, r) --Cnt[a[i]];
            ++now;
        }
        //处理r在块外的询问
        int x = bound + 1, y = bound;
        LL ans = 0;
        while(now <= rp) {
            auto [id, l, r] = Q[now];
            while(y < r) add(a[++y], ans);
            LL backup = ans;
            while(x > l) add(a[--x], ans);
            Ans[id] = ans;
            while(x <= bound) --Cnt[a[x++]];
            ans = backup;
            ++now;
        }
        memset(Cnt, 0, sizeof(Cnt));
    }
    rep(i, 1, qs) printf("%lld\n", Ans[i]); 
}
    