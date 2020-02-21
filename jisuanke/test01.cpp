#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <hash_map>
using namespace std;

int main(){
    map<long long, long long> testmap;
    long long  a0 = 1, an =0, num = 0;
    long long A = 0, B = 0, C = 0;
    cin >> A >> B >> C;
    while(testmap[a0]!=2){
        testmap[a0]++;
        num++;
        if(testmap[a0]==2){
            break;
        }
        a0 = (a0 * A + a0 % B) % C;
    }
    cout << num - 1 << endl;
    return 0;
}
