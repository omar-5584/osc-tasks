

class Solution {

    int idxofstud = 0;
    queue<int> q;
    int i = 0;

public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for (int s : students) q.push(s);


        while (!q.empty() && idxofstud < q.size()) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                idxofstud = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                idxofstud++;
            }
        }

        return q.size();
    }
};