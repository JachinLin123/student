#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char* argv[])
{
    deque<float> dequeTemp;

    for (int i = 0; i<6; i++)
        dequeTemp.push_back(i);

    for (int i = 0; i<dequeTemp.size(); i++)
        cout << dequeTemp[i] << " "; // 输出：0 1 2 3 4 5

    return 0;
}