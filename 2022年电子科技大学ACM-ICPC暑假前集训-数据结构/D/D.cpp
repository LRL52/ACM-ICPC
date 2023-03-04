//ID: LRL52  Date: 2022.4.26
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
vector<int> a;

int main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	int op, x, pos; rd(n);
	rep(i, 1, n){
		rd(op), rd(x);
		switch (op) {
			case 1: a.insert(lower_bound(a.begin(), a.end(), x), x); break;
			case 2: a.erase(lower_bound(a.begin(), a.end(), x)); break;
			case 3: printf("%d\n", lower_bound(a.begin(), a.end(), x) - a.begin() + 1); break;
			case 4: printf("%d\n", a[x - 1]); break;
			case 5: 
				pos = lower_bound(a.begin(), a.end(), x) - a.begin() - 1;
				if(pos >= 0) printf("%d\n", a[pos]);
				else puts("NOT FOUND"); break;
			case 6:
				pos = upper_bound(a.begin(), a.end(), x) - a.begin();
				if(pos < a.size()) printf("%d\n", a[pos]);
				else puts("NOT FOUND"); break;
			default: break;
		}
	}
	return 0;
}