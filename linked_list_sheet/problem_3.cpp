
#include<iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


// Function to insert a node in the middle of the linked list.
class Solution {
  public:
    Node *insertInMiddle(Node *head, int x) {
        // Code Here
       int size=0;
       Node *temp=head;
       while(temp!=NULL)
       {
            size++;
            temp=temp->next;
        }
        temp=head;
        Node *newnode=new Node(x);
      if(size==0)
      {
        newnode->next=NULL;
        return newnode;
      }
    size = (size % 2 == 0) ? (size / 2) - 1 : size / 2;
    for(int i=0;i<size;i++)
    {
        temp=temp->next;
    }

newnode->next=temp->next;
temp->next=newnode;

return head;
       

        
    }
};