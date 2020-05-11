#include "stdafx.h"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (!n)
            return 0;
        int m = grid[0].size();
        vector<vector<int>> sums(n, vector<int>(m, INT_MAX));
        sums[0][0] = grid[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i < n - 1)
                    sums[i + 1][j] = min(sums[i][j] + grid[i + 1][j], sums[i + 1][j]);
                if (j < m - 1)
                    sums[i][j + 1] = min(sums[i][j] + grid[i][j + 1], sums[i][j + 1]);
            }
        }
        return sums[n - 1][m - 1];
    }
};