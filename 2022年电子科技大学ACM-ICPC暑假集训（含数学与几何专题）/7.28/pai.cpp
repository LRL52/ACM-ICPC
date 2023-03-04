// ID: LRL Date: 2019.8.2
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055;
typedef long long ll;
int n, m;

ll rnd(ll x){return (ll)RAND_MAX * rand() * rand() % x + 1;}
int vis[N][N];

void gen(){
	n = 5, m = 10;
    printf("%d %d\n", n, m);
    rep(i, 1, m){
        int u, v, type;
        while(1){
            u = rnd(n), v = rnd(n), type = rnd(2);
            if(u != v) break;
        }
        printf("%d %d %d\n", u, v, type);
    }
	//rep(i, 1, m) printf("%d %d 1\n", i, i + 1);
}


int main(){
	freopen("in.in", "w", stdout);
	rep(times, 1, 10000){
		srand((unsigned)time(NULL) * times);
		freopen("H.in", "w", stdout);
		gen();
		cerr << "Generate data done. ";
		freopen("debug.txt", "w", stdout);
		system("H");
		system("H_TLE");
		if(system("fc H.out H_std.out")){
			cerr << "Wrong Answer!" << '\n';
			return 0;
		}
		cerr << "Passing " << times << "..." << '\n';
	}
	return 0;
}
