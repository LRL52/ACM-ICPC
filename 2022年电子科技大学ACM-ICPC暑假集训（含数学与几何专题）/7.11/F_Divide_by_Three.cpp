//ID: LRL52  Date: 2022.7.11
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <assert.h>
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
const int inf = 0x3f3f3f3f;
int f[N][3][2], del[N][3][2], Del[N];
char s[N];
struct Node{
    int i, j, k;
}pre[N][3][2];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%s", s + 1);
    int n = strlen(s + 1);
    memset(f, 0x3f, sizeof(f));
    f[0][0][0] = 0; int cnt0 = 0;
    rep(i, 1, n){
        cnt0 += s[i] == '0';
        for(int k = 0; k < 3; ++k){
            if(f[i - 1][k][0] + 1 < f[i][k][0]){
                f[i][k][0] = f[i - 1][k][0] + 1;
                pre[i][k][0] = (Node){i - 1, k, 0};
                del[i][k][0] = 1;
            }
            if(f[i - 1][k][1] + 1 < f[i][k][1]){
                f[i][k][1] = f[i - 1][k][1] + 1;
                pre[i][k][1] = (Node){i - 1, k, 1};
                del[i][k][1] = 1;
            }
            int res = f[i - 1][k][1], x = s[i] - '0', flag = 0;
            if(x != 0 || i == n){
                if(f[i - 1][k][0] < res){
                    res = f[i - 1][k][0];
                    flag = 1;
                }
            }
            if(res < f[i][(k + x) % 3][1]){
                f[i][(k + x) % 3][1] = res;
                pre[i][(k + x) % 3][1] = flag ? (Node){i - 1, k, 0} : (Node){i - 1, k, 1};
                del[i][(k + x) % 3][1] = 0;
            }
        }
    }
    int ans = f[n][0][1];
    if(ans < inf){
        int i = n, j = 0, k = 1;
        Del[i] = del[i][j][k];
        while(pre[i][j][k].i != 0){
            Node v = pre[i][j][k];
            i = v.i, j = v.j, k = v.k;
            Del[i] = del[i][j][k];
        }
        int cnt = 0;
        rep(i, 1, n)
            if(Del[i] == 0)
                putchar(s[i]);
            else
                ++cnt;
        assert(cnt == ans);
    } 
    else if(cnt0 > 0) puts("0");
    else puts("-1");
	return 0;
}
