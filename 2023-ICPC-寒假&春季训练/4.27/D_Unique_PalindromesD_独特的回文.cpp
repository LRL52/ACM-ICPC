/*** 
 * @Author: LRL52
 * @Date: 2023-04-28 00:32:28
 * @LastEditTime: 2023-04-28 00:37:45
 */
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;

char s[N];
char ss[]="abc";
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> x(k+1),c(k+1);
    for (int i=1;i<=k;i++) cin >> x[i];
    for (int i=1;i<=k;i++) cin >> c[i];
    // int cnt=0;
    s[1]='a';
    s[2]='b';
    s[3]='c';
    int d=0,id=0;
    char cur='c';
    x[0]=3,c[0]=3;
    int idx=3;
    for (int i=1;i<=k;i++){
        if (x[i]-c[i]<d){
            puts("NO");
            return;
        }
        int mor=c[i]-c[i-1];
        int lst=x[i]-x[i-1]-mor;
        for (int j=0;j<lst;j++){
            s[++idx]=ss[id];
            ++id;
            id%=3;
        }
        ++cur;
        for (int j=0;j<mor;j++){
            s[++idx]=cur;
        }
        d=max(d,x[i]-c[i]);
    }
    puts("YES");
    for (int i=1;i<=n;i++) putchar(s[i]);
    puts("");
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}