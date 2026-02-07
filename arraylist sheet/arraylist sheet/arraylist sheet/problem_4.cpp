#include<iostream>
#include<vector>

using namespace std;



   class Solution {
public:
   

	int missingNumber( vector<int>& nums) {
		for (int i = 0;i < nums.size() - 1;i++)
		{
			nums[i+1] += nums[i];
		}
		return (nums.size() * (nums.size() + 1) / 2) - (nums[nums.size() - 1]);
	}
};
