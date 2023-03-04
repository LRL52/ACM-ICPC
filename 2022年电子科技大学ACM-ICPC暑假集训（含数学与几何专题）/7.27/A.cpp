#include <bits/stdc++.h>

#define endl '\n'
#define IOS std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define seteps(N) fixed << setprecision(N) 
typedef long long ll;

using namespace std;
/*-----------------------------------------------------------------*/

ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
#define INF 0x3f3f3f3f

const int N = 1e6 + 10;
const int M = 998244353;
const double eps = 1e-5;

int isnp[N];
int pri[N];
int mu[N];
int cnt;

inline ll qpow(ll a, ll b, ll m) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

int main() {
    IOS;
    isnp[1] = 1;
    mu[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!isnp[i]) {
            mu[i] = -1;
            pri[cnt++] = i;
        }
        for(int j = 0; j < cnt && i * pri[j] < N; j++) {
            mu[i * pri[j]] = -mu[i];
            isnp[i * pri[j]] = 1;
            if(i % pri[j] == 0) {
                mu[i * pri[j]] = 0;
                break;
            }
        }
    }
    ll m, k;
    cin >> m >> k;
    ll ans = 0;
    for(int i= 1; i <= k; i++) {
        ans = (ans + (qpow(1 + 2 * (k / i), m, M) - 1 + M) * mu[i] % M + M) % M;
    }
    cout << (ans + 1 + M) % M << endl;
}
