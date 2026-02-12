#include<iostream>
#include<vector>
using namespace std;
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    vector<int> displayList(Node *head) {
        // code here
        vector<int>vec;
        while(head!=NULL)
        {
            vec.push_back(head->data);
            head=head->next;
        }
    }
};
