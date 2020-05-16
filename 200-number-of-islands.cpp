#include "stdafx.h"

class Solution
{
    int n, m;
    vector<int> parent;
    vector<int> rank;

    void makeSet(int n, int m)
    {
        this->n = n;
        this->m = m;
        parent.resize(n * m);
        for (int i = 0; i < n * m; i++)
            parent[i] = i;
        rank.resize(n * m, 0);
    }

    int findSet(int x)
    {
        int foundSet = x;
        if (parent[x] != x)
            foundSet = findSet(parent[x]);

        parent[x] = foundSet;

        return foundSet;
    }

    void unionSet(int a, int b)
    {
        int sa = findSet(a);
        int sb = findSet(b);

        if (sa != sb)
        {
            if (rank[sa] < rank[sb])
            {
                parent[sa] = sb;
            }
            else if (rank[sa] > rank[sb])
            {
                parent[sb] = sa;
            }
            else
            {
                parent[sb] = sa;
                rank[sa]++;
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (!grid.size())
            return 0;
        makeSet(grid.size(), grid[0].size());
        int islands = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    if (i > 0 && grid[i - 1][j] == '1')
                    {
                        unionSet(i * m + j, (i - 1) * m + j);
                    }
                    if (j > 0 && grid[i][j - 1] == '1')
                    {
                        unionSet(i * m + j, i * m + j - 1);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && findSet(i * m + j) == i * m + j)
                {
                    // cout << i << " " << j << "\n";
                    islands++;
                }
            }
        }
        return islands;
    }
};