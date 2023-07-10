#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
        int n, m;
		cin >> n >> m;
        if (n == 4 && m == 4) {
            puts("16 7 1 9");
            puts("12 8 2 3");
            puts("13 4 10 11");
            puts("14 5 6 15");
            puts("");
            continue;
        }
        int flag = 0;
        if (n < m) swap(n, m), flag = 1;
        vector<vector<int> > a(n + 1, vector<int>(m + 1));
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                a[i][j] = ++cnt;
        vector<vector<int> > Ans(1, vector<int>(m + 1));
        for (int i = 1; i <= n; i += 2) Ans.emplace_back(a[i]);
        for (int i = 2; i <= n; i += 2) Ans.emplace_back(a[i]);
        if (flag) {
            for (int j = 1; j <= m; ++j) {
                for (int i = 1; i <= n; ++i)
                    printf("%d ", Ans[i][j]);
                puts("");
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j)
                    printf("%d ", Ans[i][j]);
                puts("");
            }
        }
        puts("");
	}
	return 0;
}