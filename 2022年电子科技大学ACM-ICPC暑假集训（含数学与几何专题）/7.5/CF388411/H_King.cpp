//ID: LRL52  Date: 2022.7.5
//这题主要运用到一个长度 >= n/2 的子序列的性质：子序列相邻中两个元素的距离 <= 2 的元素对数 >= n/4 - 1
//利用这个性质 + map 就可以找出所有可能的q
//对于每个q，最后再用map辅助DP一下求出答案
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 200055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, P;
int a[N];
map<int, int> H, F;
int ksm(int a, int k){
    int ret = 1;
    while(k){
        if(k & 1) ret = ret * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return ret;
}

int Inv(int x){
    return ksm(x, P - 2);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
        rd(n), rd(P);
        rep(i, 1, n) rd(a[i]);
        H.clear();
        rep(i, 2, n){
            int q = a[i] * Inv(a[i - 1]) % P;
            ++H[q];
        }
        rep(i, 3, n){
            int q = a[i] * Inv(a[i - 2]) % P;
            ++H[q];
        }
        int ans = 0;
        for(map<int, int>::iterator it = H.begin(); it != H.end(); it++){
            int q = it->first, cnt = it->second;
            if(cnt >= n / 4 - 1){
                F.clear();
                rep(i, 1, n){
                    int x = a[i], lst = x * Inv(q) % P;
                    F[x] = max(F[x], F[lst] + 1);
                    ans = max(ans, F[x]);
                }
            }
        }
        int lower = n % 2 ? n / 2 + 1 : n / 2;
        if(ans >= lower) printf("%lld\n", ans);
        else puts("-1");
	}
	return 0;
}
