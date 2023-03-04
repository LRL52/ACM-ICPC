// ID: LRL Date: 2019.8.2
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055;
typedef long long ll;
int n, m;

ll rnd(ll x){return (ll)RAND_MAX * rand() * rand() % x + 1;}
map<int, int> H;

void gen(){
	H.clear();
	n = 5;
	printf("%d\n", n);
	int lst = 0;
	rep(i, 1, n){
		while(1){
			int x = rnd(10) + lst;
			if(H.find(x) == H.end()){
				H[x] = 1, lst = x;
				printf("%d ", x);
				break;
			}
		}
	}
	puts("");
	lst = 0;
	rep(i, 1, n){
		while(1){
			int x = rnd(10) + lst;
			if(H.find(x) == H.end()){
				H[x] = 1, lst = x;
				printf("%d ", x);
				break;
			}
		}
	}
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
