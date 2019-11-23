#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main()
{
    int a[2005] = {0}, b[2005] = {0}, n = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        if(a[i] + b[i] > 0)
            sum += a[i] + b[i];
    }
    cout << sum << endl;
    return 0;
}