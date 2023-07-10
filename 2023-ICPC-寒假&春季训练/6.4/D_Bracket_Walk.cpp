/*** 
 * @Author: LRL52
 * @Date: 2023-06-05 11:13:52
 * @LastEditTime: 2023-06-05 11:26:18
 */
// 太magic了，太人类智慧了
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, qs; cin >> n >> qs >> (s + 1);
	set<int> S;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(' && (i % 2 == 0)) S.insert(i);
		if (s[i] == ')' && (i % 2 == 1)) S.insert(i);
	}
	for (int _ = 1; _ <= qs; ++_) {
		int x; cin >> x;
		if (S.find(x) == S.end()) S.insert(x);
		else S.erase(x);
		if (n % 2) puts("NO");
		else if (S.size() && ((*S.begin() % 2) || (*S.rbegin() % 2 == 0))) puts("NO");
		else puts("YES"); 
	}
	return 0;
}