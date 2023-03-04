//ID: LRL52  Date: 2022.10.6
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
using LL = long long;
int n, K;
int a[N];
pair<int, int> lim[N];

void modify(int p) {
    int lst = lim[p].first;
    rep(i, p + 1, K) {
        if(lim[i].second == 0) break;
        if(lim[i].first - lst > 1) {
            lim[i].first = lst + 1;
            lim[i].second = inf;
            break;
        }
        lst = lim[i].first;
    }
}

signed main() {
#ifdef LRL52
	freopen("K.in", "r", stdin);
#endif
	int Task; rd(Task);
    while(Task--) {
        rd(n), rd(K);
        rep(i, 1, n) rd(a[i]);
        rep(i, 1, K) rd(lim[i].first), rd(lim[i].second);
        lim[++K] = make_pair(-1, 0);
        sort(a + 1, a + n + 1);
        sort(lim + 1, lim + K + 1);
        vector<int> zero;
        rep(i, 1, K) {
            if(lim[i].second == 0) {
                //modify(i);
                zero.push_back(lim[i].first);
            }
        }
        lim[++K] = make_pair(inf, 0), zero.push_back(inf);       
        LL tot = 0;
        //if(!flag) lim[++K] = make_pair(lst + 1, inf);
        int p = 1;
        rep(i, 1, n) {
            // while(lim[p].second == 0) ++p;
            int t = *(--lower_bound(zero.begin(), zero.end(), a[i]));
            while(lim[p].first < t) ++p;
            while(lim[p].second == 0 && lim[p + 1].second != 0) ++p;
            if(lim[p].second > 0) {
                --lim[p].second;
                assert(a[i] >= lim[p].first);
                tot += a[i] - lim[p].first;
            } else {
                assert(a[i] >= (lim[p].first + 1));
                tot += a[i] - (lim[p].first + 1);
            }
        }
        printf("%lld\n", (tot & 1LL) ^ 1LL); 
    }
	return 0;
}