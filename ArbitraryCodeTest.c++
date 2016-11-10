#include <iostream>
#include "ArbitraryCode.h"

using namespace std;

execute([](){
    cout << "it works" << endl;
});

execute([](){
    cout << "this works too" << endl;
});

void foo() {
    cout << "Does foo work too?" << endl;
}

execute(foo);

int main()
{
    cout << "In main here" << endl;
    execute([](){
        cout << "Can do it in main too." << endl;
    });
}
