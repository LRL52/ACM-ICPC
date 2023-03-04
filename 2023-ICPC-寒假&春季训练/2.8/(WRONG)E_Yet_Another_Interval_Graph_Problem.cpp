//ID: LRL52  Date: 2023.2.6
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 2555;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, K, cut[N];
struct Node {
    int l, r, w;
    friend bool operator<(const Node &t1, const Node &t2) {
        if(t1.l != t2.l) return t1.l < t2.l;
        return t1.r < t2.r;
    }
}a[N], b[N];
LL f[N][N];

LL F(int l, int r) {
    if(f[l][r] != INF) return f[l][r];
    if(r - l + 1 <= K) return f[l][r] = 0;
    auto &ret = f[l][r];
    vector<int> val, cut;
    vector<pii> S;
    for(int i = l, j; i <= r; i = j) {
        int right = b[i].r;
        for(j = i + 1; ; ++j) {
            if(right < j || j > r) break;
            if(right == j && b[j].r > b[j].l) cut.push_back(j);
            right = max(right, b[j].r);
        }
        S.emplace_back(i, j - 1);
    }
    if(S.size() > 1) {
        ret = 0;
        for(auto [l, r] : S) ret += F(l, r);
    } else {
        ret = min(ret, b[l].w + F(l + 1, r));
        ret = min(ret, b[r].w + F(l, r - 1));
        for(auto x : cut)
            ret = min(ret, F(l, x - 1) + b[x].w + F(x + 1, r));
        for(int x = l; x <= r; ++x) {
            val.push_back(b[x].w);
        }
        sort(val.begin(), val.end());
        auto cnt = r - l + 1 - K; LL res = 0LL;
        for(size_t i = 0; i < cnt; ++i)
            res += val[i];
        ret = min(ret, res);
    }
    return ret;
}

signed main() {
// #ifdef LRL52
// 	freopen("E.in", "r", stdin);
// #endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> K;
    rep(i, 1, n) cin >> a[i].l >> a[i].r >> a[i].w;
    sort(a + 1, a + n + 1);
    rep(i, 1, n) {
        int j = i;
        while(j < n && a[j + 1].l <= a[i].r) ++j;
        b[i] = {i, j, a[i].w};
    }
    memset(f, 0x3f, sizeof(f));
    LL ans = 0;
    ans = F(1, n);
    // for(auto [l, r] : S)
    //     ans += F(l, r);
    cout << ans << '\n';
	return 0;
}