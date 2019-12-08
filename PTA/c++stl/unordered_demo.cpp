#include <algorithm>
#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){

    unordered_map<int, string> mymap;
    mymap.insert(make_pair(1, "hello"));
    mymap.insert(make_pair(2, "jack"));
    mymap.insert(make_pair(3, "lucy"));
    mymap.insert(make_pair(4, "funk"));

    unordered_map<int, string>::iterator it;
    if((it = mymap.find(3)) != mymap.end()){
        cout << it->second << endl;
    }
    return 0;
}