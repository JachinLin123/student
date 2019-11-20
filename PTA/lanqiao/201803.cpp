#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 0, num1 = 0, num2 = 0;
    while(cin >> a)
    {
        while(1)
        {
            if(a != 0 && a%2 == 0)
            {
                a /= 2;
                num1++;
            }
            else if(a != 0 && a%5 == 0)
            {
                a /= 5;
                num2++;
            }
            else
            {
                break;
            }
            
        }
    }
    cout << num1 << " " << num2 << endl;
    return 0;
}