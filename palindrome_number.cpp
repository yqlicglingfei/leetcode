#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <cmath>
#include <sstream>
using namespace std;

int getn(int x)
{
    int i = 0;
    while (x != 0)
    {
        x /= 10;
        ++i;
    }
    return i - 1;
}

bool isPalindrome(int x)
{
	if ((x / 10) == 0)
	{
		return true;
	}
	else
	{
		int n = getn(x);
		long long nn = pow(10, n);

		int num = x / nn;

		int last = x % 10;
		int left = (x - last) / 10;
		int reverse = 0;
		do
		{
			reverse += last * nn;
			//cout << "reverse =" << reverse << endl;
			last = left % 10;
			//cout << "last =" << last << endl;
			left = (left - last) / 10; 
			//cout << "left =" << left << endl;
	
			--n;
			nn = pow(10, n);
		}while (left != 0);
	
		reverse += num;
		
		if (reverse == x)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
    int i;
    cout << "intput number" << endl;
    cin >> i;

    cout << isPalindrome(i) << endl;
}
