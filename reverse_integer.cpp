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

int reverse(int x)
{
    string s;
    stringstream ss;
    long long i = abs(x);

    ss << i;
	ss >> s;
    reverse(s.begin(), s.end());

	ss.clear();
    ss << s;
    ss >> i;

    if (((x >= 0) && i > (pow(2, 31) - 1)) || ((x < 0) && (i > pow(2, 31))))
    {
        return 0;
    }
    else
    {
        long long t = ((x >= 0) ? i : -i);
		if (t > pow(2, 31) - 1 || t < -pow(2, 31))
		{
			return 0;
		}
		else
		{
			return t;
		}
    }
}

int main()
{
    int input;
    //int i = pow(2, 31) - 1;
    //cout << i << endl;
    cin >> input;
    cout << reverse(input) << endl;

    return 0;
}
