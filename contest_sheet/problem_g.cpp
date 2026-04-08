#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    
    int t;
    cin >> t;
    while (t--) {
        int unmatched_close = 0;
        stack<char> st;
        
        int n;
        string s;
        cin >> n >> s;


        for (char ch : s) {
            if (ch == '(') {
                
                st.push(ch);
            } else {
                    if (!st.empty()) {
                    st.pop();
                } else {
                    unmatched_close++;
                }
            }
        }
        cout << unmatched_close + st.size() << endl;
    }



    return 0;
}