#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 55;
char s[N];

int main(){
    freopen("USTC.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> (s + 1);
    int n = strlen(s + 1);
    vector<int> Pos;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'U' || s[i] == 'S' || s[i] == 'T' || s[i] == 'C') Pos.push_back(i);
    }
    int ans = Pos[2] + Pos[3] - Pos[0] - Pos[1] - 4;
    printf("%d\n", ans);
    return 0;
}
