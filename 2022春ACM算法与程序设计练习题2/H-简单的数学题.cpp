//����ͬ�࣬һ��������9������ ���� ���������λ����֮�ͳ���9������
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;
char s[N];

int main() {
	scanf("%s", s);
	sort(s, s + strlen(s));
	puts(s);
	return 0;
}