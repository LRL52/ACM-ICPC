//ID: LRL52  Date: 2022.7.12
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
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
map<long long, int> H;
int n;
char s[N][12];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%d", &n);
        H.clear();
        rep(i, 1, n){
            scanf("%s", s[i] + 1);
            int len = strlen(s[i] + 1);
            long long res = 0;
            for(int j = 1; j <= len; ++j){
                res = res * 27LL + (s[i][j] - 'a' + 1);
            }
            H[res] = 1;
        }
        rep(i, 1, n){
            int len = strlen(s[i] + 1), ok = 0;
            for(int j = 1; j < len; ++j){
                long long res1 = 0, res2 = 0;
                for(int k = 1; k <= j; ++k) res1 = res1 * 27LL + (s[i][k] - 'a' + 1);
                for(int k = j + 1; k <= len; ++k) res2 = res2 * 27LL + (s[i][k] - 'a' + 1);
                if(H[res1] && H[res2]){
                    ok = 1;
                    break;
                }
            }
            ok ? putchar('1') : putchar('0');
        }
        putchar('\n');
	}
	return 0;
}
