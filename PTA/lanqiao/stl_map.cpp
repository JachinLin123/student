#include "cstdio"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    map<int, string> mapTemp;

    mapTemp.insert({ 5,"张三" });
    mapTemp.insert({ 3, "李四"});
    mapTemp.insert({ 4, "隔壁老王" });

    map<int, string>::iterator it;
    for (it = mapTemp.begin(); it != mapTemp.end(); it++)
    {
        printf("学号：%d 姓名：%s\n", (*it).first, (*it).second.c_str());
    }

    return 0;
}