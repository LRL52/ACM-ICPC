//#pragma GCC optimize(2)
//#pragma GCC optimize("Ofast","inline","-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<iostream>
#include<cstdio>
#include<string>
#include<ctime>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<cassert>
#include<bitset>
#include<unordered_map>
using namespace std;
      
typedef long long LL;
      
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f;
    
const int N=1e3+100;
 
const int mod=1e9+7;
 
LL dp[35][2][2];//dp[pos][i<=x][j<=y]
 
int A[35],B[35];
 
LL dfs(int pos,int f1,int f2)
{
	if(pos==-1)
		return 1;
	if(dp[pos][f1][f2]!=-1)
		return dp[pos][f1][f2];
	int upa=f1?A[pos]:1;
	int upb=f2?B[pos]:1;
	LL ans=0;
	for(int i=0;i<=upa;i++)//枚举A 
		for(int j=0;j<=upb;j++)//枚举B
			if((i&j)==0)
				ans=(ans+dfs(pos-1,f1&&i==upa,f2&&j==upb))%mod;
	return dp[pos][f1][f2]=ans;
}
 
LL solve(int x,int y)
{
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(dp,-1,sizeof(dp));
	int cnt1=0,cnt2=0;//highbit
	int xx=x,yy=y;
	while(xx)
	{
		A[cnt1++]=xx&1;
		xx>>=1;
	}
	while(yy)
	{
		B[cnt2++]=yy&1;
		yy>>=1;
	}
	LL ans=0;
	for(int i=0;i<max(cnt1,cnt2);i++)
	{
		LL res=0;
		if(i<cnt1)//第i位x为1,y为0 
			res+=dfs(i-1,i==cnt1-1,i>=cnt2);
		if(i<cnt2)//第i为y为1,x为0 
			res+=dfs(i-1,i>=cnt1,i==cnt2-1);
		ans=(ans+res*(i+1))%mod;
	}
	return ans;
}
 
int main()
{
#ifndef ONLINE_JUDGE
//  freopen("data.in.txt","r",stdin);
//  freopen("data.out.txt","w",stdout);
#endif
//	ios::sync_with_stdio(false);
	int w;
	cin>>w;
	while(w--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",solve(x,y));
	}
 
 
 
 
 
 
 
 
 
 
 
 
 
   return 0;
}