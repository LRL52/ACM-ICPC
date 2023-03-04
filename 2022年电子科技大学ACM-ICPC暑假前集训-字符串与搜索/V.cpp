#define debug printf("Passing [%s] in Line %d ...\n",__FUNCTION__,__LINE__)
#define ri register int
#define ll long long
#define ci const int&
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define dwn(i,a,b) for(register int i=(a);i>=(b);--i)
#define ee(i,a) for(register int i=head[a];i;i=e[i].nxt)
#include<bits/stdc++.h>
using namespace std;
const int N=1055;
const int M=2055;
const int inf=0x3f3f3f3f;
char ss[1<<21],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<21,stdin),A==B)?EOF:*A++;}
template<class T>void rd(T&x){
    ri f=1;char c=gc();x=0;while(c<48||c>57){if(c=='-')f=-1;c=gc();};
    while(c>47&&c<58){x=(x<<3)+(x<<1)+(c^48);c=gc();}x*=f;
}
#define int long long
int V,vm[N],ans=LONG_LONG_MAX/2-55,h[N],r[N],sm[N],n;
void dfs(int dep,int v,int s){
	if(dep==0){
		if(v==V)ans=min(s,ans);
		//if(ans==65LL){
		//	debug;
		//}
		//debug;
		//printf("%lld\n",s);
		return;
	}
	if(v+vm[dep]>V||s+sm[dep]>ans)return;//剪枝3,4 
	for(ri R=min(r[dep+1]-1,(ll)sqrt(V-v));R>=dep;--R){//枚举范围剪枝1，2+倒序搜索优化 
		for(ri H=min(h[dep+1]-1,(V-v)/(R*R));H>=dep;--H){
			if(dep==n)s=R*R; 
			r[dep]=R;h[dep]=H;
			if((2LL*(V-v)/r[dep])+s>ans)return;//剪枝5
			if(v+R*R*H<=V)dfs(dep-1,v+R*R*H,s+2LL*R*H);
		}
	}
}
#undef int
int main()
{
#define int long long
#ifdef LRL52
    freopen("V.in", "r", stdin);
#endif
    rd(V),rd(n);
    //预处理
	r[n+1]=100LL;h[n+1]=10000LL;
	rep(i,1,n){
		vm[i]=vm[i-1]+i*i*i;
		sm[i]=sm[i-1]+2LL*i*i;
	}
	dfs(n,0LL,0LL);
	if(ans != LONG_LONG_MAX/2-55) printf("%lld",ans); 
    else puts("0");
    return 0;
}