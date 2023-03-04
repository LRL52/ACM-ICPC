//ID: LRL52  Date: 2022.7.22
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
map<pair<int, int>, int> H;
int n, X[N], Y[N], U[N][N], V[N][N];

int gcd(int a, int b){return a == 0 ? b : gcd(b % a, a);}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n) rd(X[i]), rd(Y[i]);
    rep(i, 1, n){
        rep(j, i + 1, n){
            int u = X[j] - X[i], v = Y[j] - Y[i];
            int d = gcd(abs(u), abs(v));
            u /= d, v /= d;
            if(u < 0 && v != 0) u = -u, v = -v;
            else if(u == 0) v = 1;
            else if(v == 0) u = 1;
            //printf("u = %d v = %d\n", u, v);
            H[make_pair(u, v)]++;
            U[i][j] = u, V[i][j] = v;
        }
    }
    int ans = 0, sum = n * (n - 1) / 2;;
    //printf("sum = %d\n", sum);
    rep(i, 1, n){
        rep(j, i + 1, n){
            int u = U[i][j], v = V[i][j];
            ans += sum - H[make_pair(u, v)];
        }
    }
    printf("%lld\n", ans / 2);
	return 0;
}