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
	int T = 1;
    printf("%d\n", T);
    int n = 5;
	printf("%d\n", n);
	rep(i, 1, n) printf("%d", rand() % 2);
	puts("");
	rep(i, 1, n) printf("%d", rand() % 2);
	//rep(i, 1, m) printf("%d %d 1\n", i, i + 1);
}


int main(){
	freopen("in.in", "w", stdout);
	rep(times, 1, 10000){
		srand((unsigned)time(NULL) * times);
		freopen("J.in", "w", stdout);
		gen();
		cerr << "Generate data done. ";
		freopen("debug.txt", "w", stdout);
		system("J-std");
		system("J_Two_Binary_Strings_Problem");
		if(system("fc J.out J-std.out")){
			cerr << "Wrong Answer!" << '\n';
			return 0;
		}
		cerr << "Passing " << times << "..." << '\n';
	}
	return 0;
}
