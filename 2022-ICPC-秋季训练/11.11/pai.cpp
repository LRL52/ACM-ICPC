// ID: LRL Date: 2019.8.2
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055;
typedef long long ll;
int n, m;

ll rnd(ll x){return rand() % x + 1;}

void gencard() {
	auto x = rnd(13) + 1;
	if(x == 10) putchar('T');
	else if(x == 11) putchar('J');
	else if(x == 12) putchar('Q');
	else if(x == 13) putchar('K');
	else if(x == 14) putchar('A');
	else putchar(x + '0');
	putchar('C');
	putchar(' ');
}


void gen(){
	puts("1");
	auto n = rnd(10), m = rnd(10);
	printf("%lld %lld\n", n, m);
	rep(i, 1, n) gencard();
	puts("");
	rep(i, 1, m) gencard();
	puts("");
	gencard();
}


int main(){
	//gen();
	//return 0;
	freopen("E.in", "w", stdout);
	rep(times, 1, 10000){
		srand((unsigned)time(NULL) * times);
		freopen("E.in", "w", stdout);
		gen();
		cerr << "Generate data done. ";
		freopen("debug.txt", "w", stdout);
		system("./E_Prof_Pang_and_Poker < E.in > E.out");
		system("./E-std < E.in > E.ans");
		if(system("diff E.out E.ans")){
			cerr << "Wrong Answer!" << '\n';
			return 0;
		}
		cerr << "Passing " << times << "..." << '\n';
	}
	return 0;
}
