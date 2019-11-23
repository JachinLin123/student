#include <iostream>
#include <cmath>

using namespace std;

int uniquePaths(int m, int n)
{
    int dp[m][n] = {0};

    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }
    for (size_t i = 1; i < m; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        
    }
    
    return dp[m-1][n-1];
}

int main()
{
    int m = 7, n = 3;
    cout << uniquePaths(m, n) << endl;
    return 0;
}