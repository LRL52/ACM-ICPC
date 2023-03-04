//ID: LRL52  Date: 2023.2.10
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using ui64 = unsigned long long;
using pii = pair<int, int>;
const int N = 500000 + 55, inf = 0x3f3f3f3f;
int D, n, fa[N];
ui64 sum1[N], sum2[N];
struct Edge {
    int u, v, w;
}e[N << 1];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

pair<ui64, ui64> Hash() {
    rep(i, 1, n) fa[i] = i, sum1[i] = 5uLL * i * i + 2, sum2[i] = (ui64)i * i * i;
    rep(i, 1, n - 1) cin >> e[i].u >> e[i].v >> e[i].w;
    auto cmp = [](const Edge &t1, const Edge &t2)->bool {
        return t1.w > t2.w;
    };
    sort(e + 1, e + n, cmp);
    pair<ui64, ui64> ret = {0, 0};
    auto &[r1, r2] = ret;
    rep(i, 1, n - 1) {
        auto [u, v, w] = e[i];
        int f1 = find(u), f2 = find(v);
        r1 += 2uLL * sum1[f1] * sum1[f2] * w;
        r2 += 2uLL * sum2[f1] * sum2[f2] * w;
        sum1[f1] += sum1[f2];
        sum2[f1] += sum2[f2];
        fa[f2] = f1;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> D >> n;
    map<pair<ui64, ui64>, int> H;
    rep(i, 1, D) {
        auto val = Hash();
        if(H.find(val) == H.end()) H[val] = i;
        printf("%d ", H[val]);
    }
	return 0;
}