#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){

    int num = 10000;
    int k = 0, n = 0;
    int j = 0;
    for (int i = 2; i <= num; i++){
        k = (int)sqrt((double)i);
        for (j = 2; j <= k; j++)
        {
            if(i%j==0){
                break;
            }
        }
        if(j > k){
            cout << i << endl;
            n++;
        }
    }
    cout << n << endl;
    return 0;
}