#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){

    vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        /* code */
    }
    //四号位插入元素
    // vec.insert(vec.begin() + 4, 0);

    //清除3-5之间的元素
    // vec.erase(vec.begin() + 3, vec.begin() + 5);

    //

    //初始化遍历
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
        /* code */
    }
    //at 遍历
    for (int i = 0; i < vec.size(); i++){
        cout << vec.at(i) << endl;
    }
        //迭代遍历
        vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
        
    }
    sort(vec.begin(), vec.end());//升排序
    reverse(vec.begin(), vec.end());//降排序

    return 0;
}