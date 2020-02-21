#include <iostream>

#include <cmath>
using namespace std;
bool prime(int x)
{
     int y;
     for(y=2;y<=sqrt(x);y++)
         if (x%y==0)
            return false;
     return true;
}
int main ()
{
    int n = 100000,i;
    //cin>>n;
    bool flag = false;
    int test = 0;
    int num = 0;
    for(i=3;i<=n;i++){
        test = i;
        while(test){
            if(test%10==5){
                flag = true;
                break;
            }
            test = test / 10;
        }
    if(flag){
        flag = false;
        if(prime(i)){
            num++;
            cout << i << endl;
        }
    }
    }
    cout << num;
    return 0;
}