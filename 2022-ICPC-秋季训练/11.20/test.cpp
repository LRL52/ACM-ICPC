#include <bits/stdc++.h>

using namespace std;


std::mt19937_64 rnd(time(0));
void solve(){
    double x,y,p;cin>>x>>y>>p;
    double x1=0,x2=0,v=0;
    for(int i=1;i<=100000;i++){
        x2+=y;
        int w=rnd()%(int)p;
        double t=min(v,y);
        x1+=t;
        v-=t;
        if(w==0){
            v=x;
        }
    }
    printf("%.10lf\n",x1/x2);
}

int main(){
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ttt;cin>>ttt;
    while (ttt--) solve();
    return 0;
}
