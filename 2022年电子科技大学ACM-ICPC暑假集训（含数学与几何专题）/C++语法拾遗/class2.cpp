#include <bits/stdc++.h>
using namespace std;

class area {
    protected: //protected后子类可以访问
        double L;
    private: //private后子类不可访问
        int src;
    public: //public的函数貌似子类也不可访问
        void setsrc(int x) {
            src = x;
        }
        int getsrc() {
            return src;
        }
        string test(){
            string ret = "test";
            return ret;
        }
};

class squarearea:area {
    public:
        void setL(double);
        double getarea();
        double getV() {
            return L * L * L;
        }
};

void squarearea::setL(double x) {
    L = x;
}

double squarearea::getarea() {
    return L * L;
}

int main(){
    squarearea a;
    a.setL(5.5);
    auto res = a.getarea();
    cout << res << '\n';
    res = a.getV();
    cout << res << '\n';
    area b;
    b.setsrc(5);
    cout << b.getsrc() << '\n';
    //a.setsrc(6);
    //cout << a.getsrc() << '\n';
    cout << b.test() << '\n';
    return 0;
}