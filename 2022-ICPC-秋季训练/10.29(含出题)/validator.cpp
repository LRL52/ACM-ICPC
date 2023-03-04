#include "testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int Task = inf.readInt(1, 1000000, "Task");
    inf.readEoln();

    for(int i = 1; i <= Task; ++i) {
        int n = inf.readInt(0, 1000000, "n");
        if(i != Task) inf.readEoln();
    }
    inf.readEof(); 

    return 0;
}
