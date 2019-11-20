#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
    set<int> setTemp;

    setTemp.insert(3);
    setTemp.insert(1);
    setTemp.insert(2);
    setTemp.insert(1);

    set<int>::iterator it;
    for (it = setTemp.begin(); it != setTemp.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}

/*
#include <iostream>
#include <set>
#include <string>

using namespace std;

struct People
{
    string name;
    int age;

    bool operator <(const People p) const
    {
        return age < p.age;
    }
};

int main(int argc, char* argv[])
{
    set<People> setTemp;

    setTemp.insert({"张三",14});
    setTemp.insert({ "李四", 16 });
    setTemp.insert({ "隔壁老王", 10 });

    set<People>::iterator it;
    for (it = setTemp.begin(); it != setTemp.end(); it++)
    {
        printf("姓名：%s 年龄：%d\n", (*it).name.c_str(), (*it).age);
    }

    return 0;
}
*/