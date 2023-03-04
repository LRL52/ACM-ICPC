#include <bits/stdc++.h>
using namespace std;
int n, c1, c2, ans;
string s;
int main() {
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  cin >> n >> c1 >> c2;
  if(c1 > c2) c1 = c2;
  else c2 = min(c2, c1 + c1);
  for(int i = 1; i <= n; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    if(s[0] == s[1] || s[1] == s[2]) ans += min(c1 + c2, 3 * c1);
    else ans += 3 * c1;
  }
  cout << ans << "\n";
  return 0;
}
