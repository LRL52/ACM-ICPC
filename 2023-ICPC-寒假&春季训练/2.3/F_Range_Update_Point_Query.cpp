//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, m, c[N], done[N], a[N];

int lowbit(int x) { return x & -x; }

void add(int x, int k) {
    for(int i = x; i <= n; i += lowbit(i))
        c[i] += k;
}

int query(int x) {
    int ret = 0;
    for(int i = x; i; i -= lowbit(i))
        ret += c[i];
    return ret;
}

int calc(int x) {
    int ret = 0;
    while(x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        cin >> n >> m;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) c[i] = done[i] =0;
        rep(tt, 1, m) {
            int op, x, y;
            cin >> op;
            if(op == 1) {
                cin >> x >> y;
                add(x, 1); add(y + 1, -1);
            } else {
                cin >> x;
                if(a[x] <= 9) printf("%d\n", a[x]);
                else {
                    int res = query(x);
                    int t = res - done[x];
                    while(t > 0 && a[x] > 9) {
                        a[x] = calc(a[x]);
                        --t;
                    }
                    done[x] = res;
                    printf("%d\n", a[x]);
                }
            }
        }
    }
	return 0;
}