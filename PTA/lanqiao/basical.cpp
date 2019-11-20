#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323;

int main()
{

    double s = 0, r;
    cin >> r;
    s = PI * r * r;
    cout << fixed << setprecision(7) << s << endl;
    return 0;
}