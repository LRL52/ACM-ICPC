//ID: LRL52  Date: 2022.7.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 500000 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, Len[N];
string s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> s[i], Len[i] = s[i].size();
    int ans = 0;
    for(int i = n - 1; i >= 1; --i){
        int lim = min(Len[i], Len[i + 1]), ok = 0;
        for(int j = 0; j < lim; ++j){
            if(s[i][j] != s[i + 1][j]){
                ok = 1;
                if(s[i][j] > s[i + 1][j]) Len[i] = j;
                break;
            }
        }
        if(!ok) Len[i] = min(Len[i], Len[i + 1]);
    }
    rep(i, 1, n){
        for(int j = 0; j < Len[i]; ++j) putchar(s[i][j]);
        puts("");
    }
	return 0;
}