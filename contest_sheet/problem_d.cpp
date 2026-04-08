#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<long long>vec;
long long size,q;
cin>>size>>q;

while(size--)
{
    int num;
    cin>>num;
    vec.push_back(num);
}
while(q--)
{
int query=0;
cin>>query;
if(query==1)
{
int j,i;
cin>>j>>i;
vec[i-1]+=vec[j-1];

}
else if(query==2)
{
long long v;
cin>>v;
vec.push_back(v);

}
else if(query==3)
{

    vec.pop_back();
}

}

cout << *max_element(vec.begin(),vec.end());

    return 0;
}