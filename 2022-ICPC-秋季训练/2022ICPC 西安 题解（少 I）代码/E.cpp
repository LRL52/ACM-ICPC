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
typedef long long i64;
typedef long double f80;
typedef unsigned int u32;
typedef unsigned long long u64;
//typedef __int128 i128;
//typedef unsigned __int128 u128;
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
inline void read(i64 &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int tt,f[65][2][2][2],i;
vector<int> vl,vr;
i64 l,r;
int main()
{
	read(tt);
	while(tt--){
		read(l);read(r);vl.clear();vr.clear();
		while(l||r){
			vl.push_back(l%3);
			vr.push_back(r%3);
			l/=3;r/=3;
		}
		memset(f,-0x3f,sizeof(f));
		f[vr.size()][0][1][1]=0;
		for(int i=vr.size()-1;i>=0;i--){
			int t,l,r,c;
			fz0k(t,2)fz0k(l,2)fz0k(r,2)if(f[i+1][t][l][r]>=0){
				int fi=(l?vl[i]:0);
				int ed=(r?vr[i]:2);
				fz(c,fi,ed){
					int nt=(t||!!c);
					int nl=(l&&fi==c);
					int nr=(r&&ed==c);
					f[i][nt][nl][nr]=max(f[i][nt][nl][nr],f[i+1][t][l][r]+nt+c);
				}
			}
		}
		int ans=0,t,l,r;
		fz0k(t,2)fz0k(l,2)fz0k(r,2) ans=max(ans,f[0][t][l][r]);
		printf("%d\n",ans);
	}
	return 0;
}
