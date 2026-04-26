#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main()
{

int epoints=0,gpoints=0,n;
deque<int>nums;
cin>>n;
char station;
int choice;
int val;
while(n--)
{
    cin>>choice;
    cin>>station;
    if(choice==1)
    {
        cin>>val;
        if(station=='G')
        {
            nums.push_front(val);
        }
        else
        {
            nums.push_back(val);
        }
    }
    else
    {

         if(station=='G')
        {
            nums.pop_front();
        }
        else
        {
            nums.pop_back();
        }

    }
    if(!nums.empty()){
if (nums.size()==1)
{
    gpoints++;
    epoints++;
}
else if(nums.back()>nums.front())
{
epoints++;
}
else{
    gpoints++;
}

}
if(epoints>gpoints)
{
    cout<<"Elshohada";
}
else if(gpoints>epoints)
{
    cout<<"Gamal";
}
else{
    cout<<"Draw";
}}
    return 0;
}