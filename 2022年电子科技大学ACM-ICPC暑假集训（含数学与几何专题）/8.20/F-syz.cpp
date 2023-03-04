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
//#define int long long
//#define int unsigned long long
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//const int N=1e6+5;
//const int M=1e9+7;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3fll;
const double pi=acos(-1.0);

template<typename T>
void read(T &x){
    T a=0;T d=1;char c;
    while (c=getchar(),c<'0'||c>'9') if (c=='-') d=-1;a=a*10+c-48;
    while (c=getchar(),c>='0'&&c<='9') a=a*10+c-48;a*=d;
    x=a;
}

struct node{
    int d,idx,w;
    node(int d,int idx,int w):d(d),idx(idx),w(w){}
    bool operator > (const node &x)const{
        if (d==x.d){
            if (!d) return idx>x.idx;
            else return idx<x.idx;
        }else{
            return w<x.w;
        }
    }
    bool operator < (const node &x)const{
        if (d==x.d){
            if (!d) return idx<x.idx;
            else return idx>x.idx;
        }else{
            return w>x.w;
        }
    }
};

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
int vis[1005], order[1005];
void solve(){
    int n;
    read(n);
    vc<int> a(n+2),b(n+2);
    for (int i=1;i<=n;i++) read(b[i]);
    for (int i=1;i<=n;i++) read(a[i]);
    a[n+1]=INF,b[n+1]=INF;
    vc<int> d(n+1);
    int cur=0;
    int l=1,r=1;
    while (l<=n&&r<=n){
        if (a[l]<b[r]){
            if (cur>0) d[l]=0;
            else d[l]=1;
            ++l;
            --cur;
        }else{
            ++r;
            ++cur;
        }
    }
    LL ans=0;
    vc<int> id;
    priority_queue<node> q;
    for (int r=1;r<=n;r++){
        if (d[r-1]==1&&d[r]==0){
            while (!q.empty()){
                auto [_,idx,w]=q.top();
                q.pop();
                id.pb(idx);
                ans+=w;
            }
        }
        q.ep(d[r],r,abs(a[r]-b[r]));
    }
    while (!q.empty()){
        auto [_,idx,w]=q.top();
        q.pop();
        id.pb(idx);
        ans+=w;
    }
    printf("%lld\n",ans);
    bool f=false;
    int p = 0;
    for (auto x:id){
        order[++p] = x;
    }
    int ret = 0;
    rep(i, 1, n){
        int t = order[i];
        int d2 = 0x3f3f3f3f, idx = 0;
        rep(j, 1, n){
            if(vis[j]) continue;
            if(abs(b[j] - a[t]) < d2){
                d2 = abs(b[j] - a[t]);
                idx = j;
            }
        }
        printf("order[i] = %d idx = %d d = %d\n", t, idx, d2);
        ret += d2;
        vis[idx] = 1;
    }
    //puts("");
    if(ret != ans){
        printf("ret = %d\n", ret);
        puts("GG");
    }
}

signed main(){
    freopen("F.in", "r", stdin);
    freopen("F.out", "w", stdout);
    //IOS;
    int ttt=1;
    //read(ttt);
    while (ttt--) solve();
    return 0;
}
