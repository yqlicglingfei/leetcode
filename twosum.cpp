#include<functional>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    //remove_if(nums.begin(), nums.end(), bind1st(greater<int>(), target));
    vector<int>::iterator it = nums.begin();
    while (it != nums.end())
    {
        for (vector<int>::iterator it_next = it + 1; it_next!= nums.end(); ++it_next)
        {
            if (*it + *it_next == target)
            {
                result.push_back(it - nums.begin());
                result.push_back(it_next - nums.begin());
            }
        }
        ++it;
    }
    return result;
}

int main()
{
    int a[] = {-3,0,3,90};
    vector<int>vct(&a[0], &a[4]);
    vector<int> result = twoSum(vct, 0);
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
