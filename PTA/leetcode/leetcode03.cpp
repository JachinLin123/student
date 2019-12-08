//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class leetcode03
{
public:
    int lengthOfLongestSubstring(string s){
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
};

int main(){
    string s = "pwwkew";
    leetcode03 test;
    cout << test.lengthOfLongestSubstring(s) << endl;
}