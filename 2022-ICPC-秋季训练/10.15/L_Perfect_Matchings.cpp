#include<bits/stdc++.h>
#define vc vector
#define pb push_back
#define LL long long 

using namespace std;

const int N=2e5+5;
const int M=998244353;

LL dp[4005][4005][2];
LL fac[N],ifac[N];
int Size[N];


struct Graph{
	vc<vc<int>> e;
	int n;
	Graph(int n):e(n+1),n(n){}
	void add(int u,int v){
		e[u].pb(v);
	}
};

LL fpm(LL b,LL p){
	LL ans=1;
	while (p){
		if (p&1) ans=(ans*b)%M;
		p>>=1;
		b=(b*b)%M;
	}
	return ans;
}

LL inv(LL x){
	return fpm(x,M-2);
}

LL C(int n,int m){
	return fac[n]*ifac[m]%M*ifac[n-m]%M;
}

LL cal(int x){
	return C(x,x/2)*fac[x/2]%M*inv(fpm(2,x/2))%M;
}

signed main(){
	//ios_base::sync_with_stdio(false),cin.tie(0);
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=(fac[i-1]*i)%M;
	ifac[N-1]=inv(fac[N-1]);
	for (int i=N-2;~i;i--) ifac[i]=(ifac[i+1]*(i+1))%M;
	int n;scanf("%d",&n);
	n<<=1;
	Graph G(n);
	for (int i=1;i<n;i++){
		int u,v;scanf("%d %d",&u,&v);
		G.add(u,v);
		G.add(v,u);
	}
	function<void(int,int)> dfs=[&] (int u,int fa){
		dp[u][0][0] = dp[u][1][1] = Size[u] = 1;
		for (auto v:G.e[u]){
			if (v==fa) continue;
			dfs(v,u);
			
			/*for (int i=1;i<=n;i++){
				dp[u][i][1]=(dp[u][i][1]+dp[v][i-1][0])%M;
				dp[u][i][0]=(dp[u][i][0]+dp[v][i][1]+dp[v][i][0])%M;
			}*/
			for(int i = Size[u] + Size[v]; i >= 0; --i) {
				for(int k = max(1, i - Size[u]); k <= min(Size[v], i); ++k) {
					dp[u][i][0] += 1LL * dp[u][i - k][0] * dp[v][k][0] % M;
					dp[u][i][0] %= M;
					// dp[u][i + 1][1] = dp[u][i][0]; 
				}
			} 
			Size[u] += Size[v];
		}
		for(auto v : G.e[u]) {
			if(v == fa) continue;
			for(int i = Size[u]; i >= 0; --i) {
				for(int k = max(1, i - (Size[u] - Size[v])); k <= min(Size[v], i); ++k) {
					dp[u][i][0] += 1LL * dp[v][k][1] * dp[u][i - k + 1][1] % M;
					dp[u][i][0] %= M; 
				}
			} 
		}
		for (int i=0;i<=n;i++){
			printf("u:%d i:%d %lld %lld\n",u,i,dp[u][i][0],dp[u][i][1]);
		}
	};dfs(1,0);
	LL ans=cal(n);
	printf("ans:%lld\n",ans);
	for (int i=1;i<=n/2;i++){
		int num=(dp[1][i][0]+dp[1][i][1])%M;
		printf("i:%d num:%lld\n",i,num);
		if (i&1) ans=((ans-num*cal(n-i*2)%M)%M+M)%M;
		else ans=(ans+num*cal(n-i*2)%M)%M;
		printf("ans:%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}