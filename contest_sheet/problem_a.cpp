#include<iostream>
#include<deque>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
int main()
{
    short n,m,idx=0;
    float num,val=0;
    deque<pair<int,int>>numbers;
    cin>>n>>m;

  for (int i = 1; i <= n; i++) {
        cin >> num;
        
        int rounds = ceil(num / m);
        numbers.push_back({rounds, i});
    }

   auto element=max_element(numbers.begin(),numbers.end());

cout<<element->second;

    return 0;
}