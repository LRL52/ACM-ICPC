//ID: LRL52  Date: 2022.5.10
//二进制拆分优化多重背包，懒得写单调队列优化多重背包了
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int M = 4e4 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, V;
vector<int> vol, val;
long long f[M];

int main() {
#ifdef LRL52
	freopen("O.in", "r", stdin);
#endif
    rd(n), rd(V); int x, y, z;
    rep(i, 1, n){
        rd(x), rd(y), rd(z); int s = 1;
        for(int k = 0; s <= z; s += 1 << k){
            int cnt = 1 << k;
            val.push_back(1LL * cnt * x);
            vol.push_back(1LL * cnt * y);
            ++k;
            if(s + (1 << k) > z) break;
        }
        if(s < z){
            val.push_back(1LL * (z - s) * x);
            vol.push_back(1LL * (z - s) * y);
        }
    }
    for(int j = 0; j < val.size(); ++j){
        for(int i = V; i >= 0; --i){
            if(i - vol[j] >= 0)
                f[i] = max(f[i], f[i - vol[j]] + val[j]);
        }
    }
    long long ans = 0;
    rep(i, 0, V) ans = max(ans, f[i]);
    printf("%lld\n", ans);
	return 0;
}