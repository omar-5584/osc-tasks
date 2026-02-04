#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;

     for (int line = 0; line < numRows; line++) {
                    vector<int> currentRow; 
            
            for (int cul = 0; cul <= line; cul++) {
                if (cul == 0 || cul == line) {
                    currentRow.push_back(1);
                } 
                else {
                   
                    int val = pascal[line - 1][cul - 1] + pascal[line - 1][cul];
                    currentRow.push_back(val);
                }
            }
            
            pascal.push_back(currentRow);
        }
return pascal;

    }
};

