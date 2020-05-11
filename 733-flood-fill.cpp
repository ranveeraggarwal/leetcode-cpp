#include "stdafx.h"

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        floodFillHelper(image, sr, sc);
        for (int i = 0; i < image.size(); i++)
        {
            for (int j = 0; j < image[0].size(); j++)
            {
                if (image[i][j] == -1)
                    image[i][j] = newColor;
            }
        }
        // returning the original matrix, modified to save on copy time;
        // in general, it might be a better idea to make a copy and return since we
        // have a mutable reference as an input
        return image;
    }

    void floodFillHelper(vector<vector<int>> &image, int sr, int sc)
    {
        int currentColor = image[sr][sc];
        image[sr][sc] = -1;
        if (sr < image.size() - 1 && image[sr + 1][sc] == currentColor)
            floodFillHelper(image, sr + 1, sc);
        if (sr > 0 && image[sr - 1][sc] == currentColor)
            floodFillHelper(image, sr - 1, sc);
        if (sc < image[0].size() - 1 && image[sr][sc + 1] == currentColor)
            floodFillHelper(image, sr, sc + 1);
        if (sc > 0 && image[sr][sc - 1] == currentColor)
            floodFillHelper(image, sr, sc - 1);
    }
};
