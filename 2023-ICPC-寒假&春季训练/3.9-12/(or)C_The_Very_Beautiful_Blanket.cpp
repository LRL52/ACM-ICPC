/*** 
 * @Author: LRL52
 * @Date: 2023-03-09 18:25:17
 * @LastEditTime: 2023-03-09 18:50:03
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
using namespace chrono;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
i64 mask = (1ull << 63) - 1;
mt19937 Rng(52);
uniform_int_distribution<int> dist(0, 62);
i64 a[N][N];

int rng() {
    return dist(Rng);
}

i64 rnd() {
    auto ret = mask;
    for(int i = 0; i < 5; ++i) {
        int t = rng();
        ret &= ~(1 << t);
    }
    assert((unsigned long long)ret < (1ull << 63));
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int up = 200;
    map<i64, int> use;
    rep(i, 1, up) {
        rep(j, 1, up) {
            if(i <= 1 || j <= 1) {
                while(1) {
                    auto num = rnd();
                    if(use.find(num) == use.end()) {
                        use[num] = 1;
                        a[i][j] = num;
                        break;
                    }
                }
            } else {
                auto t = a[i - 1][j - 1] | a[i - 1][j] | a[i][j - 1];
                while(1) {
                    auto num = rnd();
                    if((num | t) == mask && use.find(num) == use.end()) {
                        use[num] = 1;
                        a[i][j] = num;
                        break;
                    }
                }
            }
        }
    }
    auto t1 = a[1][1] | a[1][2] | a[2][1] | a[2][2];
    auto t2 = a[3][3] | a[3][4] | a[4][3] | a[4][4];
    assert(t1 == t2 && t1 == mask); 
    int Task; cin >> Task;
	while(Task--) { 
		int n, m;
        cin >> n >> m;
        cout << n * m << '\n';
        rep(i, 1, n)
            rep(j, 1, m)
                cout << a[i][j] << " \n"[j == m];
	}
	return 0;
}