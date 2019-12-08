#include <algorithm>
#include <cstdio>
#include <iostream>
#include <deque>

using namespace std;

int main(){

    deque<int> mydeque = {1, 2, 3};
    mydeque.push_back(12);
    mydeque.push_front(23);
    for(int n : mydeque){
        cout << n << endl;
    }
    return 0;
}