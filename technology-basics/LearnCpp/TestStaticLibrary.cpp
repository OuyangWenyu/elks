#include "StaticMath.h"
#include <iostream>
using namespace std;
int main()
{
    double a = 10;
    double b = 2;
    cout << "a + b = " << StaticMath::add(a, b) << endl;
    system("pause");
    return 0;
}
