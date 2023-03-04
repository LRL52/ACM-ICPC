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
	rep(i, 1, n) rep(j, 1, n) vis[i][j] = 0;
	n = 200; printf("%d\n", n);
	rep(i, 1, n){
		int x, y;
		while(1){
			x = rnd(100), y = rnd(100);
			if(vis[x][y]) continue;
			break;
		}
		vis[x][y] = 1;
		printf("%d %d\n", x, y);
	}
}


int main(){
	freopen("in.in", "w", stdout);
	rep(times, 1, 10000){
		srand((unsigned)time(NULL) * times);
		freopen("G.in", "w", stdout);
		gen();
		cerr << "Generate data done. ";
		freopen("debug.txt", "w", stdout);
		system("G");
		system("G_brute");
		if(system("fc G.out G_std.out")){
			cerr << "Wrong Answer" << endl;
			system("pause");
			return 0;
		}
		cerr << "Passing " << times << "..." << endl;
	}
	return 0;
}
