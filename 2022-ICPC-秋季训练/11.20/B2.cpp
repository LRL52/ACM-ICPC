#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("B.in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int Task; cin >> Task;
    while(Task--) {
        long double x, y, P;
        cin >> x >> y >> P;
        long double p = 1.0 / P, q = (long double)(P - 1) / P;
        long double res = 0.0, Q = 1.0;
        for(int i = 0; ; ++i) {
            if((long double)x - i * y < 0.0) break;
            long double val = min((long double)x - i * y, (long double)y);
            res += val * Q;
            Q = Q * q;
        }
        //res = res * p;
        printf("%.15Lf\n", (long double)res / (P * y));
    }
    return 0;
}
