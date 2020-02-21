#include <bits/stdc++.h>

using namespace std;


int main(){

    int x = 0, y = 0, z = 0, u = 0;
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10;j++){
            for (int k = 1; k < 10; k++){
                for (int m = 1; m < 10; m++){
                    if((520+i)*6==(j*1000+k*100+m*10+8)){
                        x = i;
                        y = j;
                        z = k;
                        u = m;
                        break;
                    }
                }
            }
        }
    }
    cout << x << y << z << u;
    return 0;
}