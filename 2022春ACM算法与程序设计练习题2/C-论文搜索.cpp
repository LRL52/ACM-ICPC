//ע�����һ�����ı����ж���ؼ��ʣ������ı���Դ𰸵Ĺ�����Ȼֻ��1
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
			fgets(s, 105, stdin); //ѧϰ����ʹ��fgets
			int Len = strlen(s);
			s[Len] = s[Len + 1] = '\0'; //�Ӳ�߽磬��ֹ����
			vector<int> space; //space �ո�λ�ã��ѿո�λ���滻Ϊ'\0'������strcmp���бȽ�
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