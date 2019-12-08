#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<int> myqueue;
    for (int i = 0; i < 10; i++)
    {
        /* code */
        myqueue.push(i);
    }

    while(!myqueue.empty()){
        cout << myqueue.front() << endl;
        myqueue.pop();
    }
    
    return 0;
}
