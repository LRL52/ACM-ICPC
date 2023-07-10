/*** 
 * @Author: LRL52
 * @Date: 2023-05-29 00:13:20
 * @LastEditTime: 2023-05-29 01:07:52
 */
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 4e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, a[N], b[N];
vector<int> factor[M];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int up = 4e5;
    for (int i = 1; i <= up; ++i) {
        for (int j = i; j <= up; j += i) {
            factor[j].push_back(i);
        }
    }
    int Task; cin >> Task;
	while(Task--) { 
        cin >> n;
        vector<vector<int> > Pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            Pos[a[i]].push_back(i);
        } 
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        map<pii, int> Cnt;
        for (int i = 1; i <= n; ++i) {
            Cnt[{a[i], b[i]}]++;
        }
        i64 ans = 0;
        for (int z = 2; z <= 2 * n; ++z) {
            for (auto x : factor[z]) {
                auto y = z / x;
                if (x > y) break;
                if (x > n || y > n) continue;
                i64 res = 0;
                auto t = Pos[y].size() <= Pos[x].size() ? y : x;
                for (auto i : Pos[t]) {
                    // Cnt[{a[i], b[i]}]--;
                    auto aj = z / a[i], bj = z - b[i];
                    auto flag = (a[i] == aj && b[i] == bj);
                    auto it = Cnt.find({aj, bj});
                    if (it != Cnt.end()) {
                        res += it->second - flag;
                    }
                    // Cnt[{a[i], b[i]}]++;
                }
                if (x == y) ans += res >> 1;
                else ans += res;
            }
        }
        cout << ans << '\n';
	}
	return 0;
}