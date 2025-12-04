


class Solution {
private:
    stack<int>st;
public:
    queue<int> reverseFirstK(queue<int> q, int k) {

        if (k > q.size())
            return q;

        queue<int>q2;

        while (k--)
        {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty())
        {
            q2.push(st.top());
            st.pop();

        }
        while (!q.empty())
        {
            q2.push(q.front());
            q.pop();
        }
        return  q2;

    }
};