#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int row = i - 1;
                int col = j - 1;
                int count_0 = 0, count_1 = 0;

                for (int k = 1; k <= 8; k++)
                {

                    if (k == 1)
                    {

                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            col++;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            col++;
                        }
                    }
                    else if (k == 2)
                    {

                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            col++;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            col++;
                        }
                    }
                    else if (k == 3)
                    {

                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            row++;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            row++;
                        }
                    }
                    else if (k == 4)
                    {

                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            row++;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            row++;
                        }
                    }
                    else if (k == 5)
                    {
                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            col--;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            col--;
                        }
                    }
                    else if (k == 6)
                    {
                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            col--;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            col--;
                        }
                    }
                    else if (k == 7)
                    {
                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            row--;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            row--;
                        }
                    }
                    else
                    {
                        if (row < 0 || col < 0 || row >= m || col >= n)
                        {
                            row--;
                        }
                        else
                        {
                            if (board[row][col] == 1)
                            {
                                count_1++;
                            }
                            else
                            {
                                count_0++;
                            }
                            row--;
                        }
                    }
                }

                //  rules for updation

                if (board[i][j] == 1)
                {
                    if (count_1 < 2)
                    {
                        temp[i][j] = 0;
                    }
                    else if (count_1 == 2 || count_1 == 3)
                    {
                        temp[i][j] = 1;
                    }
                    else if (count_1 > 3)
                    {
                        temp[i][j] == 0;
                    }
                }
                else
                {
                    if (count_1 == 3)
                    {
                        temp[i][j] = 1;
                    }
                    else
                    {
                        temp[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = temp[i][j];
            }
        }
    }
};