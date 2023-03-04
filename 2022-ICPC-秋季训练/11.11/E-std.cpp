#include<bits/stdc++.h>
#define ll int
#define LL long long
#define L(i,j,k) for(ll i=j;i<=k;++i)
#define R(i,j,k) for(ll i=j;i>=k;--i)
using namespace std;
const ll N=5e3+10,mod=1e9+7;
 
ll n,m,k,p,t,x,y,z,c;
LL ans;
ll a[60],b[60];
char sa[60][5],sb[60][5],sc[5];
 
ll cal(char ch){
	if(ch=='A')return 14;
	else if(ch=='K')return 13;
	else if(ch=='Q')return 12;
	else if(ch=='J')return 11;
	else if(ch=='T')return 10;
	else return (ch-'0');
}
 
void solve(){
	scanf("%d%d",&n,&m);
	L(i,1,n)scanf("%s",sa[i]),a[i]=cal(sa[i][0]);
	L(i,1,m)scanf("%s",sb[i]),b[i]=cal(sb[i][0]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	scanf("%s",sc);c=cal(sc[0]);
	int am,bm,amax,bmax;
	am=bm=amax=bmax=0;
	int a_maxmin=0;
	int ada=0;
	for(int i=1;i<=m;i++)   //求出bob小于c的个数
	{
		if(b[i]<c)
		{
			bm++;
		}
	}
	for(int i=1;i<=n;i++)	//alice大于等于c的个数
	{
		if(a[i]>=c)
		{
			ada++;
		}
		else
		{
			if(a[i]>a_maxmin)	//最大的小于C的数字
			{
				a_maxmin=a[i];
			}
		}
	}
	int flag=1;
	if(n==1||ada==n)
	{
		printf("Shou\n");
		return ;
	}
	if(bm>=2)
	{
		printf("Pang\n");
		return;
	}
	else if(bm==0)
	{
		printf("Shou\n");
		return ;
	}
	else
	{
	    if(m==1)	//B大为0 也就是没有大于等于c的牌
        {
            if(a_maxmin>=b[1])    ///存在大于等于m且 小于C
            {
                printf("Pang\n");
                return ;
            }
            else
            {
                printf("Shou\n");
                return ;
            }
        }
		if((n-ada)==1)    //a小为1
		{
            printf("Shou\n"); return ;
		}
		else         ///A小大于等于2个
		{
			if(b[m]>=a[n])	//有牌权
			{
				printf("Shou\n");
				return ;
			}
			else
			{
				if(a_maxmin>=b[1]&&n>3)
				{
					printf("Pang\n");
				}
				else
				{
					printf("Shou\n");
				}
			}
		}
	}
}
 
int main(){
	ll cas=1;
	scanf("%d",&cas);
	while(cas--)solve();
}