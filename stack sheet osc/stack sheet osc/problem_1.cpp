#include<iostream>
#include<stack>
using namespace std;



class Solution {
private:
    stack<char> clearStr(string& s, char dilema = '#')
    {
        stack<char>st;
        for (auto element : s)
        {
           if (element != '#')
           {
            st.push(element);
           }
           else if (!st.empty() && element == '#')
           {
               st.pop();
           }
        }
        return st;
    }

public:
    bool backspaceCompare(string s, string t) {

        return clearStr(s) == clearStr(t);

    }
};