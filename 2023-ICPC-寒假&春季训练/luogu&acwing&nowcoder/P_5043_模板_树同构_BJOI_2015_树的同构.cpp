/*** 
 * @Author: LRL52
 * @Date: 2023-03-04 22:35:12
 * @LastEditTime: 2023-03-04 22:51:02
 */
//本题不会存在 v->fa 的边，也不需要把结果保存在h数组里
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
static int et = 0;
int m;

struct Edge{
	int v, nxt;
}e[N];
int head[N];

inline void adde(int from, int to){
	e[++et] = (Edge){to, head[from]};
	head[from] = et;
}

//Hash以x为根的子树
ui64 tree_hash(int x) {
	auto ret = 1;
	auto h = [](ui64 x) {
		return x * x * x * 1237123 + 19260817;
	};
	auto f = [h](ui64 x) {
		return h(x & ((1ull << 31) - 1)) + h(x >> 31);
	};
	for(int i = head[x]; i; i = e[i].nxt) {
		int v = e[i].v;
		ret += f(tree_hash(v));
	}
	return ret;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> m;
    map<ui64, int> H;
    rep(tt, 1, m) {
        int n, x, root; cin >> n; et = 0;
        for(int i = 1; i <= n; ++i) head[i] = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> x;
            if(x) adde(x, i);
            else root = i; 
        }
        auto hval = tree_hash(root);
        if(H.find(hval) == H.end()) {
            H[hval] = tt;
        }
        cout << H[hval] << '\n';
    }
	return 0;
}