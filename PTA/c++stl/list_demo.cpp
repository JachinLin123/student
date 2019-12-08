#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

typedef list<int> ListInt;
int main()
{
    ListInt L1;
    ListInt::iterator i;
    L1.push_front(2);
    L1.push_front(1);
    L1.push_back(3);
    L1.push_back(4);
    for (i = L1.begin(); i != L1.end(); i++){
        cout << *i << endl;
    }
    ListInt::reverse_iterator ir;
    for (ir = L1.rbegin(); ir != L1.rend(); ir++){
        cout << *ir << endl;
    }
    return 0;
}