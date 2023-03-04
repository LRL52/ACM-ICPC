#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 2e5 + 55, MAXN = 100055;
char A[N], B[N];
int n, m, lim, p[N], h[N];

int main()
{
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
    fgets(A + 1, MAXN, stdin);
    fgets(B + 1, MAXN, stdin);
    scanf("%d", &lim);
    n = strlen(A + 1);
    m = strlen(B + 1);
    while(A[n] == '\n' || A[n] == '\r') --n;
    while(B[m] == '\n' || B[m] == '\r') --m;
    int j = 0;
    p[1] = 0;
    rep(i, 2, m)
    {
        while (j && B[j + 1] != B[i])
            j = p[j];
        if (B[j + 1] == B[i])
            ++j;
        p[i] = j;
    }
    j = 0;
    rep(i, 1, n)
    {
        while (j && A[i] != B[j + 1]){
            h[1]++, h[j + 1]--;
            j = p[j];
        }
        if (B[j + 1] == A[i])
            ++j;
        if (j == m)
        {
            //wr(i - m + 1);
            //++ans;
            //putchar('\n');
            h[1]++, h[j + 1]--;
            j = p[j];
        }
    }
    while(j){
        h[1]++, h[j + 1]--;
        j = p[j];
    }
    rep(i, 1, m) h[i] += h[i - 1];
    //rep(i, 1, m) printf("%d ", h[i]);
    //puts("");
    for(int i = m; i >= 1; --i){
        if(h[i] >= lim){
            for(int j = 1; j <= i; ++j) putchar(B[j]);
            return 0;
        }
    }
    puts("IMPOSSIBLE");
    // wr(ans);
    //rep(i, 1, m) wr(p[i]), putchar(' ');
    return 0;
}