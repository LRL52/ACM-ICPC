#include <bits/stdc++.h>
#define vc vector
#define pb push_back
#define LL long long
using namespace std;
const int M=1e9+7;

LL fpm(LL b,LL p){
    LL ans=1;
    while (p){
        if (p&1) ans=(ans*b)%M;
        p>>=1;
        b=(b*b)%M;
    }
    return ans;
}

LL inv(LL x){return fpm(x,M-2);}

void solve(){
    LL n,k;cin>>n>>k;
    vc<LL> dp(k+10);
    LL sum=0;
    for (int i=2;i<=k+1;i++){
        dp[i]=((sum+i-1)%M)*inv(i-1)%M;
        //cout<<"sum:"<<sum+i-1<<endl;
        //cout<<i-1<<endl;
        //cout<<"i:"<<dp[i]<<endl;
        sum=(sum+dp[i])%M;
    }
    LL ans=dp[k+1]*n%M;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ttt;cin>>ttt;
    while (ttt--) solve();
    return 0;
}
