//ID: LRL52  Date: 2022.8.11
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define dwn(i, a, b) for(int i = (a); i >= (b); --i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const double Eps = 1e-8;
int n;
double a[N][N];

//#undef int
int main()
{
//#define int long long
    //freopen("read.txt","r",stdin);
    scanf("%d",&n);
    rep(i,1,n){
    	rep(j,1,n+1){
    		scanf("%lf",&a[i][j]);
        }
    }
    rep(i,1,n){
        int r=i;
        rep(j,i+1,n){
            if(fabs(a[j][i])>fabs(a[r][i]))r=j;
        }
        if(fabs(a[r][i])<Eps){
            puts("No Solution");
            return 0;
        }
        if(r!=i)swap(a[i],a[r]);
        rep(j,i+1,n){
            double div=a[j][i]/a[i][i];
            rep(k,i,n+1){
                a[j][k]-=div*a[i][k];
            }
        }
    }
    dwn(i,n,1){
        rep(j,i+1,n){
            a[i][n+1]-=a[j][n+1]*a[i][j];
        }
        a[i][n+1]/=a[i][i];
    }
    rep(i,1,n)printf("%.10lf\n",a[i][n+1]);
    //printf("\n内存消耗：%.3f M",(double)sizeof(a)/(1<<20));
    return 0;
}
