//ID: LRL52  Date: 2023.2.8
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
struct Node {
    int v, d, r;
    friend bool operator<(const Node &t1, const Node &t2) {
        if(t1.d != t2.d) return t1.d < t2.d;
        return t1.r < t2.r;
    }
};
priority_queue<Node> q;

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// vector<int> a{1, 2, 3, 4, 5};
	// auto b = std::move(a);
	// a.push_back(1);
	// for(auto x : b) cout << x << " ";
	// cout << '\n';
	// for(auto x : a) cout << x << " ";
	// cout << '\n';
	q.push({1, 1, 2});
	q.push({2, 2, 0});
	q.push({3, 1, 5});
	while(!q.empty()) {
		auto [v, d, r] = q.top(); q.pop();
		printf("%d %d %d\n", v, d, r);
	}
	return 0;
}