//ID: LRL52  Date: 2022.7.12
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int inf = 0x3f3f3f3f;
int s, t, flag, maxstep;
int Pcnt, prime[N], st[N], f[N];
vector<int> p[N];

void Euler(){
    rep(i, 2, 1225){
        if(!st[i]) prime[++Pcnt] = i;
        for(int j = 1; j <= Pcnt && i <= 1225 / prime[j]; ++j){
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int dfs(int now, int step){
    if(step == maxstep){
        flag = 1;
        if(now == t) return 1;
        else return 0;
    }
    if(step > f[now]) return 0;
    f[now] = step;
    int x = now, res = 0;
    while(x < t) x <<= 1, ++res;
    if(step + res > maxstep) return flag = 1, 0;
    //int idx = lower_bound(prime + 1, prime + Pcnt + 1, min(now, t - now)) - prime;
    //printf("now = %d idx = %d\n", now, idx);
    //if(now == 999){
    //    res = res;
    //    printf("aa");
    //}
    /*for(int i = idx; i >= 1; --i){
        if(now + prime[i] > t || now % prime[i]) continue;
        dfs(now + prime[i], step + 1);
    }*/
    for(int i = (int)p[now].size() - 1; i >= 0; --i){
        if(p[now][i] >= now || now + p[now][i] > t) continue;
        if(dfs(now + p[now][i], step + 1)) return 1;
    }
    return 0;
}

void init(){
    rep(i, 2, 1000){
        int x = i;
        for(int j = 1; j <= Pcnt && prime[j] * prime[j] <= x; ++j){
            if(x % prime[j] == 0){
                p[i].push_back(prime[j]);
                while(x % prime[j] == 0) x /= prime[j];
            }
        }
        if(x != 1) p[i].push_back(x);
    }
}

int main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
    Euler();
    init();
	int Task; rd(Task); int casecnt = 0;
	while(Task--){
		rd(s), rd(t);
        int ok = 0; flag = 1;
        rep(i, s, t) f[i] = inf;
        for(maxstep = 0; flag; maxstep++){
            flag = 0;
            if(dfs(s, 0)){
                printf("Case %d: %d\n", ++casecnt, maxstep);
                ok = 1; break;
            }
        }
        if(!ok) printf("Case %d: -1\n", ++casecnt);
        //if(Ans < inf) printf("Case %d: %d\n", ++casecnt, Ans);
        //else printf("Case %d: -1\n", ++casecnt);
	}
	return 0;
}
