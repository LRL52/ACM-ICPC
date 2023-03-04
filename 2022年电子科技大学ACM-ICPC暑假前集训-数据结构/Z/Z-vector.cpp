//ID: LRL52  Date: 2022.4.21
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
vector<int> a;

int main() {
#ifdef LRL52
	freopen("O.in", "r", stdin);
#endif
	rd(n), rd(m); int x;
    rep(i, 1, n){
        rd(x);
        a.push_back(x);
    }
    int op, k, pos;
    rep(i, 1, m){
        rd(op);
        if(op == 1){
            rd(k), rd(pos);
            if(pos > a.size()) a.push_back(k);
            else a.insert(a.begin() + pos - 1, k);
        }
        else{
            rd(pos);
            printf("%d\n", a[pos - 1]);
        }
    }
	return 0;
}