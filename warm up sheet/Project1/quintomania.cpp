#include<iostream>
#include<queue>
using namespace std;


void fillnums(deque<int>&nums,int size)
{
	int num;
	while (size--)
	{
		cin >> num;
		nums.push_back(num);
	}
}

bool IsPerfect(deque<int>& nums,int size)
{
	while (nums.size()>1)
	{
		if (abs(nums[0] - nums[1]) != 5 && abs(nums[0] - nums[1]) != 7)
		{

			return false;
		}
		else
		{
			nums.pop_front();
		}
	}
	return true;
}

int main()
{
	deque<int>nums;

	int q;
	cin >> q;
	short size;
	while (q--)
	{
		cin >> size;
		
		fillnums(nums,size);
	
		if (IsPerfect(nums,size))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		nums.clear();

	}

}