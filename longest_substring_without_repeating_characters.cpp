#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
using namespace std;

int maxvct(vector<int> vct)
{
    if (vct.size() == 0)
    {
        return 0;
    }
    else if (vct.size() == 1)
    {
        return vct.front();
    }
    else
    {
        vector<int>::iterator it = vct.begin();
        vector<int>::iterator it1 = it + 1;
        int maxint = max(*it, *it1);
        while (it1 != vct.end())
        {
            maxint = max(maxint, *it1);
            ++it1;
        }

        return maxint;
    }
}

int lengthOfLongestSubstring(string s)
{
    string stmp;
    vector<int> vct;

    while (!s.empty())
    {
        for (auto c : s)
        {
            size_t pos = stmp.find(c);
            if (string::npos == pos)
            {
                stmp += c;
            }
            else
            {
                s = s.substr(pos + 1);
                vct.push_back(stmp.size());
                stmp.clear();
                break;
            }
        }
    }

    int max = maxvct(vct);
    return max;
}

int main()
{
    string s;
    cout << "cin s" << endl;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
