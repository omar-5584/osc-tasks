class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node*  target=head;
        Node* temp=head ;
        long long cnt=0;
        k--;
        while(k-- && temp!=NULL)
        {
            temp=temp->next;
            cnt++;
            if(temp==NULL)
            {return -1;}
        }
        
        while(temp->next!=NULL )
        {
           
            
             target=target->next;
              temp=temp->next;
            cnt++;
            
            if(k>cnt)
             {
                return -1;
                
            }
        }
     
     return target->data;   
    }
};