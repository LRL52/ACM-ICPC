//ID: LRL52  Date: 2023.2.8
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
mt19937 Rng(random_device{}());
uniform_int_distribution<int> dist(0, 2e9);

int rnd(int x) { return dist(Rng) % x + 1; }

signed main() {
#ifdef LRL52
	// freopen("D.in", "r", stdin);
    freopen("B.in", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int Task = 10;
    printf("%d\n", Task);
    while(Task--) {
        int n = 20000, L = n, m = 1e9;
        printf("%d %d %d\n", n, L, m);
        for(int i = 1; i <= n; ++i) printf("%d ", rnd(998244352));
        puts("");
    }
	return 0;
}