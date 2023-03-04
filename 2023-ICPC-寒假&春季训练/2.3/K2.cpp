//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 4100, inf = 0x3f3f3f3f;
int n = 12, tcnt, a[N];
int f[M], Ans[5];
pii pre[M];

void getans(pii p) {
    if(p.first == -1) return;
    auto [i, s] = p;
    int pp = 0;
    for(int k = 0; k < n; ++k) {
        if(s >> k & 1) {
            Ans[++pp] = a[k];
            // printf("%d ", a[k]);
        }
    }
    printf("%d %d %d\n", Ans[1], Ans[2], Ans[3]);
    // puts("");
    getans(pre[i]);
}

signed main() {
#ifdef LRL52
	freopen("K.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        vector<int> S;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                for(int k = j + 1; k < n; ++k)
                    if(a[i] + a[j] > a[k])
                        S.push_back((1 << i) | (1 << j) | (1 << k));
        memset(f, -1, sizeof(f));
        f[0] = 0, pre[0] = { -1, -1 };
        int ans = 0, state = 0;
        for(int i = 0; i < (1 << n); ++i) {
            if(f[i] == -1) continue;
            if(f[i] > ans) {
                ans = f[i], state = i;
                if(ans == 4) break;
            }
            for(auto s : S) {
                if(i & s) continue;
                auto j = i | s;
                if(f[i] + 1 > f[j]) {
                    f[j] = f[i] + 1;
                    pre[j] = { i, s };
                }
            }
        }
        printf("Case #%d: %d\n", ++tcnt, ans);
        getans(pre[state]);
    }
	return 0;
}