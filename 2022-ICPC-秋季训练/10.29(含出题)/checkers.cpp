#include "testlib.h"
#include <string>

using namespace std;

const string YES = "YES";
const string NO = "NO";

int main(int argc, char * argv[])
{
    setName("%s", (YES + " or " + NO + " (case insensetive)").c_str());
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    std::string ja, pa;
    for(int i = 1; i <= n; ++i) {
        ja = upperCase(ans.readWord());
        pa = upperCase(ouf.readWord());

        if(i != n) {
            ans.readEoln();
            ouf.readEoln();
        }
        
        if (ja != YES && ja != NO)
            quitf(_fail, "%s or %s expected in answer, but %s found", YES.c_str(), NO.c_str(), compress(ja).c_str());

        if (pa != YES && pa != NO)
            quitf(_pe, "%s or %s expected, but %s found", YES.c_str(), NO.c_str(), compress(pa).c_str());

        if (ja != pa)
            quitf(_wa, "expected %s, found %s", compress(ja).c_str(), compress(pa).c_str());

    }
    quitf(_ok, "answer is %s", "correct");
}
