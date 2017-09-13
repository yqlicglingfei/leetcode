#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    double result = 0.0;

    int size = nums1.size() + nums2.size();
    int size1 = nums1.size();
    int size2 = nums2.size();
    int i = 0;
    int i1 = 0;
    int i2 = 0;
    if (size % 2 != 0)
    {
        while (i < size / 2 + 1)
        {
            if (i1 < size1 && i2 < size2)
            {
                if (nums1[i1] < nums2[i2])
                {
                    result = nums1[i1];
                    i1 += 1;
                }
                else
                {
                    result = nums2[i2];
                    i2 += 1;
                }
            }
            else if (i1 >= size1 && i2 < size2)
            {
                result = nums2[i2];
                i2 += 1;
            }
            else
            {
                result = nums1[i1];
                i1 += 1;
            }
            ++i;
        }
    }
    else
    {
        int result1 = 0;
        int result2 = 0;
        while (i < size / 2 + 1)
        {
            if (i1 < size1 && i2 < size2)
            {
                if (nums1[i1] < nums2[i2])
                {
                    result = nums1[i1];
                    i1 += 1;
                }
                else
                {
                    result = nums2[i2];
                    i2 += 1;
                }
            }
            else if (i1 >= size1 && i2 < size2)
            {
                result = nums2[i2];
                i2 += 1;
            }
            else
            {
                result = nums1[i1];
                i1 += 1;
            }

            if (i == size / 2)
            {
                result1 = result;
            }
            if (i == size / 2 - 1)
            {
                result2 = result;
            }

            ++i;
        }
        result = (double)(result1 + result2) / 2;
    }

    return result;
}

int main()
{
    int a[] = {1,2};
    int b[] = {3,4};
    vector<int> n1(a, a+2);
    vector<int> n2(b, b+2);

    cout << findMedianSortedArrays(n1, n2) << endl;
    return 0;
}
