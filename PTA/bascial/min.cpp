#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int smax(int a, int b, int c)
{
    int max = a;
    if(b > c)
    {
        c = b;
    }
    if(b > max)
    {
        max = b;
    }
    
    return max;
}

int main()
{
    int n1, n2, n3, max;
 
    cin >> n1 >> n2 >> n3;
    
    // 获取最大的数
    max = smax(n1, n2, n3);

    do
    {
        if (max % n1 == 0 && max % n2 == 0 && max % n3 == 0)
        {
            cout << max << endl;
            break;
        }
        else
            ++max;
    } while (true);

    return 0;
}