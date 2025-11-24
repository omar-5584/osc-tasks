#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    vector<int>vec;
    vector<int>pos;
    bool addneg;

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        for (int element : asteroids)
        {
            if (element > 0)
            {
                pos.push_back(element);

                continue;
            }
            else {
                addneg = true;
                while (!pos.empty() && addneg)
                {
                    if (abs(element) < pos.back())
                    {
                        addneg = false;

                    }
                    else if (abs(element) == pos.back())
                    {
                        pos.pop_back();
                        addneg = false;


                    }
                    else if (abs(element) > pos.back())
                    {
                        pos.pop_back();
                    }


                }
                if (addneg)
                {
                    vec.push_back(element);
                }

            }
        }

        reverse(pos.begin(), pos.end());
        while (!pos.empty())
        {
            vec.push_back(pos.back());
            pos.pop_back();
        }

        return vec;


    }
};
