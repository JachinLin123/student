#include <iostream>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
    list<char> listTemp;

    for (char c = 'a'; c <= 'z'; ++c)
        listTemp.push_back(c);

    while (!listTemp.empty())
    {
        cout <<listTemp.front() << " ";
        listTemp.pop_front();
    }

    return 0;
}