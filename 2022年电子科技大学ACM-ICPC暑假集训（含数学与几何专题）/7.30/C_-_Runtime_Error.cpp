//ID: LRL52  Date: 2022.7.29
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int P, a, b, vis[N], Ans[N];

int ksm(int a, int k){
    int ret = 1;
    while(k){
        if(k & 1) ret = ret * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return ret;
}

int Inv(int x){return ksm(x, P - 2);}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(P), rd(a), rd(b);
    int inv_a = Inv(a), inv_b = Inv(b);
    Ans[1] = vis[1] = 1; int ok = 1;
    rep(i, 2, P - 1){
        int lst = Ans[i - 1];
        int x = lst * a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * inv_a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * inv_b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        ok = 0;
        break;
    }
    if(Ans[P - 1] * a % P == 1  || Ans[P - 1] * b % P == 1 ||
       Ans[P - 1] * inv_a % P == 1 || Ans[P - 1] * inv_b % P == 1)
           ok &= 1;
    else ok = 0;
    if(ok){
        puts("Yes");
        rep(i, 1, P - 1) printf("%lld ", Ans[i]);
        printf("1\n");
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    Ans[1] = vis[1] = ok = 1;
    rep(i, 2, P - 1){
        int lst = Ans[i - 1];
        int x = lst * b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * inv_a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * inv_b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        ok = 0;
        break;
    }
    if(Ans[P - 1] * a % P == 1  || Ans[P - 1] * b % P == 1 ||
       Ans[P - 1] * inv_a % P == 1 || Ans[P - 1] * inv_b % P == 1)
           ok &= 1;
    else ok = 0;
    if(ok){
        puts("Yes");
        rep(i, 1, P - 1) printf("%lld ", Ans[i]);
        printf("1\n");
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    Ans[1] = vis[1] = ok = 1;
    rep(i, 2, P - 1){
        int lst = Ans[i - 1];
        int x = lst * inv_a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * inv_b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        ok = 0;
        break;
    }
    if(Ans[P - 1] * a % P == 1  || Ans[P - 1] * b % P == 1 ||
       Ans[P - 1] * inv_a % P == 1 || Ans[P - 1] * inv_b % P == 1)
           ok &= 1;
    else ok = 0;
    if(ok){
        puts("Yes");
        rep(i, 1, P - 1) printf("%lld ", Ans[i]);
        printf("1\n");
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    Ans[1] = vis[1] = ok = 1;
    rep(i, 2, P - 1){
        int lst = Ans[i - 1];
        int x = lst * inv_b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * inv_a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * a % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        x = lst * b % P;
        if(!vis[x]){
            vis[x] = 1;
            Ans[i] = x;
            continue;
        }
        ok = 0;
        break;
    }
    if(Ans[P - 1] * a % P == 1  || Ans[P - 1] * b % P == 1 ||
       Ans[P - 1] * inv_a % P == 1 || Ans[P - 1] * inv_b % P == 1)
           ok &= 1;
    else ok = 0;
    if(ok){
        puts("Yes");
        rep(i, 1, P - 1) printf("%lld ", Ans[i]);
        printf("1\n");
        return 0;
    }
    puts("No"); 
	return 0;
}