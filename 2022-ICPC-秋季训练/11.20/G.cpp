#include <bits/stdc++.h>
#define vc vector
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define epb emplace_back
using namespace std;

const int N=1e6+5;
vc<pii> e[N];
char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x) {
    int f= 1; x = 0, cc = gc(); while(cc < '0' && cc > '9') {if(cc == '-') f = -1; cc = gc();}
    while(cc >= '0' && cc <= '9') {x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}

struct DSU{
    vc<int> fa,siz,mx;
    int n;
    DSU(int n):fa(n+1),n(n),siz(n+1),mx(n+1){
        for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1,mx[i]=i;
    }
    int findset(int x){
        if (fa[x]==x) return x;
        return fa[x]=findset(fa[x]);
    }
    void merge(int x,int y){
        x=findset(x);
        y=findset(y);
        if (x!=y){
            fa[x]=y;
            siz[y]+=siz[x];
            mx[y]=max(mx[x],mx[y]);
        }   
    }
};

void solve(){
    int n,t;//cin>>n>>t;
    rd(n),rd(t);
    DSU dsu(t+100);
    vc<int> vis(t+100);
    vc<int> x(t+1),y(t+1),cnt(t+100);
    for (int i=1;i<=t;i++){
        int a,b;rd(a),rd(b);
        if (a>b) swap(a,b);
        if (a>t) a=t+2;
        if (b>t) b=t+2;
        x[i]=a;
        y[i]=b;
        dsu.merge(a,b);
    }
    for (int i=1;i<=t;i++){
        int id=dsu.findset(x[i]);
        ++cnt[id];
    }
    for (int i=1;i<=t;i++){
        int id=dsu.findset(i);
        if (dsu.siz[id]<=cnt[id]||dsu.mx[id]!=i) vis[i]=1;//,cout<<i<<endl;
    }
    //cout<<dsu.mx[dsu.findset(5)];
    for (int i=1;;i++){
        if (!vis[i]){
            printf("%d\n",i);
            break;
        }
    }
}

int main(){
    freopen("G.in","r",stdin);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int ttt=1;
    while (ttt--) solve();
    return 0;
}
