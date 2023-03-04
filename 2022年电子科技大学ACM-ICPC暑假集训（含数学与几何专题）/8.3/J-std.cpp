#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 5e4 + 10;
int s[N], id[N];
bitset<N> A, ans, flip;


inline void solve(){
    A.reset(), ans.reset(), flip.reset();
    int n = 0; cin >> n;
    string a, b; cin >> a >> b;
    a = '@' + a, b = '@' + b;
    for(int i = 1; i <= n; i++) flip.set(i);
    id[0] = 0;
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + (a[i] == '1' ? 1 : -1);
        id[i] = i;
    } 
    sort(id, id + 1 + n, [](int x, int y){ return s[x] > s[y] || s[x] == s[y] && x < y; });
    int tg = n + 1;
    for(int i = 0; i <= n; i++){
        int pos = id[i];
        if(pos){
            if(b[pos] == '1') {
                ans = ans | (A >> (n - pos));
                if(s[pos] <= 0) tg = min(tg, pos + 1);
            } else {
                ans = ans | ((A ^ flip) >> (n - pos));
                if(s[pos] > 0) tg = min(tg, pos + 1);
            }
        }
        A[n - pos] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(ans[i] || i >= tg) cout << 0;
        else cout << 1;
    }
    cout << endl;
}

signed main(){
    freopen("J.in", "r", stdin);
    freopen("J-std.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(0);
    int t = 0; cin >> t;
    while(t--) solve();
    return 0;
}
