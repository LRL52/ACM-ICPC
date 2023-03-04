#include <bits/stdc++.h>
#define LL long long
using namespace std;


int main(){
    srand(time(0));
    freopen("G.in","w",stdout);
    int n=1e9,t=1e6;
    printf("%d %d\n",n,t);
    for (int i=1;i<=t;i++){
//        LL x=(rand()*rand())%t+1;
//        LL y=(rand()*rand())%t+1;
        printf("%lld %lld\n",i,i+1);
    }
    return 0;
}
