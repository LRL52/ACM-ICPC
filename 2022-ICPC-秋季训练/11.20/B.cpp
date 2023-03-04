#include <bits/stdc++.h>
#define vc vector
#define pb push_back
#define LL long long
using namespace std;




void solve(){
    double x,y,p;cin>>x>>y>>p;
    if(x<p*y){
        printf("%.10lf\n",x/(p*y));
    }
    else{
        double ans=1.0;
        printf("%.10lf\n",ans);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ttt;cin>>ttt;
    while (ttt--) solve();
    return 0;
}
