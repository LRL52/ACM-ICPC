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
	
}


int main(){
	freopen("in.in", "w", stdout);
	rep(times, 1, 10000){
		srand((unsigned)time(NULL) * times);
		freopen("F.in", "w", stdout);
		gen();
		cerr << "Generate data done. ";
		freopen("debug.txt", "w", stdout);
		system("F-brute");
		system("F-syz");
		if(system("fc F.out F-std.out")){
			cerr << "Wrong Answer!" << '\n';
			return 0;
		}
		cerr << "Passing " << times << "..." << '\n';
	}
	return 0;
}
