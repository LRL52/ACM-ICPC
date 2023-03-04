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

char s[505][505];
int cnt[505];
void solve()
{
    int n;
    read(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) s[i][j]='.';
    }
    if (n%3==0){
        int st=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<3;j++) s[i][j+st]='#';
            st=(st+3)%n;
        }
    }
    else if (n%3==1){
        int left=1;
        int len=(2*n+left)/3;
        int st=((n-n/3+1)%n+n)%n;
        for (int i=0;i<len;i++){
            for (int j=0;j<3;j++){
                s[i][(st+j)%n]='#';
                ++cnt[(st+j)%n];
            }
            st=(st+3)%n;
            if (left) --left,--st;
            st=(st%n+n)%n;
        }
        for (int i=len;i<n;i++){
            int cur=0;
            for (int j=0;j<n;j++){
                if (cnt[j]<3){
                    ++cur;
                    ++cnt[j];
                    s[i][j]='#';
                }
                if (cur==3) break;
            }
        }
    }
    else{
        int left=2;
        int len=(2*n+left)/3;
        int st=0;
        for (int i=0;i<len;i++){
            for (int j=0;j<3;j++){
                s[i][(st+j)%n]='#';
                ++cnt[(st+j)%n];
            }
            st=(st+3)%n;
            if (left) --left,--st;
        }
        for (int i=len;i<n;i++){
            int cur=0;
            for (int j=0;j<n;j++){
                if (cnt[j]<3){
                    ++cur;
                    ++cnt[j];
                    s[i][j]='#';
                }
                if (cur==3) break;
            }
        }

    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            putchar(s[i][j]);
        }
        puts("");
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
