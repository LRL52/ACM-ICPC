//ID: LRL52  Date: 2022.7.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> s + 1;
    int n = strlen(s + 1);
    int K = 0, cnt0 = 0, cnt1 = 0;
    rep(i, 1, n){
        K += s[i] == '?';
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
    }
    int second = (n - 2) / 2, first = n - 2 - second;
    int s00 = 0, s01 = 0, s10 = 0, s11 = 0;
    if(first >= cnt1) s00 = 1;
    if(second >= cnt0) s11 = 1;
    if(cnt1 <= first + 1 && cnt1 + K >= first + 1){
        int v1 = first + 1 - cnt1, v0 = K - v1;
        int zero = 0, one = 0, ok = 0;
        for(int i = n; i >= 1; --i){
            if(s[i] == '0' || (s[i] == '?' && v0 > 0)) zero = 1, v0--;
            else{
                if(zero) s10 = 1;
                break;
            }
        }
        v1 = first + 1 - cnt1, v0 = K - v1, zero = one = 0;
        for(int i = n; i >= 1; --i){
            if(s[i] == '1' || (s[i] == '?' && v1 > 0)) one = 1, v1--;
            else{
                if(one) s01 = 1;
                break;
            }
        }
    }
    if(s00) puts("00");
    if(s01) puts("01");
    if(s10) puts("10");
    if(s11) puts("11");
	return 0;
}