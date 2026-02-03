#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:

	int findMaxConsecutiveOnes(vector<int>& nums) {

		auto start = nums.begin();
		auto end = nums.end();
		int maxlen = 0;

		do {
			end = find(start, nums.end(), 0);
			maxlen = max(int(end - start), maxlen);
			if (end != nums.end())
			{
				start = end + 1;
			}


		} while (end < nums.end());
		return maxlen;

	}
};


