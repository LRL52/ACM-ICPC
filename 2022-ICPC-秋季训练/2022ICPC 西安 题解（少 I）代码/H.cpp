#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1 << 16;
string op;
vector<int> A, M, d;
int n, x, y, z, cnt[N], s[N];
void AND(int id) {x--, op += '&', d.push_back(id);}
void OR(int id) {y--, op += '|', d.push_back(id);}
void XOR(int id) {z--, op += '^', d.push_back(id);}
void F(int id) {z ? XOR(id) : OR(id);}
void G(int id) {x ? AND(id) : F(id);}
void solve() {
  scanf("%d%d%d%d", &n, &x, &y, &z);
  A.clear(), M.clear(), d.clear(), op = "";
  for(int i = 0; i < n; i++) cnt[i] = s[i] = 0;
  for(int i = 0, a; i < n; i++) scanf("%d", &a), cnt[a]++;
  for(int i = 0; i < n; i++) {
    if(cnt[i]) A.push_back(i);
    if(cnt[i] > 1) M.push_back(i);
  }
  if(y + z <= A.size()) {
    reverse(A.begin(), A.end());
    int tot = y + z;
    for(int i = 0; i < tot; i++) s[A[i]] = 1, cnt[A[i]]--;
    for(int i : A) while(cnt[i]--) AND(i);
    for(int i = 0; i < tot; i++) F(A[i]);
  }
  else if(x == 0) {
    for(int i = n - 1; ~i; i--) {
      if(cnt[i] & 1) {s[i] = 1; while(cnt[i]--) F(i);}
      else if(cnt[i] && y) {s[i] = 1; while(--cnt[i]) F(i); OR(i);}
      else {while(cnt[i]--) F(i);}
    }
  }
  else {
    for(int i : A) s[i] = 1, cnt[i]--;
    if(y) {
      cnt[M[0]]--, x--;
      for(int i : A) while(cnt[i]--) G(i);
      x++, AND(M[0]), OR(M[0]);
      A.erase(find(A.begin(), A.end(), M[0]));
    }
    else if(x >= 2 && M.size() >= 2) {
      cnt[M[0]]--, cnt[M[1]]--, x -= 2;
      for(int i : A) while(cnt[i]--) G(i);
      x += 2, AND(M[0]), AND(M[1]);
    }
    else if(M.size() == 1) {
      if(z - A.size() & 1) {
        s[A[0]] = 0, AND(A[0]);
        A.erase(find(A.begin(), A.end(), A[0]));
      }
      while(cnt[M[0]]--) G(M[0]);
    }
    else {
      int odd = -1;
      for(int i : M) if(cnt[i] & 1) odd = i;
      if(odd == -1) {
        s[A[0]] = 0, AND(A[0]);
        A.erase(find(A.begin(), A.end(), A[0]));
      }
      else cnt[odd]--;
      for(int i : M) while(cnt[i]--) XOR(i);
      if(odd != -1) AND(odd);
    }
    for(int i : A) F(i);
  }
  for(int i = n - 1; ~i; i--) cout << s[i]; cout << "\n";
  cout << op << "\n";
  for(int i = 0; i < n; i++) cout << d[i] << (i + 1 < n ? ' ' : '\n');
}
int main() {
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  cerr << "TIME " << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n";
  return 0;
}
