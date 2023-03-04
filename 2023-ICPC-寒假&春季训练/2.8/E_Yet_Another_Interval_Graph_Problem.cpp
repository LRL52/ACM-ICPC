//ID: LRL52  Date: 2023.2.6
//这题应该反过来考虑，如何让剩下的连通块size <= K 且权值和最大
//将区间端点离散化，f[i]仅考虑区间右端点 <= i的所有区间，选取若干区间使得构成的连通块合法，且权值和最大
//枚举最后一个构成的连通块，f[i] = max { f[j] + g(j + 1, i) }, g(j + 1, i)表示仅考虑区间左右端点都在[j+1, i]的区间，构成1个连通块，权值最大为多少
//g(j+1, i)只需要取 top-k 即可
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = (2500 + 55) * 2, inf = 0x3f3f3f3f;
int n, K;
LL f[N];
struct Node {
    int l, r, w;
}a[N];
vector<Node> b[N];

signed main() {
#ifdef LRL52
	freopen("E.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> K; LL S = 0;
    vector<int> val;
    rep(i, 1, n) {
        cin >> a[i].l >> a[i].r >> a[i].w;
        val.push_back(a[i].l);
        val.push_back(a[i].r);
        S += a[i].w;
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    int m = val.size();
    rep(i, 1, n) {
        auto &[l, r, w] = a[i];
        l = lower_bound(val.begin(), val.end(), l) - val.begin() + 1;
        r = lower_bound(val.begin(), val.end(), r) - val.begin() + 1;
        b[l].push_back(a[i]);
    }
    auto cmp = [](const Node &t1, const Node &t2)->bool {
        return t1.r < t2.r;
    };
    rep(i, 1, m) sort(b[i].begin(), b[i].end(), cmp);
    for(int i = 1; i <= m; ++i) {
        priority_queue<int, vector<int>, greater<int> > q;
        LL sum = 0;
        for(int j = i - 1; j >= 0; --j) {
            for(auto [l, r, w] : b[j + 1]) {
                if(r > i) break;
                sum += w; q.push(w);
                while(q.size() > K) {
                    sum -= q.top();
                    q.pop();
                }
            }
            f[i] = max(f[i], f[j] + sum);
        }
    }
    LL ans = S - f[m];
    cout << ans << '\n';
	return 0;
}