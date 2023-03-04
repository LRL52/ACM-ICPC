#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dwn(i,a,b) for(int i=(a);i<=(b);--i)
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5 + 55;char ss[1<<21],*A=ss,*B=ss,ch;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<21,stdin),A==B)?EOF:*A++;}
template<class T>void rd(T&x){
    int f=1;ch=gc();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=gc();}x*=f;
}
int maxs, zs, tt, n, cnt;
int pos[N], f[2005][2005], g[2005][2005], ls[N], rs[N], sum[N], v[N], a[N], b[N];
vector<int> xb[N];
struct cmp{
    inline bool operator()(const int &t1, const int &t2){
        return t1 < t2;
    }
};

void jd(int tot, int x){
    if(tot > maxs || (tot == maxs && x < zs))maxs = tot, zs = x;
}

void init(int x){
    memset(sum, 0, sizeof(sum));maxs = 0;
    rep(i, x, tt){
        rep(j, ls[i], rs[i]){
            ++sum[v[j]];
            jd(sum[v[j]],v[j]);
        }
        f[x][i] = zs;
        g[x][i] = maxs;
    }
}

int bsh(int x, int l, int r){
    int p1 = lower_bound(xb[x].begin(), xb[x].end(), l) - xb[x].begin();
    int p2 = lower_bound(xb[x].begin(), xb[x].end(), r) - xb[x].begin();
    if( p2 >= (int)xb[x].size() || xb[x][p2] > r)--p2;
    return p2 - p1 + 1;
}

int query(int l, int r){
    int p = pos[l], q = pos[r], times = 0; maxs = 0;
    if(p == q){
        rep(i, l, r){
            times = bsh(v[i], l, r);
            jd(times, v[i]);
        }
    }
    else{
        rep(i, l, rs[p]){
            times = bsh(v[i], l, r);
            jd(times, v[i]);
        }
        if(p + 1 <= q - 1)jd(g[p + 1][q - 1], f[p + 1][q - 1]);
        rep(i, ls[q], r){
            times = bsh(v[i], l, r);
            jd(times, v[i]);
        }
    }
    return zs;
}

int main()
{
    freopen("L.in", "r", stdin);
    rd(n);
    rep(i, 1, n)rd(a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1, cmp());
    cnt = unique(b + 1, b + n + 1) - b - 1;
    rep(i, 1, n)v[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    tt = sqrt(n * (log(n) / log(2)));
    int len = tt ? n / tt : n;
    if(n % tt) ++len;
    rep(i, 1, tt){
        ls[i] = (i - 1) * len + 1;
        rs[i] = i * len;
        if(rs[i] > n){
            tt = i;
            break;
        }
    }
    if(rs[tt] < n)++tt, ls[tt] = rs[tt-1] + 1, rs[tt] = n;
    if(rs[tt] > n) rs[tt] = n;
    rep(i, 1, tt){
        rep(j, ls[i], rs[i]){
            pos[j] = i;
        }
    }
    rep(i, 1 ,tt)init(i);
    rep(i, 1, n){
        xb[v[i]].push_back(i);
    }
    int l, r;
    rep(i, 1, n){
        rd(l), rd(r);
        printf("%d\n", b[query(l, r)]);
    }
    return 0;
}