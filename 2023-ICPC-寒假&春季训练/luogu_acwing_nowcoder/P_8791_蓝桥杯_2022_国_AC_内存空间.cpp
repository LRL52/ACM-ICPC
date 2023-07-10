/*** 
 * @Author: LRL52
 * @Date: 2023-06-09 19:47:37
 * @LastEditTime: 2023-06-09 21:18:52
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("P8791.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	i64 ans = 0;
    int m; cin >> m;
	while(m--) { 
		string prompt, s;
        cin >> prompt >> std::ws;
        getline(cin, s);
        i64 mul = 1; auto idx = 0ULL;
        int cnt = 0;
        if (prompt == string("int") || prompt == string("long")) {
            if (prompt == string("int")) mul = 4;
            else mul = 8;
            while ((idx = s.find_first_of('=', idx)) != string::npos) {
                ++cnt;
                ++idx;
            }
            ans += mul * cnt;
        } else
        if (prompt == string("String")) {
            while ((idx = s.find('"', idx)) != string::npos) {
                auto nxt = s.find('"', idx + 1);
                ans += nxt - idx - 1;
                idx = nxt + 1; 
            }
        } else {
            if (prompt == string("int[]")) mul = 4;
            else mul = 8;
            while ((idx = s.find('[', idx)) != string::npos) {
                auto nxt = s.find(']', idx + 1);
                cnt += stoi(s.substr(idx + 1, nxt - idx - 1));
                idx = nxt + 1; 
            }
            ans += mul * cnt;
        }
	}
    string unit[] = {"GB", "MB", "KB", "B"};
    vector<int> Ans;
    for (int i = 0; i < 4; ++i) {
        Ans.push_back(ans % 1024);
        ans /= 1024;
    }
    assert(ans == 0);
    reverse(Ans.begin(), Ans.end());
    for (int i = 0; i < 4; ++i) {
        if (Ans[i] > 0)
            cout << Ans[i] << unit[i];
    }
    cout << endl;
	return 0;
}