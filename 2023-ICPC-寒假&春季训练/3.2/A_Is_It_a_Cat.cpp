//ID: LRL52  Date: 2023.3.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        int n;
		cin >> n >> (s + 1);
        char a[] = {'m', 'e', 'o', 'w'};
        char b[] = {'M', 'E', 'O', 'W'};
        int ok = 0, j = 0;
        for(int i = 0; i < 4; ++i) {
            while(j < n && (s[j + 1] == a[i] || s[j + 1] == b[i])) {
                ok |= 1 << i;
                ++j;
            }
        }
        if(ok == (1 << 4) - 1 && j == n) puts("YES");
        else puts("NO");
	}
	return 0;
}