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

int sa[105],sb[105];
int s[105];
int tmp[105];
void reverse(int *x,int len){
    for (int i=1;i<=len;i++) tmp[i]=x[i];
    for (int i=1;i<=len;i++) x[i]=tmp[len-i+1];
}

void solve(){
    LL a,b;
    read(a),read(b);
    vc<int> cnta(10),cntb(10);
    int n=0,m=0;
    LL aa=a;
    LL ma=a/gcd(a,b);
    LL mb=b/gcd(a,b);
    while (aa){
        sa[++n]=aa%10;
        cnta[aa%10]++;
        aa/=10;
    }
    reverse(sa,n);
    LL bb=b;
    while (bb){
        sb[++m]=bb%10;
        cntb[bb%10]++;
        bb/=10;
    }
    reverse(sb,m);
    LL ans=a;
    for (int st=1;st<(1<<n);st++){
        LL p=0;
        vc<int> del(10);
        for (int i=1;i<=n;i++){
            if ((st>>(i-1))&1){
                p*=10;
                p+=sa[i];
            }else ++del[sa[i]];
        }
        if (p%ma) continue;
        if (!p) continue;
        LL q=mb*(p/ma);
        vc<int> chos(10);
        int tot=0;
        while (q){
            chos[q%10]++;
            s[++tot]=q%10;
            q/=10;
        }
        reverse(s,tot);
        bool fd=false;
        for (int i=0;i<10;i++){
            if (i==0){
                if (del[i]+chos[i]>cntb[i]) fd=true;
                continue;
            }
            if (del[i]+chos[i]!=cntb[i]){
                fd=true;
            }
        }
        if (fd) continue;
        int ned0=cntb[0]-del[0]-chos[0];
        int ed=0,num=0;
        for (int i=m;i>=1;i--){
            if (tot&&s[tot]==sb[i]) --tot;
            if (!tot){
                ed=i;
                break;
            }
        }
        if (tot) continue;
        bool flag=false;
        for (int i=1;i<=ed;i++){
            if (sb[i]==0) ++num;
            if (sb[i]==s[1]){
                if (num==ned0) flag=true;
            }
        }
        if (flag) ans=min(ans,p);
    }
    printf("%lld %lld\n",ans,mb*(ans/ma));
}

signed main(){
    //IOS;
    int ttt=1;
    read(ttt);
    while (ttt--) solve();
    return 0;
}
