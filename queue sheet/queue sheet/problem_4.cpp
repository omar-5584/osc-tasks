
#include<iostream>
#include<queue>

using namespace std;

class Solution {

private:
    int cnt = 0;
    pair<int, int>pr;// index,numoftickets
    queue<pair<int, int>>tickets;

public:
    int timeRequiredToBuy(vector<int>& tck, int k) {

        for (int i = 0;i < tck.size();i++)
        {
            pr.first = i;
            pr.second = tck[i];
            tickets.push(pr);
        }



        while (!tickets.empty())
        {



            tickets.front().second--;
            auto temp = tickets.front();
            tickets.pop();
            cnt++;
            if (temp.second > 0)
            {
                tickets.push(temp);
            }
            else if (temp.first == k && temp.second == 0)
            {
                return cnt;
            }

        }
        return cnt;

    }
};