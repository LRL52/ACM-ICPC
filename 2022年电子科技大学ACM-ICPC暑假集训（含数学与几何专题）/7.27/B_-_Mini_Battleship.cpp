//ID: LRL52  Date: 2022.7.27
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 105, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int a[N][N], Ans = 0, K, n, L[N];
char s[N][N];

void dfs(int k){
    if(k > K){
        int ok = 1;
        rep(i, 1, n){
            rep(j, 1, n){
                if(s[i][j] == 'O' && a[i][j] == 0){
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        Ans += ok;
        return;
    }
    rep(i, 1, n){
        rep(j, 1, n){
            if(s[i][j] == 'X' || a[i][j]) continue;
            int ok = 1;
            for(int t = 1; t <= L[k]; ++t){
                int x = i, y = j + t - 1;
                if(x < 0 || x > n || y < 0 || y > n || s[x][y] == 'X' || a[x][y]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                for(int t = 1; t <= L[k]; ++t){
                    int x = i, y = j + t - 1;
                    a[x][y] = 1;
                }
                dfs(k + 1);
                for(int t = 1; t <= L[k]; ++t){
                    int x = i, y = j + t - 1;
                    a[x][y] = 0;
                }
            }
            if(L[k] == 1) continue;
            ok = 1;
            for(int t = 1; t <= L[k]; ++t){
                int x = i + t - 1, y = j;
                if(x < 0 || x > n || y < 0 || y > n || s[x][y] == 'X' || a[x][y]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                for(int t = 1; t <= L[k]; ++t){
                    int x = i + t - 1, y = j;
                    a[x][y] = 1;
                }
                dfs(k + 1);
                for(int t = 1; t <= L[k]; ++t){
                    int x = i + t - 1, y = j;
                    a[x][y] = 0;
                }
            }
        }
    }
}





signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d%d", &n, &K);
    rep(i, 1, n) scanf("%s", s[i] + 1);
    rep(i, 1, K) scanf("%d", &L[i]);
    dfs(1);
    printf("%d\n", Ans);
	return 0;
}