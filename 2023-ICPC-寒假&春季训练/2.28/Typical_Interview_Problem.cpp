//ID: LRL52  Date: 2023.2.28
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s;
    for(int i = 1; i <= 45; ++i) {
        if(i % 3 == 0) s.push_back('F');
        if(i % 5 == 0) s.push_back('B');
    }
    // cout << s << endl;
    // s = s + s;
    int Task; cin >> Task;
	while(Task--) {
		string t;
        int n;
        cin >> n >> t;
        int ok = 0;
        for(int i = 0; i <= s.size() - t.size(); ++i) {
            if(s.substr(i, t.size()) == t) {
                ok = 1;
                break;
            }
        }
        ok ? puts("YES") : puts("NO");
	}
	return 0;
}