//ID: LRL52  Date: 2023.2.12
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, K, m, In[N];
struct Edge{
    int v, nxt;
}e[N];
int head[N];
vector<int> in[N];
priority_queue<int, vector<int>, greater<int> > q[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> K >> m;
    rep(i, 1, m) {
        int x, y;
        adde(x, y);
        ++In[y];
    }
    in[1].resize(n + 1);
    for(int i = 1; i <= n; ++i) in[1][i] = In[i];
    for(int i = 2; i <= K; ++i) in[i] = in[1];
    rep(tt, 1, n * K) {
        cin >> x;
        
    }
	return 0;
}