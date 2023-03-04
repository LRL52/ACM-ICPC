//ID: LRL52  Date: 2022.5.4
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, K;
int a[N];
multiset<int> s;
vector<int> b;

int main() {
#ifdef LRL52
	freopen("J.in", "r", stdin);
#endif
    rd(n), rd(K); int x;
    rep(i, 1, n) rd(x), s.insert(x);
    rep(i, 1, n) rd(a[i]);
    sort(a + 1, a + n + 1);
    long long ans = 0LL;
    for(int i = n; i >= 1; --i){
        multiset<int>::iterator it = s.lower_bound(a[i]);
        if(it != s.end()){
            ans += *it;
            b.push_back(*it - a[i]);
            s.erase(it);
        } else {
            if(K > 0){
                --K;
                ans += a[i];
            } else {
                puts("NIE");
                return 0;
            }
        }
    }
    sort(b.begin(), b.end(), greater<int>());
    for(int i = 0; K > 0 && i < b.size(); ++i, --K)
        ans -= b[i];
    printf("%lld\n", ans);
	return 0;
}