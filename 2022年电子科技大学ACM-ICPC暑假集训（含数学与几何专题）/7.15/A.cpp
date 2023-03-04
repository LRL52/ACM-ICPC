//ID: LRL52  Date: 2022.7.15
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
map<string, char> a;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    a[".-"] = 'A';
    a["-..."] = 'B';
    a["-.-."] = 'C';
    a["-.."] = 'D';
    a["."] = 'E';
    a["..-."] = 'F';
    a["--."] = 'G';
    a["...."] = 'H';
    a[".."] = 'I';
    a[".---"] = 'J';
    a["-.-"] = 'K';
    a[".-.."] = 'L';
    a["--"] = 'M';
    a["-."] = 'N';
    a["---"] = 'O';
    a[".--."] = 'P';
    a["--.-"] = 'Q';
    a[".-."] = 'R';
    a["..."] = 'S';
    a["-"] = 'T';
    a["..-"] = 'U';
    a["...-"] = 'V';
    a[".--"] = 'W';
    a["-..-"] = 'X';
    a["-.--"] = 'Y';
    a["--.."] = 'Z';
    string s;
    while(cin >> s && s.size()){
        for(int i = 0, j; i < s.size(); i = j + 1){
            j = i;
            if(s[i] == '/'){
                putchar(' ');
                continue;
            }
            while(j < s.size() && s[j] != '/') ++j;
            //cout << s.substr(i, j - i) << " ";
            putchar(a[s.substr(i, j - i)]);
        }
        puts("");
    }        
	return 0;
}