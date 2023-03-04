//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, K, Ans[N], del[N];
set<int> s;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(K);
    if(K > n / 2){
        puts("-1");
        return 0;
    }
    rep(i, 1, n) s.insert(i);
    rep(i, 1, K){
        Ans[i] = i + K;
        s.erase(i + K);
    }
    set<int>::iterator it;
    set<int>::reverse_iterator rit;
    for(rit = s.rbegin(); rit != s.rend(); rit++){
        int x = *rit;
        if(x > n - K){
            del[x] = 1;
            Ans[x - K] = x;
        } else
            break;
    }
    rep(i, 1, n){
        if(del[i]){
            s.erase(i);
        }
    }
    rep(i, K + 1, n){
        if(Ans[i]) continue;
        if(*s.begin() <= i - K){
            Ans[i] = *s.begin();
            s.erase(s.begin());
        } else{
            it = s.lower_bound(i + K);
            Ans[i] = *it;
            s.erase(it);
        }
    }
    rep(i, 1, n) printf("%d ", Ans[i]);
	return 0;
}