// ID: LRL52 Date: 2023.2.6
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055;
using LL = long long;
int n, m;
mt19937 Rng(random_device{}());
uniform_int_distribution<int> dist(0, 2e9);

int rnd(int x) { return dist(Rng) % x + 1; }

void gen(){
	int n = 5, K = rnd(n);
	printf("%d %d\n", n, K);
	for(int i = 1; i <= n; ++i) {
		int l = rnd(10), r = rnd(10);
		if(l > r) swap(l, r);
		printf("%d %d %d\n", l, r, rnd(50));
	}
}


int main(){
	freopen("in.in", "w", stdout);
	rep(times, 1, 10000){
		srand((unsigned)time(NULL) * times);
		freopen("E.in", "w", stdout);
		gen();
		cerr << "Generate data done. ";
		freopen("debug.txt", "w", stdout);
		system("./E_Yet_Another_Interval_Graph_Problem < E.in > E.out");
		system("./E-std < E.in > E-std.out");
		if(system("diff E.out E-std.out")){
			cerr << "Wrong Answer!" << '\n';
			return 0;
		}
		cerr << "Passing " << times << "..." << '\n';
	}
	return 0;
}
