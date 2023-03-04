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
namespace mf
{
	int dis[505],tot,cst,s=0,t=501;
	struct ii
	{
		int y,z;
	}e[150005];
	vector<int>bi[505];
	void init()
	{
		int i;for(i=0;i<=t;i++)bi[i].clear();
		tot=0;
	}
	void add(int x,int y,int z)
	{
		tot++;
		bi[x].push_back(tot*2-2);
		bi[y].push_back(tot*2-1);
		e[tot*2-2]=(ii){y,z};
		e[tot*2-1]=(ii){x,0};
	}
	bool bfs(int s,int t)
	{
		queue<int> qx;memset(dis,0x3f,sizeof(dis));
		dis[s]=0;qx.push(s);
		while(!qx.empty()){
			int x=qx.front();qx.pop();
			ff(bi[x],it){
				if(e[*it].z&&dis[e[*it].y]>dis[x]+1){
					dis[e[*it].y]=dis[x]+1;
					qx.push(e[*it].y);
				}
			}
		}
		return dis[t]<dis[t+1];
	}
	int dfs(int x,int tt,int flw)
	{
		if(!flw||x==tt) return flw;
		int ans=0;
		ff(bi[x],it){
			if(e[*it].z&&dis[e[*it].y]==dis[x]+1){
				int t=dfs(e[*it].y,tt,min(flw,e[*it].z));
				flw-=t;ans+=t;e[*it].z-=t;e[(*it)^1].z+=t;
				if(!flw) return ans;
			} 
		}
		dis[x]=-1;
		return ans;
	}
	int dinic(int s,int t)
	{
		int ans=0;
		while(bfs(s,t)){
			ans+=dfs(s,t,0x3f3f3f3f);
		}
		return ans;
	}
}
int n,m,c,d,i,j,rem;
long long ans;
int main()
{
	read(n);read(m);read(c);read(d);
	fz1(i,n) mf::add(mf::s,i,0);
	fz1(i,m) mf::add(i+n,mf::t,0);
	fz1(i,n){
		fz1(j,m){
			char c;while((c=getchar())!='.'&&c!='*');
			if(c=='.') rem++,mf::add(i,j+n,1);
		}
	}
	ans=1ll*d*rem;int arg=0;
	fz1(i,max(n,m)){
		fz1(j,n+m) mf::e[j+j-2].z++;
		rem-=mf::dinic(mf::s,mf::t);
		long long tmp=1ll*d*rem+1ll*c*i;
		if(tmp<ans) ans=tmp,arg=i;
	}
	printf("%lld\n",ans);
//	cerr<<arg<<endl;
	return 0;
}
