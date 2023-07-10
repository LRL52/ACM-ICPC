/*** 
 * @Author: LRL52
 * @Date: 2023-05-08 20:21:34
 * @LastEditTime: 2023-05-09 10:04:00
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fo(x,a,b) for(int x=a;x<=b;x++)
#define of(x,a,b) for(int x=a;x>=b;x--)
#define close(); std::ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
#define PI acos(-1)
#define pb push_back
#define lowbit(a) ((a)&-(a))
#define lbit(a) (__builtin_ffsll(a))
#define ubit(a) (64-__builtin_clzll(a))
#define fi first
#define se second
//lowbit 10100获取100 lbit 3  ubit  5
//lower_bound(begin,end,num)返回从begin开始的第一个大于或等于val的元素的地址
//upper_bound(begin,end,num)
//__builtin_popcountll(x) 返回二进制中1的个数
//vector<vector<int>>G;//G.resize(m, vector<int>(n, 0)); 开辟一个n行m列的数组
//unordered_map 哈希map
const long long mod=1e9+7;
const long long INF=998244353;
long long wxd=1e18;
int mov[8][2]={0,1,0,-1,1,0,-1,0,-1,-1,-1,1,1,-1,1,1};
int qpow(int a,int b){
    int ans=1;
    while(b)
    {
        if(b%2==1) ans=ans*a%mod;//每部取模防止数据溢出
        a=(a*a)%mod;//每部取模防止数据溢出
        b=b/2;
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n*m+1);
    fo(i,1,n*m){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    int mx=n*m;
    // cout<<a[n*m]<<endl;
    // cout<<(a[mx]-a[1])*(n-1)<<" "<<(a[mx]-a[2])*(m-1)<<" "<<(a[mx]-a[1])*(n*m-n-m+1)<<endl;
    int ans1=(a[mx]-a[1])*(n-1)+(a[mx]-a[2])*(m-1)+(a[mx]-a[1])*(n*m-n-m+1);
    int ans2=(a[mx]-a[1])*(m-1)+(a[mx]-a[2])*(n-1)+(a[mx]-a[1])*(n*m-n-m+1);
    int ans3=(a[mx]-a[1])*(n-1)+(a[mx-1]-a[1])*(m-1)+(a[mx]-a[1])*(n*m-n-m+1);
    int ans4=(a[mx]-a[1])*(m-1)+(a[mx-1]-a[1])*(n-1)+(a[mx]-a[1])*(n*m-n-m+1);
    cout<<max({ans1,ans2,ans3,ans4})<<endl;
}
signed main()
{
    close();
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
//freopen("in.in", "r", stdin);
//freopen("out.out", "w", stdout);
	cin >> n >> m;
        int t = n * m;
        for (int i = 1; i <= t; ++i) cin >> a[i];
        sort(a + 1, a + t + 1);
        int d1 = a[t] - a[1], d2 = max(a[t] - a[2], a[t - 1] - a[1]);
        int l = min(n, m);
        int res = n * m - l;
        i64 ans = d1 * res + d2 * l - d1;
        cout << ans << '\n';