#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n = a.size();
        int m = b.size();

        int i = n - 1, j = m - 1;

        string ans;
        int carry = 0;

        while (i >= 0 && j >= 0)
        {
            if (a[i] == '0' && b[j] == '0')
            {
                if (carry == 0)
                {
                    ans.push_back('0');
                }
                else
                {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else if ((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0'))
            {
                if (carry == 0)
                {
                    ans.push_back('1');
                }

                else
                {
                    ans.push_back('0');
                    carry = 1;
                }
            }
            else if (a[i] == '1' && b[j] == '1')
            {
                if (carry == 0)
                {
                    ans.push_back('0');
                    carry = 1;
                }
                else
                {
                    ans.push_back('1');
                    carry = 1;
                }
            }

            i--;
            j--;
        }

        while (i >= 0)
        {
            if (a[i] == '0')
            {
                if (carry == 0)
                {
                    ans.push_back('0');
                }
                else
                {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else
            {
                if (carry == 0)
                {
                    ans.push_back('1');
                }
                else
                {
                    ans.push_back('0');
                    carry = 1;
                }
            }
            i--;
        }

        while (j >= 0)
        {

            if (b[j] == '0')
            {
                if (carry == 0)
                {
                    ans.push_back('0');
                }
                else
                {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else
            {
                if (carry == 0)
                {
                    ans.push_back('1');
                }
                else
                {
                    ans.push_back('0');
                    carry = 1;
                }
            }
            j--;
        }

        if (carry)
        {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};