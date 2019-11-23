#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using std::vector;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (m <= 0 || n <= 0)
    {
        return 0;
    }
    int dp[m][n] = {0}; // 
      // 初始化
      dp[0][0] = grid[0][0];
      // 初始化最左边的列
      for(int i = 1; i < m; i++){
      dp[i][0] = dp[i-1][0] + grid[i][0];
    }
      // 初始化最上边的行
      for(int i = 1; i < n; i++){
      dp[0][i] = dp[0][i-1] + grid[0][i];
    }
        // 推导出 dp[m-1][n-1]
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int numRows=3,zone=3;//层数，每层需要的空间
    vector<vector<int>> vec(numRows, vector<int>());//初始层数，赋值
    for (int i = 0; i < numRows; i++) {
	    vec[i].resize(zone);
}
    return 0;
}