//ID: LRL52  Date: 2023.2.10
//这题逻辑有点绕。首先不能作为周期的数有两种情况：
//1.a[i] != a[j]，则 abs(i - j) 的所有约数都不能作为周期
//2.该周期t不是最小循环节。即模t后不产生矛盾，所有生成元都存在，且存在t' < t, t'是周期，则t不是周期 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, vis[N];
pii b[N];
map<int, int> Ans;

int check(int T) {
    vector<vector<int> > r(T);
    for(int i = 1; i <= n; ++i) {
        auto [x_i, a_i] = b[i];
        auto idx = (x_i % T + T) % T;
        r[idx].push_back(a_i);
    }
    int ok = 1;
    for(auto &v : r) {
        if(v.size() == 0 ||  v != vector<int>(v.size(), v[0])) {
            ok = 0;
            break;
        }
    }
    return ok;
}

vector<int>& getd(int val) {
    auto _ret = new vector<int>;
    auto &ret = *_ret;
    for(int d = 1; d * d <= val; ++d) {
        if(val % d == 0) {
            ret.push_back(d);
            if(d * d != val) ret.push_back(val / d);
        }
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
    rep(i, 1, n) cin >> b[i].first >> b[i].second;
    rep(i, 1, n)
        rep(j, i + 1, n) {
            auto [x_i, a_i] = b[i];
            auto [x_j, a_j] = b[j];
            if(a_i != a_j) {
                auto &v = getd(abs(x_i - x_j));
                for(auto d : v) Ans[d] = 1;
            }
        }
    for(int T = 1; T <= n; ++T) {
        int ok = check(T);
        if(ok) {
            if(vis[T]) Ans[T] = 1;
            for(int j = T; j <= n; j += T)
                vis[j] = 1;
        }
    }
    LL ans = 0;
    for(auto it : Ans)
        ans += it.first;
    cout << Ans.size() << " " << ans << '\n';
	return 0;
}