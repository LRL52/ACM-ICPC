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
	int T = 1;
	printf("%d\n", T);
	rep(tt, 1, T) {
		int n = 3, m = 3;
		printf("%d %d\n", n, m);
		rep(i, 1, n) printf("%d ", rnd(10));
		puts("");
		rep(i, 1, n) printf("%d ", rnd(10));
		puts("");
	}
}


int main(){
	freopen("in.in", "w", stdout);
	rep(times, 1, 10000){
		srand((unsigned)time(NULL) * times);
		freopen("A.in", "w", stdout);
		gen();
		cerr << "Generate data done. ";
		freopen("debug.txt", "w", stdout);
		system("./A_Array_Merge > A.out");
		system("./A-std < A.in > A-std.out");
		if(system("diff A.out A-std.out")){
			cerr << "Wrong Answer!" << '\n';
			return 0;
		}
		cerr << "Passing " << times << "..." << '\n';
	}
	return 0;
}
