#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> R{-1, 0, 1, 0};
    vector<int> C{0, 1, 0, -1};
    int m, n;
    int helper(int row, int col, int total, int curr_energy, int energy, vector<string> &classroom)
    {
        if (total == 0)
            return 0;
        if (row == m or col == n)
            return 1e5 + 9;
        if (curr_energy == 0 and classroom[row][col] != 'R')
            return 1e5 + 9;

        int ans = 1e5 + 9;
        for (int i = 0; i < 4; i++)
        {
            int new_row = row + R[i];
            int new_col = col + C[i];
            if (new_row >= 0 and new_row < m and new_col >= 0 and new_col < n)
            {
                char temp = classroom[new_row][new_col];
                if (temp != 'X')
                {
                    if (temp == 'L')
                        ans = min(ans, 1 + helper(new_row, new_col, total - 1, curr_energy - 1, energy, classroom));
                    else if (temp == 'R')
                        ans = min(ans, 1 + helper(new_row, new_col, total, energy, energy, classroom));
                    else
                        ans = min(ans, 1 + helper(new_row, new_col, total, curr_energy - 1, energy, classroom));
                };
            };
        };
        return ans;
    }
    int minMoves(vector<string> &classroom, int energy)
    {
        m = classroom.size();
        n = classroom[0].size();
        int ans = -1;
        int total = 0;
        int row , col;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') row = i , col = j;
                else if(classroom[i][j] == 'L') total++;
            };
        };

        ans = helper(row , col , total , energy , energy , classroom);
        if(ans >= 1e5 + 9) return -1;
        return ans;
    };
};

int main()
{

    return 0;
}

