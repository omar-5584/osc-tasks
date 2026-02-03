#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        short cnt = 0;
        for (short i = 0;i < nums.size();i++)
        {
            if (nums[i] > nums[(i + 1) % nums.size()])
            {
                cnt++;
            }
            if (cnt > 1)
            {
                return false;
            }
        }
        return true;

    }
};

