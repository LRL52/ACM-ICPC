#include <bits/stdc++.h>

constexpr int fib(const int n){
    return n == 0 || n == 1 ? 1 : fib(n - 1) + fib(n - 2);
}

int main(){
    int n = 6;
    std::cin >> n;
    std::cout << fib(n) << '\n';
    int a[fib(n)];
    std::cout << sizeof(a) / 4 << '\n';
    return 0;
}