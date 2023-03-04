#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
/*#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif*/
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,q,i,j,k,p,a[7][100005],pos[7][100005];
int f[19][100005][7],g[7],ng[7];
int main()
{
    scanf("%d%d",&n,&m);fz1(i,m)fz1(j,n){scanf("%d",&a[i][j]);pos[i][a[i][j]]=j;}
	fz1(i,m){
		fz1(j,n) f[0][j][i]=pos[i][j];
		fz1(j,m){
			int mi=n+1;
			fd1(k,n){
				mi=min(mi,pos[i][a[j][k]]);
				f[0][a[j][k]][i]=min(f[0][a[j][k]][i],mi);
			}
		}
	}
	fz1(k,18){
		fz1(i,n)fz1(j,m){
			f[k][i][j]=f[k-1][i][j];
			fz1(p,m){
				f[k][i][j]=min(f[k][i][j],f[k-1][a[p][f[k-1][i][p]]][j]);
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		fz1(i,m){
			g[i]=pos[i][x];
			if(g[i]<=pos[i][y]){
			    puts("1");break;
			}
		}
		if(i<=m) continue;
		int ans=2;
		fd0g(k,18){
			fz1(i,m){
				ng[i]=g[i];
				fz1(j,m){
					ng[i]=min(ng[i],f[k][a[j][g[j]]][i]);
				}
				if(ng[i]<=pos[i][y]) break;
			}
			if(i>m){
				ans+=(1<<k);
				fz1(i,m) g[i]=ng[i];
			}
		}
		if(ans==524289) puts("-1"); else printf("%d\n",ans);
	}
	return 0;
}
