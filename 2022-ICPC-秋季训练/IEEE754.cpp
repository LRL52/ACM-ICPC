#include <bits/stdc++.h>
using namespace std;

int main() {
    union Node {
        int x;
        float y;
    }a;
    a.y = 20.59375f;
    printf("a.x = %d\n", a.x);
    bitset<32> T;
    T = a.x;
    cout << T << endl;
    return 0;
}