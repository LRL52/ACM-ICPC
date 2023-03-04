#include <stdio.h>
#include <string.h>

int main()
{
    char *s1 = "Hello, LingRui Studio.";
    char s2[22] = "Hello, LingRui Studio.";
    s2[4] = 'a';
    puts(s2);
    printf("%d %d\n", strlen(s1), strlen(s2));
    printf("%c\n", *("abcd" + 2));
    char s[6]; int i; for(i = 0; i <= 5; ++i) s[i] = ('A' + i) % 70;
    char s3[] = "Hello", s4[] = "Hello";
    printf("%d\n", s3 == s4); 
    return 0;
}