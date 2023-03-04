#include <bits/stdc++.h>
using namespace std;

class area {
    public:
        double width, length;
};

int main(){
    area a;
    a.width = 5.0;
    a.length = 7.0;
    cout << a.length * a.width << '\n';   
    return 0;
}