#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> mymap;
    int count = 0, firstId = 0, id = 0, scorce=0, max = 0 ;
    cin >> count;
    while(count--){
        cin >> id >> scorce;
        mymap[id] += scorce;
    }
    map<int, int>::iterator iter;
    for (iter = mymap.begin(); iter != mymap.end(); iter++)
    {
        if(iter->second >= max){
            max = iter->second;
            firstId = iter->first;
        }
    }
    cout << firstId << " " << max << endl;

    return 0;
}