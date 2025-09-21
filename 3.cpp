#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    int helper(int row, int col, int k, vector<vector<int>> &grid)
    {
        set<int> S;
        for (int i = row; i < row + k; i++)
        {
            for (int j = col; j < col + k; j++)
            {
                S.insert(grid[i][j]);
            };
        };
        if (S.size() == 1)
            return 0;
        int mini = INT_MAX;
        int prev = INT_MAX;
        for (auto it : S)
        {
            mini = min(mini, abs(prev - it));
            prev = it;
        };
        return mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for (int row = 0; row + k <= m; row++)
        {
            for (int col = 0; col + k <= n; col++)
            {
                int res = helper(row, col, k, grid);
                ans[row][col] = res;
            }
        };
        return ans;
    }
};

int main()
{

    return 0;
}