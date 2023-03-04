//ID: LRL52  Date: 2023.2.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 300000 + 55;
const int up = 1e6;
int n, Cnt[up + 55], Pos[up + 55];
pii sum[up + 55];
vector<pii> b[up + 55];
struct Node {
    int x, y, z;
}a[N];

int Solve() {
    rep(i, 0, up) 
        Cnt[i] = Pos[i] = 0, sum[i] = { 0, i },  vector<pii>().swap(b[i]);
    rep(i, 1, n) {
        auto [x, y, z] = a[i];
        sum[y].first += z, Cnt[x]++;
        b[x].emplace_back(y, z);
    }
    sort(sum, sum + up + 1, greater<pii>());
    rep(i, 0, up) Pos[sum[i].second] = i;
    int ret = sum[0].first + sum[1].first + sum[2].first;
    rep(x, 0, up) {
        int v1 = 0, v2 = 0, s = 0;
        for(auto [y, z] : b[x])
            sum[Pos[y]].first -= z, s += z;
        for(int i = 0; i <= Cnt[x] + 2; ++i) {
            auto t = sum[i].first;
            if(t > v1) v2 = v1, v1 = t;
            else if(t > v2) v2 = t;
        }
        // if(v1 + v2 + s == 6) cerr << "v1 = " << v1 << "v2 = " << v2 << "s = " << s << '\n';
        ret = max(ret, v1 + v2 + s);
        for(auto [y, z] : b[x])
            sum[Pos[y]].first += z;
    }
    return ret;
}

signed main() {
    // freopen("D.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
    rep(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].z;
    auto res1 = Solve();
    rep(i, 1, n) swap(a[i].x, a[i].y);
    auto res2 = Solve();
    cout << max(res1, res2) << endl;
	return 0;
}