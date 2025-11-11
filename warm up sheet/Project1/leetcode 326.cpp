#include<iostream>
using namespace std;

class Solution {
public:

	bool  isInt(double num)
	{
		return (num == (long long)num) ? true : false;
	}

	bool  isPowerOfThree(long long n)
	{

		double res = 0;
		res = log10(n) / log10(3);
		return (n > 0 && isInt(res)) ? true : false;
	}

};
// int main()
// {
//     Solution s1;
// 	float num;
// 	cin >> num;
// 	isPowerOfThree(num);

// }