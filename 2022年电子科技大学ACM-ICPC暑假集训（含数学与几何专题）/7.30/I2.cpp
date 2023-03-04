#include <bits/stdc++.h>
#define F(i, x, y) for (int i = x; i <= y; i++)
#define D(i, x, y) for (int i = x; i >= y; i--)
#define debug(a) cout<<#a<<"="<<a<<endl;
#define pr printf
#define SZ(x) ((int)x.size())
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define YN(ok) cout << (ok ? "YES" : "NO") << '\n';

using namespace std;

void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) { x=0;int ch=getchar(),f=0;while(ch<'0'||ch>'9') { if (ch=='-') f=1;ch=getchar();}while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}if(f)x=-x;read(oth...);}

const int N = 5010;
int f[N*5];
int main()
{
#ifdef LOCAL_DEFINE
   freopen("temp.in", "r", stdin);
#endif
    int _;

    scanf("%d\n",&_);
    int i=1;
    while(i<N){
        i+=4;
        f[i]=1;
        i+=4;
        f[i]=1;
        i+=6;
        f[i]=1;
        i+=6;
        f[i]=1;
    }
    while(_--)
    {
        int n;
        read(n);
        if(f[n]==0) puts("First");
        else puts("Second");
    }
    return 0;
}