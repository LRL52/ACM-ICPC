//ID: LRL52  Date: 2022.7.13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 100055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 1e9 + 7;
int n, Pcnt;
int st[N], prime[N], d[N], pow2[N], mu[N];
vector<int> p[N], c[N];

void Euler(){
    rep(i, 2, 100000){
        if(!st[i]) prime[++Pcnt] = i, mu[i] = -1;
        for(int j = 1; j <= Pcnt && i <= 100000 / prime[j]; ++j){
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
}

void init(){
    rep(i, 2, 100000){
        int x = i;
        for(int j = 1; j <= Pcnt && prime[j] * prime[j] <= x; ++j){
            if(x % prime[j] == 0){
                p[i].push_back(prime[j]), c[i].push_back(0);
                while(x % prime[j] == 0) x /= prime[j], c[i][c[i].size() - 1]++;
            }
        }
        if(x != 1) p[i].push_back(x), c[i].push_back(1);;
    }
}

void dfs(int x, int now, int i){
    if(i >= p[x].size()){
        d[now]++;
        //if(now == 9)
        //    printf("x = %d\n", x);
        return;
    }
    int t = 1;
    for(int j = 0; j <= c[x][i]; ++j){
        dfs(x, now * t, i + 1); 
        t = t * p[x][i];
    }
}


int main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
    Euler();
    init();
	rd(n); int x;
    rep(i, 1, n){
        rd(x);
        dfs(x, 1, 0);
    }
    pow2[0] = 1;
    rep(i, 1, n) pow2[i] = pow2[i - 1] * 2LL % MOD;
    long long ans = pow2[n] - 1;
    for(int i = 2; i <= 100000; ++i){
        if(d[i] == 0) continue;
        //printf("d[%d] = %d\n", i, d[i]);
        //int t = 1;
        //for(int j = 0; j < c[i].size(); ++j)
        //    t = t * (c[i][j] + 1);
        //if(t & 1) ans = (ans + (pow2[d[i]] - 1)) % MOD;
        //else ans = (ans - (pow2[d[i]] - 1) + MOD) % MOD;
        ans = (ans + 1LL * mu[i] * (pow2[d[i]] - 1) + MOD) % MOD;
    }
    printf("%lld\n", (ans % MOD + MOD) % MOD);
	return 0;
}
