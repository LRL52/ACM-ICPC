//ID: LRL52  Date: 2019.11.3
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1000055;
int Nxt[N];
char a[N], b[N];

int main(){
#ifdef LRL52
	freopen("Q.in", "r", stdin);
#endif
	scanf("%s%s", a + 1, b + 1);
	int m = strlen(b + 1);
	for(int i = 2, j = 0; i <= m; ++i){
		while(j > 0 && b[j + 1] != b[i]) j = Nxt[j];
		if(b[j + 1] == b[i]) ++j;
		Nxt[i] = j;
	}
	int n = strlen(a + 1), ans = 0;
	for(int i = 1, j = 0; i <= n; ++i){
		while(j > 0 && b[j + 1] != a[i]) j = Nxt[j];
		if(b[j + 1] == a[i]) ++j;
		if(j == m){
			++ans;
			j = Nxt[j];
		}
	}
    printf("%d\n", ans);
	return 0;
}