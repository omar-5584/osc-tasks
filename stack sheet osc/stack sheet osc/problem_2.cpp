#include<iostream>
#include<stack>
using namespace std;


class Solution {

private:
    stack <char> st;
   

    string s1 = "({[";
    string s2 = ")}]";

    int idx_open_br;
public:
    bool  isValid(string s) {
        if (s.size() & 1)
            return false;
        else
        {

            for (char ch : s)
            {
                   if(!st.empty()) idx_open_br = s1.find(st.top());
                if (s1.find(ch) != string::npos)
                {
                    st.push(ch);
                }
                else if (!st.empty() && s2.find(ch) ==idx_open_br)
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }


        }
        return true;

    }
};

int main()
{
    Solution s;
    cout << s.isValid("([])");



}