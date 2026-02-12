
#include<iostream>

using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    bool areIdentical(Node *head1, Node *head2) {
        // code here
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->data!=head2->data)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
            
        }
        if(head1==NULL && head2==NULL)
        return true;
        else 
        return false;
    }
};