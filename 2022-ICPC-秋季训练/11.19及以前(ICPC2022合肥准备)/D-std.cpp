#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int _=1e2;
const int maxn=1e5+_;
const int fbin=(1<<17)+_;
const int mod=998244353;
inline int ad(int x,int y){return x>=mod-y?x-mod+y:x+y;}
inline int re(int x,int y){return x<y?x-y+mod:x-y;}
inline int mu(int x,int y){return (LL)x*y%mod;}
inline int qp(int x,LL y){int r=1;while(y){if(y&1)r=mu(r,x);x=mu(x,x);y>>=1;}return r;}
inline int iv(int x){return qp(x,mod-2);}
inline int dv(int x,int y){return mu(x,qp(y,mod-2));}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(LL d)
{
    if(d<0){putchar('-');d=-d;}
    if(d>=10)write(d/10);
    putchar(d%10+'0');
}

int main() 
{
    int n=100,m=165,k=1000000;
    printf("%d %d\n",n,m);
    for(int i=1;i+3<=n;i+=3)
    {
        printf("%d %d %d\n",i,i+1,1);
        printf("%d %d %d\n",i,i+2,k);
        printf("%d %d %d\n",i+1,i+2,1);
        printf("%d %d %d\n",i+2,i+3,1);
        printf("%d %d %d\n",i+1,i+3,max(1,k/2-1));
        k=max(1,k/2);
    }
    
    return 0; 
}