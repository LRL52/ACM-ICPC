//ID: LRL52  Date: 2022.7.21
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
int n;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%s", s + 1);
        int len = strlen(s + 1);
        int cnt0 = 0, cnt1 = 0, x = 0;
        rep(i, 1, len){
            cnt0 += s[i] == '(';
            cnt1 += s[i] == ')';
            x += s[i] == '?';
        }
        int lcnt = len / 2 - cnt0, rcnt = len / 2 - cnt1;
        int sum = 0, l = 0, r = 0, flag = 0;
        if(lcnt == 0 || rcnt == 0){
            puts("YES");
            continue;
        }
        int uqe = 0;
        rep(i, 1, len){
            if(s[i] == '(') ++sum;
            if(s[i] == ')') --sum;
            if(s[i] == '?'){
                if(l < lcnt - 1) ++sum, ++l;
                else if(l == lcnt - 1 && !flag){
                    --sum, ++r; flag = 1;
                } 
                else if(l == lcnt - 1 && flag){
                    ++sum, ++l;
                }
                else --sum, ++r;
            }
            if(sum < 0){
                uqe = 1;
                break;
            }
        }
        uqe ? puts("YES") : puts("NO");
	}
	return 0;
}