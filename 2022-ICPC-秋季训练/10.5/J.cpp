#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>
#define F(i, x, y) for (int i = x; i <= y; i++)
#define D(i, x, y) for (int i = x; i >= y; i--)
#define SZ(x) ((int)x.size())
#define mp make_pair

#ifdef LOCAL_DEFINE
#include "bits/debug.h"
#else
#define DEB(...)  
#endif

using namespace std;
using ll = long long;
using pii = pair<int, int>;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
bool jih,ouh;
const int N=1e5+5;
int dep[N];
vector<vector<int>> G;
void dfs(int u,int faa){
    dep[u]=dep[faa]+1;
    for(int v:G[u]){
        if(v==faa) continue;
        if(dep[v]){
            if(dep[u] %2 ==dep[v] %2 ) jih=true;
            else ouh=true;
        }
        else dfs(v,u);
    }
}
signed main()
{
#ifdef LOCAL_DEFINE
   freopen("temp.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    if(n<4){
        puts("-1");
        return 0;
    }
    DSU f(n+1);
    G.resize(n+1);
    F(i,1,m){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        f.merge(x,y);
    }
    vector<int> a;
    int md=0;
    F(i,1,n){
        if(f.leader(i) == i){
            if(f.size(i)>=3) a.push_back(i);
            md=max(md,f.size(i));
        }
    }
    if(SZ(a)==0){ //!!!!
        cout<<5-min(m,2)<<'\n';
        return 0;
    }
    
    jih=ouh=false;
    int ans=0;
    for(int i:a){
        dfs(i,i);
    }
    if(jih==false){
        ans++;
    }
    if(ouh==false){
        if(md==3) ans+=2;
        else ans+=1;
    }
    cout<<ans<<'\n';
    return 0;
}
