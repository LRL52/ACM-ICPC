#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100055;
int n;
char s[N];

int main() {
	scanf("%d%s", &n, s + 1);
	//��������㷨�е����⣬����֤������ȷ��
	/*int one = 0, zero = 0, s1 = 0, s0 = 0; //s1��ʾ����1�Ķ���Ҫ�Ľ�������, s0ͬ��
	for (int i = 1; i <= n; ++i) {
		int t = 0;
		if (s[i] == '0') {
			++zero, ++t;
			while (i < n && s[i + 1] == '0') ++i, ++zero, ++t;
			s0 += t >> 1;
		}
		else {
			++one, ++t;
			while (i < n && s[i + 1] == '1') ++i, ++one, ++t;
			s1 += t >> 1;
		}
	}
	int ans = (n / 2) - min(one, zero); //��Ҫ��0��1 ���� 1��0 �Ĵ���
	if (one == zero) ans += max(s0, s1);
	else if (one < zero) ans += max(s1, s0 - ans);
	else ans += max(s0, s1 - ans);
	printf("%d\n", ans);*/

	//ֻҪ��λȷ���ˣ����մ𰸾Ͷ��ˣ���010101... �� 101010...
	//�����ַ���������żλ�ҵ������������𰸵����֣�ȡmax���Ǵ𰸵�һ�����������ϸ˵���������׵õ��ģ�
	//odd_0 ����λΪ0�ĸ��� odd_1 even_0 even_1 ͬ��
	int odd_0 = 0, odd_1 = 0, even_0 = 0, even_1 = 0;
	for(int i = 1; i <= n; ++i)
		if (i % 2) s[i] == '0' ? ++odd_0 : ++odd_1;
		else s[i] == '0' ? ++even_0 : ++even_1;
	printf("%d\n", min(max(odd_0, even_1), max(odd_1, even_0)));
	return 0;
}