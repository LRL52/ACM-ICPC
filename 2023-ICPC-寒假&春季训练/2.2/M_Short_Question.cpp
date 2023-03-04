//ID: LRL52  Date: 2023.2.2
//切比雪夫距离转曼哈顿距离
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1000000 + 55;
int n;
int a[N], b[N], p[N], q[N];

LL calc(int a[]) {
    LL ret = 0;
    sort(a + 1, a + n + 1);
    rep(i, 1, n)
        ret += (2LL * i - 1 - n) * a[i];
    return ret * 2;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) cin >> q[i];
    for(int i = 1; i <= n; ++i)
        a[i] = p[i] + q[i], b[i] = p[i] - q[i];
    cout << calc(p) + calc(q) - (calc(a) + calc(b)) / 2 << '\n';
	return 0;
}