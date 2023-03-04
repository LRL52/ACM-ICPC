#include <bits/stdc++.h>

//C++14
template<typename T, typename U>
auto add(T x, U y){
    return x + y;
}

template<typename T, typename U>
auto mul(T x, U y) -> decltype(x * y) {
    return x * y;
}

int main(){
    std::vector<int> a(5);
    a[0] = 3, a[1] = 6, a[4] = 7;
    for(std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it){
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    //auto 类型推导
    for(auto it = a.begin(); it != a.end(); ++it){
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    //auto i = 5, j = 7LL; //Complier Error
    auto i = 5;
    auto j = 7LL;
    decltype (i+j) k;
    std::cout << "sizeof(i) = " << sizeof(i) << '\n';
    std::cout << "sizeof(j) = " << sizeof(j) << '\n';
    std::cout << "sizeof(k) = " << sizeof(k) << '\n';
    std::cout << add(25, 13) << '\n';
    std::cout << add(10000000000LL, -1) << '\n';
    std::cout << mul(25, 0.125) << '\n';

    //区间迭代
    for(auto &x: a){ // & 启用了引用, 如果没有则对 a 中的元素只能读取，修改将不会影响原数组
        std::cout << x << ' ';
        x = 0;
    }
    std::cout << '\n';
    for(auto x: a){
        std::cout << x << ' ';
    }
    std::cout << '\n';
    return 0;
}