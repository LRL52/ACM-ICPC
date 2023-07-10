/*** 
 * @Author: LRL52
 * @Date: 2023-04-27 23:08:37
 * @LastEditTime: 2023-04-27 23:08:37
 */
const int N=1e7+5;

int prime[N],pn,mi[N];
bool vis[N];
void init(int n){
    for (int i=2;i<=n;i++){
        if (!vis[i]) prime[++pn]=i,mi[i]=i;
        for (int j=1;j<=pn&&i*prime[j]<=n;j++) {
            vis[i*prime[j]]=true;
            mi[i*prime[j]]=prime[j];
            if (i%prime[j]==0) break;
        }
    }
}

void solve(){
    int n;
    read(n);
    map<int,LL> mp;
    LL cnt=0;
    for (int i=1;i<=n;i++){
        int x;
        read(x);
        while (x!=1){
            ++mp[mi[x]];
            ++cnt;
            x/=mi[x];
        }
    }
    LL ans=0;
    for (auto [x,y]:mp){
        ans+=1ll*y/2;
        cnt-=1ll*(y/2)*2;
    }
    ans+=cnt/3;
    printf("%lld\n",ans);
}

signed main(){
    //IOS;
    init(1e7);
    int ttt=1;
    read(ttt);
    while (ttt--) solve();
    return 0;
}
