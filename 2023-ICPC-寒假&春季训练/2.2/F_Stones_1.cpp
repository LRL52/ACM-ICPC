//ID: LRL52  Date: 2023.1.15
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 300000 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, a[N], val[N];
char s[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> (s + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1, j; i <= n; i = j + 1) {
        j = i;
        int v = a[i];
        while(j < n && s[j + 1] == s[i]) {
            ++j;
            v = max(v, a[j]);
        }
        val[++val[0]] = v;
    }
    if(val[0] <= 2) {
        puts("0");
        return 0;
    }
    sort(val + 2, val + val[0]);
    int cnt = (val[0] - 2 + 1) / 2;
    LL ans = 0;
    for(int i = val[0] - 1, j = 1; j <= cnt; --i, ++j)
        ans += val[i];
    cout << ans << endl;
	return 0;
}