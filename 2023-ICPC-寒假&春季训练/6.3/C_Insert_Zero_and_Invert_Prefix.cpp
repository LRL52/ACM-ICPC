#include <bits/stdc++.h>
#include <functional>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (a[n] == 1) {
            puts("NO");
            continue;
        }
        vector<int> Ans;
        function<void (int, int)> solve = [&](int x, int rev) {
            if (x == 1) {
                Ans.push_back(0);
                return;
            }
            int val = a[x - 1] ^ rev;
            if (val == 1) {
                Ans.push_back(x - 1);
                a.erase(a.begin() + x);
            } else {
                Ans.push_back(x - 2);
                a.erase(a.begin() + x - 1);
            }
            solve(x - 1, rev ^ 1);
        };
        solve(n, 0);
        puts("YES");
        reverse(Ans.begin(), Ans.end());
        for (auto x : Ans) printf("%d ", x);
        puts("");
	}
	return 0;
}