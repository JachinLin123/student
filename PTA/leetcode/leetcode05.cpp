/*
 * 问题描述
 * 给定数组nums和一个值val，原地删除所有等于val的元素，返回新数组的新长度
 * 不能使用额外的数组空间。 
 */
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
        int removeElment(vector<int>&nums, int val){
            int j = 0;
            for (int i = 0; i < nums.size(); i++){
                if(nums[i]!=val){
                    nums[j] = nums[i];
                    j++;
                }
            }
            return j;
        }
};
/*
0 1 1 0 0 2 2 0 2 1 3
2
0--nums[0]=0
1--nums[1]=1
1--nums[2]=1
0--nums[3]=0
0--nums[4]=0
2--null
2--null
0--nums[5]=0
2--null
1--nums[6]=1
3--nums[7]=3
*/

int main(){

    Solution s;
    vector<int> nums = {1, 2, 3, 4, 4, 6};
    cout << s.removeElment(nums, 4) << endl;
    return 0;
}
