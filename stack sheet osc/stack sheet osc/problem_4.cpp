
#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int>mp;
    stack<pair<int, int>>st;
    pair<int, int>indv;
    vector<int>vc;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vc.resize(temperatures.size());
        for (int i = temperatures.size() - 1;i >= 0;i--)
        {

            while (!st.empty() && temperatures[i] >= st.top().first)
            {

                st.pop();
            }
            if (st.empty())
            {
                vc[i] = 0;

            }
            else if (temperatures[i] < st.top().first)
            {
                vc[i] = st.top().second - i;
            }
            indv.first = temperatures[i];
            indv.second = i;
            st.push(indv);


        }

        return vc;

    }
};