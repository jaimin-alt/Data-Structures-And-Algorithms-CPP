#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maskPII(string s)
    {
        int n = s.size();
        int i = 0;
        bool isEmail = 0;
        string ans;

        if (s.find('.') != string::npos)
        {
            isEmail = true;
        }

        if (isEmail)
        {
            int pos = s.find('@') - 1;
            if (s[0] < 97)
            {
                ans.push_back(char(s[0] + 32));
            }
            else
            {
                ans.push_back(s[0]);
            }

            ans += "*****";

            if (s[pos] < 97)
            {
                ans += char(s[pos] + 32);
            }
            else
            {
                ans += s[pos];
            }

            ans += '@';

            int i = pos + 2;

            while (i < n)
            {
                if (s[i] == '.')
                {
                    ans += '.';
                    i++;
                    continue;
                }
                if (s[i] < 97)
                {
                    ans += char(s[i] + 32);
                }
                else
                {
                    ans += s[i];
                }
                i++;
            }
        }
        else
        {

            int i = 0;
            string digits;

            while (i < n)
            {
                if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ' ')
                {
                    i++;
                    continue;
                }
                else
                {
                    digits += s[i];
                    i++;
                }
            }

            int contry_digits = digits.size() - 10;

            if (contry_digits == 0)
            {
                ans += "***-***-";
                ans += digits.substr(6);
            }
            else if (contry_digits == 1)
            {
                ans += "+*-***-***-";
                ans += digits.substr(7);
            }
            else if (contry_digits == 2)
            {
                ans += "+**-***-***-";
                ans += digits.substr(8);
            }
            else
            {
                ans += "+***-***-***-";
                ans += digits.substr(9);
            }
        }

        return ans;
    }
};