/*** 
 * @Author: LRL52
 * @Date: 2023-06-09 16:49:35
 * @LastEditTime: 2023-06-09 17:14:03
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int fa[N];
i64 val[N];

int find(int x) {
    if (fa[x] == x) return x;
    auto p = fa[x], rt = find(fa[x]);
    val[x] += val[p];
    return fa[x] = rt;
}

signed main() {
#ifdef LRL52
	freopen("P8779.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, Q;
    cin >> n >> m >> Q;
    for (int i = 0; i <= n; ++i) fa[i] = i, val[i] = 0;
    for (int i = 1; i <= m; ++i) {
        int l, r; i64 s; 
        cin >> l >> r >> s;
        int f1 = find(l - 1), f2 = find(r);
        auto w = s + val[l - 1] - val[r];
        if (f1 < f2) {
            fa[f2] = f1;
            val[f2] = w;
        } else {
            fa[f1] = f2;
            val[f1] = -w;
        }
    }
    for (int _ = 1; _ <= Q; ++_) {
        int l, r; cin >> l >> r;
        int f1 = find(l - 1), f2 = find(r);
        if (f1 == f2) cout << val[r] - val[l - 1] << '\n';
        else cout << "UNKNOWN" << '\n';
    }
	return 0;
}