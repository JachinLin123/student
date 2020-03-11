#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x = 1101;
    int y = 0, product = 1;
    while(x != 0){
        y = y + (x % 10) * product;
        x = x / 10;
        product = product * 2;
    }
    cout << y << endl;
    return 0;
}