//ID: LRL52  Date: 2022.5.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5055;
int n, m;
char A[N], B[N];
int f[N][N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    int x, y, z;
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &z);
    scanf("%s%s", A + 1, B + 1);
    if(A[1] == B[1]) f[1][1] = x - y - z;
    else f[1][1] = -y - z;
    int ans = f[1][1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i == 1 && j == 1) continue;
            if(i > 1) f[i][j] = max(f[i][j], f[i - 1][j] - y);
            if(j > 1) f[i][j] = max(f[i][j], f[i][j - 1] - z);
            f[i][j] = max(f[i][j], -y - z);
            if(A[i] == B[j]){
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + x - y - z);
                f[i][j] = max(f[i][j], x - y - z);
            }
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
	return 0;
}