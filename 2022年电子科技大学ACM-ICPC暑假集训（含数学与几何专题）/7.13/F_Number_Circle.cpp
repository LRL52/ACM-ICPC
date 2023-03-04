//ID: LRL52  Date: 2022.7.13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int a[N];
vector<int> b1, b2;

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n) rd(a[i]);
    sort(a + 1, a + n + 1);
    if(a[n - 2] + a[n - 1] <= a[n]){
        puts("NO");
        return 0;
    }
    rep(i, 1, n){
        if(i & 1) b1.push_back(a[i]);
        else b2.push_back(a[i]);
    }
    puts("YES");
    for(int i = 0; i < b1.size(); ++i) printf("%d ", b1[i]);
    for(int i = (int)b2.size() - 1; i >= 0; --i) printf("%d ", b2[i]);
	return 0;
}
