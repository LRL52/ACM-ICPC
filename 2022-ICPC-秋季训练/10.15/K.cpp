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
//const int N=1e6+5;
//const int M=1e9+7;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3fll;
const double pi=acos(-1.0);

template<typename T>
void read(T &x){
    T a=0;T d=1;char c;
    while (c=getchar(),c<'0'||c>'9') if (c=='-') d=-1;a=a*10+c-48;
    while (c=getchar(),c>='0'&&c<='9') a=a*10+c-48;a*=d;
    x=a;
}

void solve(){
    int n,k;
    read(n),read(k);
    vc<int> a(n+1);
    for (int i=1;i<=n;i++) read(a[i]);
    sort(++a.begin(),a.end());
    if (k==0){
        LL tot=0;
        for (int i=1;i<=n;i++) tot+=a[i];
        if (tot&1) puts("0");
        else puts("1");
        return;
    }
    vc<pii> lim(k+1);
    lim[0].fi=-1,lim[0].se=0;
    for (int i=1;i<=k;i++) read(lim[i].fi),read(lim[i].se);
    lim.epb(1e9+1,0);
    ++k;
    sort(++lim.begin(),lim.end());
    LL tot=0;
    vc<int> x,y,d;
    auto cal=[&] (int mi,int w){
        if (d.size()==0) return;
        for (int i=0;i<d.size();i++) d[i]-=mi;
        vc<int> left(w+1,INF);
        for (int i=0;i<x.size();i++) left[x[i]-mi]=y[i];
        int j=0;
        for (auto x:d){
            tot+=x-j;
            --left[j];
            if (!left[j]) ++j;
        }
    };
    int j=1;
    for (int l=0,r;l<k;l=r+1){
        r=l;
        x.clear();
        y.clear();
        int cur=lim[l].fi+1;
        int mi=lim[l].fi+1;
        while (r+1<=k&&lim[r+1].se!=0){
            ++r;
            if (lim[r].fi==cur){
                ++cur;
                x.pb(lim[r].fi);
                y.pb(lim[r].se);
            }
        }
        int mx=lim[r+1].fi;
        d.clear();
        while (j<=n&&a[j]<=mx){
            d.pb(a[j]);
            ++j;
        }
        cal(mi,cur-lim[l].fi-1);
    }
    if (tot&1) puts("0");
    else puts("1");
}

signed main(){
    //IOS;
    int ttt=1;
    read(ttt);
    while (ttt--) solve();
    return 0;
}
