//ID: LRL52  Date: 2022.7.26
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
//#define int unsigned long long
#define int __int128_t
int n, Cnt[N];

int sqr(int x){return x * x;}
int gcd(int a, int b){return a == 0 ? b : gcd(b % a, a);}

void print(int x){
    if(x < 0) putchar('-');
    if(x > 9) print(x / 10);
    putchar('0' + x % 10);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int x = 0, sum = 0;
    rep(i, 1, n){
        rd(x);
        sum += x;
        for(int k = 0; k < 20; ++k){
            Cnt[k] += (x >> k & 1);
        }
    }
    int D = 0;
    rep(i, 1, n){
        x = 0;
        for(int k = 0; k < 20; ++k){
            if(Cnt[k] > 0){
                x |= 1uLL << k;
                Cnt[k]--;
            }
        }
        //long long t = (long long)n * x - (long long)sum;
        //t = abs(t);
        //D += (unsigned long long)t * t;
        D += sqr(n * x - sum);
        //printf("%d ", x);
    }
    int t = n * n * n;
    int d = gcd(D, t);
    D /= d, t /= d;
    //printf("%llu/%llu\n", D, t);
    print(D); putchar('/');
    print(t);
	return 0;
}