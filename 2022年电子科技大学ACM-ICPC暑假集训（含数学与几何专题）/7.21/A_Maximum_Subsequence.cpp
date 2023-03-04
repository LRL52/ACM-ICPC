//ID: LRL52  Date: 2022.7.21
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, m, a[N];
vector<int> v[2];

void dfs(int i, int up, int idx, int sum){
    if(i > up){
        v[idx].push_back(sum);
        return;
    }
    dfs(i + 1, up, idx, sum);
    dfs(i + 1, up, idx, (sum + a[i]) % m);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m);
    rep(i, 1, n) rd(a[i]);
    int mid = (1 + n) >> 1;
    dfs(1, mid, 0, 0);
    dfs(mid + 1, n, 1, 0);
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    int ans = 0, p = v[1].size() - 1;
    for(int i = 0; i < v[0].size(); ++i){
        int x = v[0][i];
        while(p > 0 && x + v[1][p] >= m) --p;
        ans = max(ans, x + v[1][p]);
    }
    printf("%lld\n", ans);
	return 0;
}