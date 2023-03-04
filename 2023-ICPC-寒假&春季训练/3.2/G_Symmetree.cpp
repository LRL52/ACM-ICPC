/*** 
 * @Author: LRL52
 * @Date: 2023-03-04 22:24:28
 * @LastEditTime: 2023-03-04 22:50:28
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
using pii = pair<int, int>;
const int N = 2e5 + 55;
static int et = 0;
int n;
ui64 h[N];

struct Edge{
	int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
	e[++et] = (Edge){to, head[from]};
	head[from] = et;
}

int check(int x, int far) {
	map<ui64, int> Cnt;
	for(int i = head[x]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v == far) continue;
		Cnt[h[v]]++;
	}
	int odd = 0;
	ui64 odd_val = 0;
	for(auto &[hval, cnt] : Cnt) {
		if(cnt & 1) 
			++odd, odd_val = hval; 
	}
	if(odd > 1) return 0;
	if(odd == 0) return 1;
	for(int i = head[x]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v == far) continue;
		if(h[v] == odd_val) 
			return check(v, x);
	}
	assert(0);
	return 0; //should't reach here
}

//Hash以x为根的子树, 存在h数组中
ui64 tree_hash(int x, int far) {
	auto &ret = h[x];
	ret = 1;
	auto h = [](ui64 x) {
		return x * x * x * 1237123 + 19260817;
	};
	auto f = [h](ui64 x) {
		return h(x & ((1ull << 31) - 1)) + h(x >> 31);
	};
	for(int i = head[x]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(v == far) continue;
		ret += f(tree_hash(v, x));
	}
	return ret;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n; et = 0;
		rep(i, 1, n) head[i] = 0;
		rep(i, 1, n - 1) {
			int x, y;
			cin >> x >> y;
			adde(x, y), adde(y, x);
		}
		tree_hash(1, -1);
		puts(check(1, -1) ? "YES" : "NO");
	}
	return 0;
}