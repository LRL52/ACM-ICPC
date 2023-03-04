#include <bits/stdc++.h>
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
const int N=2e5+10, M=(1<<8), mo=1e9+7;
struct MI {
    int x; 
    MI(int x = 0) : x(norm_mo(x)) {}
    MI(long long x) : x(norm_mo(x % mo)) {}
    int norm_mo(int x) const { if (x < 0) {x += mo;} if (x >= mo) {x -= mo;} return x;}
    int val() const { return x;}
    friend MI operator^(const MI &lhs, const long long &rhs) { MI res=1, a=lhs; for (long long x=rhs; x; x >>= 1, a *= a) { if (x & 1) { res *= a; } } return res;  }
    MI operator-() const { return MI(norm_mo(mo - x));}
    MI inv() const { assert(x != 0);return (*this ^ (mo-2));}
    MI &operator*=(const MI &rhs) { x = (long long)x * rhs.x % mo; return *this;}
    MI &operator+=(const MI &rhs) { x = norm_mo(x + rhs.x); return *this;}
    MI &operator-=(const MI &rhs) { x = norm_mo(x - rhs.x); return *this;}
    MI &operator/=(const MI &rhs) { return *this *= rhs.inv();}
    bool operator==(const int &rhs) { return x == rhs;}
    bool operator!=(const int &rhs) { return x != rhs;}
    friend MI operator*(const MI &lhs, const MI &rhs) { MI res = lhs; res *= rhs; return res;}
    friend MI operator+(const MI &lhs, const MI &rhs) { MI res = lhs; res += rhs; return res;}
    friend MI operator-(const MI &lhs, const MI &rhs) { MI res = lhs; res -= rhs; return res;}
    friend MI operator/(const MI &lhs, const MI &rhs) { MI res = lhs; res /= rhs; return res; }
    friend std::istream &operator>>(std::istream &is, MI &a) { long long v; is >> v; a = MI(v); return is;}
    friend std::ostream &operator<<(std::ostream &os, const MI &a) { return os << a.val();}
}f[M][M];
int a[N];

signed main()
{
#ifdef LOCAL_DEFINE
   freopen("temp.in", "r", stdin);
#endif
    int n,d;

    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    cin>>n>>d;
    F(i,1,n){
        string s;
        cin>>s;
        DEB(s);
        F(j,0,d-1) a[i]=a[i]*2+s[j]-'0';
    }
    F(i,1,n){
        DEB(a[i]);
    }
    MI ans=0;
    F(i,1,n){
        int x=a[i]/256,y=a[i]%256;
        MI tmp=1;
        for(int j=0;j<M;j++){
            if((j&y)!=j) continue;
            tmp+=f[x][j];
        }
        ans+=tmp;
        for(int j=0;j<M;j++){
            if((j&x)!=x) continue;
            f[j][y]+=tmp;
        }
    }
    cout<<ans;
    return 0;
}