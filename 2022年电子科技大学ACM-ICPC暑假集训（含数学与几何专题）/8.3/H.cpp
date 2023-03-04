#include<bits/stdc++.h>
#define gcd(a,b) __gcd(a,b)
#define debug(x) cout<<#x<<'='<<(x)<<endl
#define setp setiosflags(ios::fixed)<<setprecision
#define IOS ios_base::sync_with_stdio(false),cin.tie(0)
#define LL long long
#define pii pair<int,int>
#define vc vector
#define pb push_back
#define epb emplace_back
#define epf emplace_front
#define ep emplace
#define fi first
#define se second
//#define double long double
#define int long long
//#define int unsigned long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const int N=1e6+5;
//const int M=1e9+7;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3fll;
const double pi=acos(-1.0);

template<typename T>
void read(T &x)
{
    T a=0;T d=1;char c;
    while (c=getchar(),c<'0'||c>'9') if (c=='-') d=-1;a=a*10+c-48;
    while (c=getchar(),c>='0'&&c<='9') a=a*10+c-48;a*=d;
    x=a;
}

struct DSU{
    vc<int> fa;
    int n;
    DSU(int n):fa(n+1),n(n){
        for (int i=1;i<=n;i++) fa[i]=i;
    }
    int findset(int x){
        if (fa[x]==x) return x;
        return fa[x]=findset(fa[x]);
    }
    void merge(int x,int y){
        x=findset(x);
        y=findset(y);
        if (x!=y) fa[x]=y;
    }
    bool judge(int x,int y){return findset(x)==findset(y);}
};

struct Graph{
    vc<vc<int>> e;
    int n;
    Graph(int n):e(n+1),n(n){}
    void add(int u,int v){
        e[u].pb(v);
        e[v].pb(u);
    }
};

void solve()
{
    int n,m,q;
    read(n),read(m),read(q);
    vc<tuple<int,int,int>> edge;
    vc<int> a(2*n);
    for (int i=1;i<=n;i++) read(a[i]);
    for (int i=1;i<=m;i++){
        int x,y,z;
        read(x),read(y),read(z);
        edge.epb(x,y,z);
    }
    auto cmp=[] (tuple<int,int,int> x,tuple<int,int,int> y)->bool{
        return get<2>(x)<get<2>(y);
    };
    sort(edge.begin(),edge.end(),cmp);
    Graph G(2*n-1);
    int cnt=n;
    DSU dsu(2*n-1);
    vc<int> w(2*n);
    vc<vc<int>> fa(2*n+1,vc<int>(30));
    for (auto [x,y,z]:edge){
        x=dsu.findset(x);
        y=dsu.findset(y);
        if (x==y) continue;
        ++cnt;
        dsu.fa[x]=cnt;
        dsu.fa[y]=cnt;
        fa[x][0]=cnt;
        fa[y][0]=cnt;
        w[cnt]=z;
        G.add(x,cnt);
        G.add(y,cnt);
        dsu.merge(x,y);
    }
    n=2*n-1;
    vc<vc<LL>> dp(n+1,vc<LL>(30,1e18));
    vc<LL> siz(n+1),dep(n+1);
    function<void(int,int)> dfs=[&] (int u,int f){
        siz[u]+=a[u];
        dep[u]=dep[f]+1;
        for (auto v:G.e[u]){
            if (v==f) continue;
            dfs(v,u);
            siz[u]+=siz[v];
        }
    };dfs(n,0);
    vc<int> lg(n+1);lg[0]=-1;
    for (int i=1;i<=n;i++){
        dp[i][0]=w[fa[i][0]]-siz[i];
        lg[i]=lg[i>>1]+1;
    }
    function<void(int,int)> dfs1=[&] (int u,int f){
        for (int i=1;i<=lg[dep[u]];i++){
            fa[u][i]=fa[fa[u][i-1]][i-1];
            dp[u][i]=max(dp[u][i-1],dp[fa[u][i-1]][i-1]);
        }
        for (auto v:G.e[u]){
            if (v==f) continue;
            dfs1(v,u);
        }
    };dfs1(n,0);
    while (q--){
        int x,k;
        read(x),read(k);
        for (int i=lg[dep[x]];~i;i--){
            if (dp[x][i]<=k){
                x=fa[x][i];
            }
        }
        LL ans=k+siz[x];
        printf("%lld\n",ans);
    }
}

signed main()
{
    //IOS;
    int ttt=1;
    //read(ttt);
    while (ttt--)
        solve();
    return 0;
}
