//ID: LRL52  Date: 2022.7.12
//考场想复杂了，不过也比较创新，就是通过平移坐标系，再利用棣莫弗公式模拟旋转90度的过程
#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 105, M = 205; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int a[M][M], b[M][M];
char s[M];
#define b(i, j) b[i + 55][j + 55]

int main() {
#ifdef LRL52
	freopen("E.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%d", &n); int flag = 0;
        //printf("n = %d\n", n);
        /*if(n == 4){
            printf("qaq\n");
        }*/
        if((n&1) == 0) ++n, flag = 1; 
        int L = (n + 1) / 2;
        memset(a, 0, sizeof(a));
        rep(i, 1, n){
            if(i == L && flag) continue; //考场代码打反了
            scanf("%s", s + 1);
            for(int j = 1; j <= n; ++j){
                if(j == L && flag) continue;
                if(j > L && flag) a[i][j] = s[j - 1] - '0';
                else a[i][j] = s[j] - '0';
                //if(a[i][j]) puts("qaq");
            }
            //puts(s + 1);
        }
        memset(b, 0, sizeof(b));
        rep(i, 1, n){
            rep(j, 1, n){
                b(j - L, n - i + 1 - L) = a[i][j];
                //assert(j - L + 55 > 0 && n - i + 1 - L + 55> 0);
            }
        }
        int ans = 0;
        for(int i = 0; i < L; ++i){
            for(int j = 0; j < L; ++j){
                int x = i, y = j, cnt0 = 0, cnt1 = 0;
                //printf("%d", b(i, j));
                for(int k = 0; k < 4; ++k){
                    cnt0 += b(x, y) == 0;
                    cnt1 += b(x, y) == 1;
                    int nx = -y, ny = x;
                    x = nx, y = ny;
                    //assert(x + 55 > 0 && y + 55 > 0);
                }
                int dig = 0;
                if(cnt0 < cnt1) ans += 4 - cnt1, dig = 1;
                else ans += 4 - cnt0, dig = 0;
                x = i, y = j;
                for(int k = 0; k < 4; ++k){
                    b(x, y) = dig;
                    int nx = -y, ny = x;
                    x = nx, y = ny;
                }
            }
            //putchar('\n');
        }
        printf("%d\n", ans);
	}
	return 0;
}
