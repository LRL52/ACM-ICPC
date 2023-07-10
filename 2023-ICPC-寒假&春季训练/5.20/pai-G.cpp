/*** 
 * @Author: LRL52
 * @Date: 2023-05-21 17:27:56
 * @LastEditTime: 2023-05-21 18:06:45
 */
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
		int n = 9;
		printf("%d\n", n);
		for (int i = 2; i <= n; ++i)
			printf("%d %d\n", i, rnd(i - 1)); 
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
		system("./G_Ksyusha_and_Chinchilla > G.out");
		system("./G-std > G-std.out");
		if(system("diff G.out G-std.out")){
			cerr << "Wrong Answer!" << '\n';
			return 0;
		}
		cerr << "Passing " << times << "..." << '\n';
	}
	return 0;
}
