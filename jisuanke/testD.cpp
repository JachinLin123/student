#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[30] = {7, 2, 12, 5, 9, 9, 8, 10, 7, 10, 5, 4, 5, 8, 4, 4, 10, 11, 3, 8, 7, 8,
     3, 2, 1, 6, 3, 9, 7, 1};
    sort(a, a + 30);
    for (int i = 0; i < 30; i++){
        cout << a[i] << " ";
    }
    return 0;
}
