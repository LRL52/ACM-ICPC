#include <stdio.h>

int main() {
    int a = 1, b = 2, c;
    c = a + b;
    asm volatile (
        "lea (%rip), %rax"
    );
    return 0;
}