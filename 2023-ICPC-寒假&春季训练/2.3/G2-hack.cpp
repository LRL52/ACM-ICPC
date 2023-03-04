#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define forsn(i, s, n) for(int i = s; i < n; ++i)
#define dforn(i, n) for(int i = n-1; i >= 0; --i)
#define DBG(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	fastIO;
	ll n = 1e5;
	ll m = 1e9;
	cout << 1 << endl;
	cout << 2*n << " " << m << endl;
	
	for(ll i = 0; i<n; i++){
		cout << (ll)1e9 << " ";
	}
	for(ll i = 0; i<n; i++){
		cout << 1;
		if(i != n-1) cout << " ";
	}
	cout << endl;	
}