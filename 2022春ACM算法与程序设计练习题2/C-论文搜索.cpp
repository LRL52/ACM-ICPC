//注意如果一个论文标题有多个关键词，该论文标题对答案的贡献依然只有1
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1055;
char key_words[25], s[N];

int main() {
	freopen("C.in", "r", stdin);
	int T, n; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s\n", key_words);
		int len = strlen(key_words), ans = 0;
		for (int k = 1; k <= n; ++k) {
			fgets(s, 105, stdin); //学习尝试使用fgets
			int Len = strlen(s);
			s[Len] = s[Len + 1] = '\0'; //加层边界，防止意外
			vector<int> space; //space 空格位置，把空格位置替换为'\0'，利用strcmp进行比较
			for (int i = 0; i < Len; ++i)
				if (s[i] == ' ' || s[i] == '\r' || s[i] == '\n') {
					s[i] = '\0';
					space.push_back(i);
				}
			int ok = 0;
			ok |= !strcmp(key_words, s);
			for (int j = 0; j < space.size(); ++j) {
				ok |= !strcmp(key_words, s + space[j] + 1);
				if (ok) break;
			}
			ans += ok;
		}
		ans ? printf("%d\n\n", ans) : printf("Do not find\n\n");
	}
	return 0;
}